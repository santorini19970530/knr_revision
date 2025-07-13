/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.14: Conditional expressions */

#include <stdio.h>

int main() {
    int a = 10, b = 20;
    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;
    
    printf("a = %d, b = %d\n", a, b);
    printf("max = %d\n", max);
    printf("min = %d\n", min);
    
    /* Nested conditional */
    int x = 5, y = 10, z = 15;
    int largest = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
    printf("largest of %d, %d, %d is %d\n", x, y, z, largest);
    
    return 0;
} 
