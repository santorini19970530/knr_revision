/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 8.7 - Memory allocator with coalescing
 * 
 * malloc accepts a size request without checking its
 * reasonableness; free believes that the block it is
 * asked to free contains a valid size field. Improve
 * these routines so they take more pains with error
 * checking.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef long Align;

union header {
    struct {
        union header *ptr;
        unsigned size;
    } s;
    Align x;
};

typedef union header Header;

static Header base;
static Header *freep = NULL;

void *malloc_coalesce(unsigned nbytes);
void free_coalesce(void *ap);
Header *morecore(unsigned nu);

int main() {
    char *p1, *p2, *p3, *p4;
    
    printf("Testing coalescing memory allocator:\n\n");
    
    /* Allocate some memory blocks */
    p1 = malloc_coalesce(100);
    p2 = malloc_coalesce(200);
    p3 = malloc_coalesce(50);
    
    printf("Allocated: p1=%p, p2=%p, p3=%p\n", p1, p2, p3);
    
    /* Free adjacent blocks to test coalescing */
    free_coalesce(p1);
    free_coalesce(p2);
    printf("Freed p1 and p2 (should coalesce)\n");
    
    /* Allocate new block - should use coalesced space */
    p4 = malloc_coalesce(250);
    printf("Allocated p4=%p (should fit in coalesced space)\n", p4);
    
    /* Free remaining blocks */
    free_coalesce(p3);
    free_coalesce(p4);
    printf("Freed all blocks\n");
    
    return 0;
}

void *malloc_coalesce(unsigned nbytes) {
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;
    
    /* Error checking */
    if (nbytes == 0) {
        printf("malloc: invalid size request (0)\n");
        return NULL;
    }
    
    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
    if ((prevp = freep) == NULL) {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) {
            if (p->s.size == nunits)
                prevp->s.ptr = p->s.ptr;
            else {
                p->s.size -= nunits;
                p += p->s.size;
                p->s.size = nunits;
            }
            freep = prevp;
            return (void *)(p + 1);
        }
        if (p == freep)
            if ((p = morecore(nunits)) == NULL)
                return NULL;
    }
}

#define NALLOC 1024

Header *morecore(unsigned nu) {
    char *cp, *sbrk(int);
    Header *up;
    
    if (nu < NALLOC)
        nu = NALLOC;
    cp = sbrk(nu * sizeof(Header));
    if (cp == (char *) -1)
        return NULL;
    up = (Header *) cp;
    up->s.size = nu;
    free_coalesce((void *)(up + 1));
    return freep;
}

void free_coalesce(void *ap) {
    Header *bp, *p;
    
    /* Error checking */
    if (ap == NULL) {
        printf("free: null pointer\n");
        return;
    }
    
    bp = (Header *)ap - 1;
    
    /* Check for valid size field */
    if (bp->s.size == 0) {
        printf("free: invalid size field\n");
        return;
    }
    
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;
    
    /* Coalesce with upper neighbor */
    if (bp + bp->s.size == p->s.ptr) {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else
        bp->s.ptr = p->s.ptr;
    
    /* Coalesce with lower neighbor */
    if (p + p->s.size == bp) {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else
        p->s.ptr = bp;
    freep = p;
} 