/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include <stdio.h>

/* Exercise 2-8: Write a function rightrot(x,n) that returns the value of the integer x 
   rotated to the right by n bit positions */

unsigned rightrot(unsigned x, int n);

int main() {
    unsigned x = 0x12345678;
    int n = 4;
    
    printf("Original x: 0x%X\n", x);
    printf("Rotate right by %d bits\n", n);
    
    unsigned result = rightrot(x, n);
    printf("Result: 0x%X\n", result);
    
    return 0;
}

/* rightrot: rotate x to the right by n positions */
unsigned rightrot(unsigned x, int n) {
    int wordlength(void);
    int rbit;
    
    while (n-- > 0) {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;
        x = x | rbit;
    }
    return x;
}

/* wordlength: computes word length of the machine */
int wordlength(void) {
    int i;
    unsigned v = (unsigned) ~0;
    
    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
} 