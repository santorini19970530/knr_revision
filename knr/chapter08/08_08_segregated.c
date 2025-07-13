/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 8.8 - Memory allocator with segregated lists
 * 
 * Write a routine bfree(p,n) that will free an arbitrary
 * block p of n characters into the free list maintained by
 * malloc and free. Using bfree, a user can add a static
 * or external array to the free list at any time.
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

void *malloc_segregated(unsigned nbytes);
void free_segregated(void *ap);
void bfree(void *p, unsigned n);
Header *morecore(unsigned nu);

int main() {
    char *p1, *p2;
    char static_array[100];
    
    printf("Testing segregated memory allocator:\n\n");
    
    /* Allocate some memory */
    p1 = malloc_segregated(100);
    p2 = malloc_segregated(200);
    
    printf("Allocated: p1=%p, p2=%p\n", p1, p2);
    
    /* Add static array to free list */
    bfree(static_array, sizeof(static_array));
    printf("Added static array to free list\n");
    
    /* Free allocated memory */
    free_segregated(p1);
    free_segregated(p2);
    printf("Freed allocated memory\n");
    
    return 0;
}

void *malloc_segregated(unsigned nbytes) {
    Header *p, *prevp;
    Header *morecore(unsigned);
    unsigned nunits;
    
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

void bfree(void *p, unsigned n) {
    Header *bp;
    
    if (n < sizeof(Header)) {
        printf("bfree: block too small\n");
        return;
    }
    
    bp = (Header *)p;
    bp->s.size = n / sizeof(Header);
    free_segregated((void *)(bp + 1));
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
    free_segregated((void *)(up + 1));
    return freep;
}

void free_segregated(void *ap) {
    Header *bp, *p;
    
    if (ap == NULL)
        return;
    
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