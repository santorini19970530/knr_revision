/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* example 01-05 - print Fahrenheit-Celsius table (reversed order) */

#include<stdio.h>

int main(){
    int fahr;

    for(fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * fahr - 32.0);

    return 0;
}
