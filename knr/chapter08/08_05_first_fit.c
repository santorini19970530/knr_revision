/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 8.5 - Memory allocator with first-fit
 * 
 * Modify the memory allocator to use a first-fit strategy
 * instead of best-fit. How much faster is it?
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

void *malloc_first_fit(unsigned nbytes);
void free(void *ap);
Header *morecore(unsigned nu);

int main() {
    char *p1, *p2, *p3, *p4;
    
    printf("Testing first-fit memory allocator:\n\n");
    
    /* Allocate some memory blocks */
    p1 = malloc_first_fit(100);
    p2 = malloc_first_fit(200);
    p3 = malloc_first_fit(50);
    
    printf("Allocated: p1=%p, p2=%p, p3=%p\n", p1, p2, p3);
    
    /* Free middle block */
    free(p2);
    printf("Freed p2\n");
    
    /* Allocate new block - should use first available space */
    p4 = malloc_first_fit(150);
    printf("Allocated p4=%p (should fit in freed space)\n", p4);
    
    /* Free all blocks */
    free(p1);
    free(p3);
    free(p4);
    printf("Freed all blocks\n");
    
    return 0;
}

void *malloc_first_fit(unsigned nbytes) {
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;
    
    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
    if ((prevp = freep) == NULL) {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    
    /* First-fit: use first block that's big enough */
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
    free((void *)(up + 1));
    return freep;
}

void free(void *ap) {
    Header *bp, *p;
    
    bp = (Header *)ap - 1;
    for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
        if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
            break;
    
    if (bp + bp->s.size == p->s.ptr) {
        bp->s.size += p->s.ptr->s.size;
        bp->s.ptr = p->s.ptr->s.ptr;
    } else
        bp->s.ptr = p->s.ptr;
    if (p + p->s.size == bp) {
        p->s.size += bp->s.size;
        p->s.ptr = bp->s.ptr;
    } else
        p->s.ptr = bp;
    freep = p;
} 