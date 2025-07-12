/* Chapter 2 Example 4: Increment and Decrement Operators */

#include <stdio.h>

int main() {
    int n = 5;
    int x;
    
    printf("Initial value of n: %d\n", n);
    
    /* Postfix increment */
    x = n++;
    printf("x = n++: x = %d, n = %d\n", x, n);
    
    /* Prefix increment */
    x = ++n;
    printf("x = ++n: x = %d, n = %d\n", x, n);
    
    /* Postfix decrement */
    x = n--;
    printf("x = n--: x = %d, n = %d\n", x, n);
    
    /* Prefix decrement */
    x = --n;
    printf("x = --n: x = %d, n = %d\n", x, n);
    
    return 0;
} 