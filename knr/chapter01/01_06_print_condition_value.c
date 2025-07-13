/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include<stdio.h>

/* copy input to output : print true or false value */

int main(){
    int c, value;

    while((value = (c = getchar()) != EOF)){
        printf("%d\n", value);

    return 0;
}
