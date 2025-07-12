#include<stdio.h>

/* print Celsius-Fahrenheit table
   for celsius = 0, 20, ..., 300
   floating-point version, with heading   */

int main(){
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;  /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;  /* step size */

    celsius = lower;
    printf("%7s %3s\n", "Cal", "Fah");
    printf("------- ---\n");
    while(celsius <= upper){
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%6.1f %3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
