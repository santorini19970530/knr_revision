/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.13: bitcount function implementation */

#include <stdio.h>

/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {
    int b;
    
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}

int main() {
    unsigned numbers[] = {0, 1, 2, 3, 7, 15, 255};
    
    printf("Number\tBinary\t\t1-bits\n");
    printf("------\t-------\t\t------\n");
    
    for (int i = 0; i < 7; i++) {
        unsigned num = numbers[i];
        int count = bitcount(num);
        
        printf("%u\t", num);
        for (int j = 7; j >= 0; j--) {
            printf("%d", (num >> j) & 1);
        }
        printf("\t%d\n", count);
    }
    
    return 0;
} 
