/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 4.14 - Swap macro
 * 
 * Define a macro swap(t,x,y) that interchanges two arguments
 * of type t. (Block structure will help.)
 */

#include <stdio.h>

#define swap(t, x, y) { t temp = x; x = y; y = temp; }

int main() {
    /* Test with integers */
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(int, a, b);
    printf("After swap: a = %d, b = %d\n\n", a, b);
    
    /* Test with doubles */
    double x = 3.14, y = 2.718;
    printf("Before swap: x = %f, y = %f\n", x, y);
    swap(double, x, y);
    printf("After swap: x = %f, y = %f\n\n", x, y);
    
    /* Test with characters */
    char c1 = 'A', c2 = 'Z';
    printf("Before swap: c1 = %c, c2 = %c\n", c1, c2);
    swap(char, c1, c2);
    printf("After swap: c1 = %c, c2 = %c\n\n", c1, c2);
    
    /* Test with pointers */
    char *str1 = "hello";
    char *str2 = "world";
    printf("Before swap: str1 = %s, str2 = %s\n", str1, str2);
    swap(char*, str1, str2);
    printf("After swap: str1 = %s, str2 = %s\n", str1, str2);
    
    return 0;
} 