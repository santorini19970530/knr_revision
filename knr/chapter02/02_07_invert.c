/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Exercise 2-7: Write a function invert(x,p,n) that returns x with the n bits that begin 
   at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
    unsigned x = 0x12345678;
    int p = 8;
    int n = 4;
    
    printf("Original x: 0x%X\n", x);
    printf("Position p: %d, bits n: %d\n", p, n);
    
    unsigned result = invert(x, p, n);
    printf("Result: 0x%X\n", result);
    
    return 0;
}

/* invert: invert n bits of x starting at position p */
unsigned invert(unsigned x, int p, int n) {
    unsigned mask = ~(~0 << n);  /* n rightmost 1's */
    unsigned bits_to_invert = (x >> (p + 1 - n)) & mask;
    
    /* Clear the n bits in x starting at position p */
    unsigned clear_mask = ~(mask << (p + 1 - n));
    x = x & clear_mask;
    
    /* Invert the bits and set them back */
    unsigned inverted_bits = ~bits_to_invert & mask;
    x = x | (inverted_bits << (p + 1 - n));
    
    return x;
} 
