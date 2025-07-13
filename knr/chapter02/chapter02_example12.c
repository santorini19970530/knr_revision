/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.12: getbits function implementation */

#include <stdio.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

int main() {
    unsigned x = 0xF0F0;  /* 1111000011110000 in binary */
    
    printf("x = 0x%X (binary: ", x);
    for (int i = 15; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf(")\n");
    
    printf("getbits(x, 11, 4) = 0x%X\n", getbits(x, 11, 4));
    printf("getbits(x, 7, 4) = 0x%X\n", getbits(x, 7, 4));
    printf("getbits(x, 3, 4) = 0x%X\n", getbits(x, 3, 4));
    
    return 0;
} 
