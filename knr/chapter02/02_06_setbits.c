#include <stdio.h>

/* Exercise 2-6: Write a function setbits(x,p,n,y) that returns x with the n bits that begin 
   at position p set to the rightmost n bits of y, leaving the other bits unchanged */

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    unsigned x = 0x12345678;
    unsigned y = 0xABCD;
    int p = 8;
    int n = 4;
    
    printf("Original x: 0x%X\n", x);
    printf("Original y: 0x%X\n", y);
    printf("Position p: %d, bits n: %d\n", p, n);
    
    unsigned result = setbits(x, p, n, y);
    printf("Result: 0x%X\n", result);
    
    return 0;
}

/* setbits: set n bits of x starting at position p to rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = ~(~0 << n);  /* n rightmost 1's */
    unsigned rightmost_n = y & mask;  /* rightmost n bits of y */
    
    /* Clear the n bits in x starting at position p */
    unsigned clear_mask = ~(mask << (p + 1 - n));
    x = x & clear_mask;
    
    /* Set the n bits to rightmost_n */
    x = x | (rightmost_n << (p + 1 - n));
    
    return x;
} 