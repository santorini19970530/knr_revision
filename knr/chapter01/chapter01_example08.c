/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* example 01-08 - copy input to output : 2nd version */

#include<stdio.h>

int main(){
    int c;

    while((c = getchar()) != EOF){
        putchar(c);

    return 0;
}
