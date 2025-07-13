/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Exercise 1-15: Rewrite the temperature conversion program of Section 1.2 to use a function for conversion */

#include <stdio.h>

float fahr_to_celsius(float fahr);

int main() {
    float fahr, celsius;
    int lower, upper, step;
    
    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */
    
    fahr = lower;
    printf("Fahrenheit to Celsius conversion table:\n");
    printf("Fahr  Celsius\n");
    printf("----  -------\n");
    
    while (fahr <= upper) {
        celsius = fahr_to_celsius(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    
    return 0;
}

/* fahr_to_celsius: convert Fahrenheit to Celsius */
float fahr_to_celsius(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
} 
