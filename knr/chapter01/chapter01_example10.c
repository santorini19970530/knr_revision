/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* example 01-10 - count characters in input; 2nd version */

#include <stdio.h>

int main() {
    double nc;

    for(nc = 0; getchar() != EOF ; ++nc)
        ;

    printf("%.0f\n", nc);
    
    return 0;
} 
