/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.4: Function declaration */

#include <stdio.h>

int power(int m, int n);

int main() {
    printf("2^3 = %d\n", power(2, 3));

    return 0;
}

int power(int m, int n) {
    int p = 1;

    for (int i = 0; i < n; i++)
        p *= m;

    return p;
} 
