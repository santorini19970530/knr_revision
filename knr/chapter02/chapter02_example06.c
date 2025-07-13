/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.6: Bitwise operators */

#include <stdio.h>
int main() {
    unsigned n = 0xF0F0;
    printf("n = 0x%X\n", n);
    printf("n & 0x0F0F = 0x%X\n", n & 0x0F0F);
    printf("n | 0x0F0F = 0x%X\n", n | 0x0F0F);
    printf("n ^ 0xFFFF = 0x%X\n", n ^ 0xFFFF);
    printf("~n = 0x%X\n", ~n);
    return 0;
} 
