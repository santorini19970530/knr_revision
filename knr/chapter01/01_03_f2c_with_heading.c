/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* exercise 01-03 - print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300
   floating-point version, with heading   */

#include<stdio.h>

int main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;  /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;  /* step size */

    fahr = lower;
    printf("%3s %7s\n", "Fah", "Cel");
    printf("--- -------\n");
    while(fahr <= upper){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
