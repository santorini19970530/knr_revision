/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include <stdio.h>

/* Exercise 2-9: In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. 
   Explain why. Use this observation to write a faster version of bitcount */

int bitcount(unsigned x);
int bitcount_fast(unsigned x);

int main() {
    unsigned x = 0x12345678;
    
    printf("Original x: 0x%X\n", x);
    printf("Bit count (original): %d\n", bitcount(x));
    printf("Bit count (fast): %d\n", bitcount_fast(x));
    
    return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
    int b;
    
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

/* bitcount_fast: count 1 bits in x using x &= (x-1) */
int bitcount_fast(unsigned x) {
    int b;
    
    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;
} 