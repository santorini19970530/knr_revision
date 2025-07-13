/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* example 01-09 - count characters in input; 1st version */

#include <stdio.h>

int main() {
    long nc;
    
    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);
    
    return 0;
} 
