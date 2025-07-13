/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* exercise 01-06 - copy input to output : print true or false value */

#include<stdio.h>

int main(){
    int c, value;

    while((value = (c = getchar()) != EOF)){
        printf("%d\n", value);

    return 0;
}
