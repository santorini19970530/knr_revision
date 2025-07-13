/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 8.6 - Memory allocator with boundary tags
 * 
 * The standard library function calloc(n,size) returns a
 * pointer to n objects of size size, with the storage
 * initialized to zero. Write calloc, by calling malloc
 * or by modifying it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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

void *malloc_boundary(unsigned nbytes);
void *calloc_boundary(unsigned n, unsigned size);
void free(void *ap);
Header *morecore(unsigned nu);

int main() {
    int *p1, *p2;
    char *p3;
    
    printf("Testing boundary-tagged memory allocator:\n\n");
    
    /* Test calloc */
    p1 = calloc_boundary(5, sizeof(int));
    p2 = calloc_boundary(10, sizeof(int));
    p3 = calloc_boundary(20, sizeof(char));
    
    printf("Allocated: p1=%p, p2=%p, p3=%p\n", p1, p2, p3);
    
    /* Verify initialization to zero */
    printf("p1[0] = %d (should be 0)\n", p1[0]);
    printf("p2[0] = %d (should be 0)\n", p2[0]);
    printf("p3[0] = %d (should be 0)\n", p3[0]);
    
    /* Free blocks */
    free(p1);
    free(p2);
    free(p3);
    printf("Freed all blocks\n");
    
    return 0;
}

void *malloc_boundary(unsigned nbytes) {
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

void *calloc_boundary(unsigned n, unsigned size) {
    void *ptr;
    unsigned total_size;
    
    total_size = n * size;
    ptr = malloc_boundary(total_size);
    
    if (ptr != NULL) {
        /* Initialize to zero */
        memset(ptr, 0, total_size);
    }
    
    return ptr;
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