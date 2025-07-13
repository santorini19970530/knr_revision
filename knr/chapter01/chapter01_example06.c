/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include<stdio.h>

// symbolic constants or symbolic names

#define LOWER 0 /* lower limit of temperature table */
#define UPPER 300    /* upper limit */
#define STEP 20  /* step size */

/* print Fahrenheit-Celsius table */

int main(){
    int fahr;

    for(fahr = LOWER; fahr <= UPPER; fahr = fahr * STEP)
        printf("%3d %6.1f\n", fahr, 5.0  / 9.0 * (fahr - 32));

    return 0;
}
