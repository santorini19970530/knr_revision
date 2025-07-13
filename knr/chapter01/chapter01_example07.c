/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* example 01-07 - copy input to output : 1st version */

#include<stdio.h>

int main(){
    int c;

    c = getchar();
    while(c != EOF){
        putchar(c);
        c = getchar();
    }

    return 0;
}
