/* Chapter 2 Example 3: Function Declaration */

#include <stdio.h>

/* Function declaration example */
int power(int m, int n);

int main() {
    int base = 2, exponent = 3;
    int result = power(base, exponent);
    
    printf("%d raised to the power of %d = %d\n", base, exponent, result);
    
    return 0;
}

/* Function definition */
int power(int m, int n) {
    int i, p;
    
    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * m;
    return p;
} 