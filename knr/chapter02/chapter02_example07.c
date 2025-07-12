/* Chapter 2 Example 7: Conditional Expressions */

#include <stdio.h>

int main() {
    int a = 10, b = 20;
    int z;
    
    printf("a = %d, b = %d\n", a, b);
    
    /* Conditional expression to find maximum */
    z = (a > b) ? a : b;
    printf("z = (a > b) ? a : b: z = %d (max of a and b)\n", z);
    
    /* Conditional expression to find minimum */
    z = (a < b) ? a : b;
    printf("z = (a < b) ? a : b: z = %d (min of a and b)\n", z);
    
    /* Nested conditional expression */
    int c = 15;
    printf("c = %d\n", c);
    z = (a > b) ? a : (b > c) ? b : c;
    printf("z = (a > b) ? a : (b > c) ? b : c: z = %d (max of a, b, c)\n", z);
    
    /* Conditional expression with different types */
    char result = (a > 5) ? 'Y' : 'N';
    printf("result = (a > 5) ? 'Y' : 'N': result = %c\n", result);
    
    /* Conditional expression in printf */
    printf("a is %s\n", (a > 0) ? "positive" : "non-positive");
    printf("b is %s\n", (b % 2 == 0) ? "even" : "odd");
    
    return 0;
} 