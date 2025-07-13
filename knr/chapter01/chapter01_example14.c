/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include <stdio.h>

/* Section 1.8 - Arguments: Call by Value */

/* This function demonstrates call by value - it receives a COPY of the argument */
void increment_by_value(int x) {
    x = x + 1;
    printf("Inside increment_by_value: x = %d\n", x);
}

/* This function demonstrates call by reference using pointers */
void increment_by_reference(int *x) {
    *x = *x + 1;
    printf("Inside increment_by_reference: *x = %d\n", *x);
}

int main() {
    int a = 5;
    
    printf("Before function calls: a = %d\n", a);
    
    /* Call by value - a is not changed */
    increment_by_value(a);
    printf("After increment_by_value: a = %d\n", a);
    
    /* Call by reference - a IS changed */
    increment_by_reference(&a);
    printf("After increment_by_reference: a = %d\n", a);
    
    return 0;
} 