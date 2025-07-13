/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* example 01-11 - count lines in input */

#include <stdio.h>

int main() {
    int c, nl;
    
    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%d\n", nl);
    
    return 0;
} 
