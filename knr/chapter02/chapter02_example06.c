/* Chapter 2 Example 6: Assignment Operators */

#include <stdio.h>

int main() {
    int i = 10;
    int x = 5;
    int y = 3;
    
    printf("Initial values: i = %d, x = %d, y = %d\n", i, x, y);
    
    /* Add and assign */
    i += 2;
    printf("i += 2: i = %d\n", i);
    
    /* Multiply and assign with complex expression */
    x *= y + 1;
    printf("x *= y + 1: x = %d (same as x = x * (y + 1))\n", x);
    
    /* Subtract and assign */
    i -= 3;
    printf("i -= 3: i = %d\n", i);
    
    /* Divide and assign */
    x /= 2;
    printf("x /= 2: x = %d\n", x);
    
    /* Modulo and assign */
    i %= 4;
    printf("i %%= 4: i = %d\n", i);
    
    /* Left shift and assign */
    y <<= 2;
    printf("y <<= 2: y = %d\n", y);
    
    /* Right shift and assign */
    y >>= 1;
    printf("y >>= 1: y = %d\n", y);
    
    /* Bitwise AND and assign */
    x &= 3;
    printf("x &= 3: x = %d\n", x);
    
    /* Bitwise OR and assign */
    y |= 1;
    printf("y |= 1: y = %d\n", y);
    
    /* Bitwise XOR and assign */
    i ^= 2;
    printf("i ^= 2: i = %d\n", i);
    
    return 0;
} 