/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Chapter 2 Example 2: Variable Declarations */

#include <stdio.h>

int main() {
    /* Variable declarations example */
    int lower, upper, step;
    char c, line[1000];
    
    /* Initialize variables */
    lower = 0;
    upper = 100;
    step = 10;
    c = 'A';
    
    printf("lower = %d, upper = %d, step = %d\n", lower, upper, step);
    printf("c = %c\n", c);
    printf("line array declared with size 1000\n");
    
    return 0;
} 