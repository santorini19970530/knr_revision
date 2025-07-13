/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 8.4 - Memory allocator with best-fit */

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

void *malloc(unsigned nbytes);
void free(void *ap);
Header *morecore(unsigned nu);

void *malloc(unsigned nbytes) {
    Header *p, *prevp, *bestp, *prevbestp;
    unsigned nunits, bestsize;
    
    nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
    if ((prevp = freep) == NULL) {
        base.s.ptr = freep = prevp = &base;
        base.s.size = 0;
    }
    
    /* Find best fit */
    bestp = NULL;
    prevbestp = NULL;
    bestsize = 0xFFFFFFFF; /* Large number */
    
    for (p = prevp->s.ptr; ; prevp = p, p = p->s.ptr) {
        if (p->s.size >= nunits) {
            if (p->s.size == nunits) {
                /* Exact fit */
                prevp->s.ptr = p->s.ptr;
                freep = prevp;
                return (void *)(p + 1);
            }
            if (p->s.size < bestsize) {
                bestsize = p->s.size;
                bestp = p;
                prevbestp = prevp;
            }
        }
        if (p == freep) {
            if (bestp != NULL) {
                /* Use best fit */
                prevbestp->s.ptr = bestp->s.ptr;
                bestp->s.size -= nunits;
                bestp += bestp->s.size;
                bestp->s.size = nunits;
                freep = prevbestp;
                return (void *)(bestp + 1);
            }
            if ((p = morecore(nunits)) == NULL)
                return NULL;
        }
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

int main() {
    char *p1, *p2, *p3, *p4;
    
    printf("Testing best-fit memory allocator:\n");
    
    p1 = malloc(100);
    printf("Allocated 100 bytes at %p\n", p1);
    
    p2 = malloc(200);
    printf("Allocated 200 bytes at %p\n", p2);
    
    p3 = malloc(50);
    printf("Allocated 50 bytes at %p\n", p3);
    
    free(p2);
    printf("Freed 200 bytes at %p\n", p2);
    
    p4 = malloc(75);
    printf("Allocated 75 bytes at %p\n", p4);
    
    return 0;
} 