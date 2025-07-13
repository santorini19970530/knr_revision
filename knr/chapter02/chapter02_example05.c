/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Chapter 2 Example 5: Bitwise Operators */

#include <stdio.h>

int main() {
    unsigned int n = 255;  /* 11111111 in binary */
    unsigned int x = 15;   /* 00001111 in binary */
    unsigned int SET_ON = 0x80;  /* 10000000 in binary */
    
    printf("n = %u (binary: 11111111)\n", n);
    printf("x = %u (binary: 00001111)\n", x);
    printf("SET_ON = %u (binary: 10000000)\n", SET_ON);
    
    /* Turn off all bits except the low-order 7 */
    n = n & 0177;  /* 0177 is octal for 127 (binary: 01111111) */
    printf("n & 0177 = %u (binary: 01111111)\n", n);
    
    /* Turn on the bits in SET_ON */
    x = x | SET_ON;
    printf("x | SET_ON = %u (binary: 10001111)\n", x);
    
    /* Bitwise XOR */
    printf("n ^ x = %u\n", n ^ x);
    
    /* Left shift */
    printf("n << 1 = %u\n", n << 1);
    
    /* Right shift */
    printf("x >> 1 = %u\n", x >> 1);
    
    /* Bitwise NOT */
    printf("~n = %u\n", ~n);
    
    return 0;
} 