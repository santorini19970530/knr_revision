/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.5: Increment and decrement operators */

#include <stdio.h>

int main() {
    int n = 5, x;
    x = n++;
    printf("x = %d, n = %d (after x = n++)\n", x, n);
    n = 5;
    x = ++n;
    printf("x = %d, n = %d (after x = ++n)\n", x, n);
    return 0;
} 
