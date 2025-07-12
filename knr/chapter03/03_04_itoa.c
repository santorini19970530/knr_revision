/* Exercise 3.4 - itoa function */

#include <stdio.h>
#include <string.h>

/* In a two's complement number representation, our version of itoa does not
   handle the largest negative number, that is, the value of n equal to
   -(2^(wordsize-1)). Explain why not. Modify it to print that value
   correctly, regardless of the machine on which it runs. */

void reverse(char s[]) {
    int i, j, c;
    
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/* Original itoa - has problem with largest negative number */
void itoa_original(int n, char s[]) {
    int i, sign;
    
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {      /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* Fixed itoa - handles largest negative number */
void itoa(int n, char s[]) {
    int i, sign;
    
    sign = n;
    i = 0;
    do {      /* generate digits in reverse order */
        s[i++] = (n % 10 < 0 ? -(n % 10) : n % 10) + '0';   /* get next digit */
    } while ((n /= 10) != 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];
    int test_cases[] = {123, -123, 0, -2147483648, 2147483647};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("Testing itoa functions:\n");
    for (int i = 0; i < num_tests; i++) {
        int n = test_cases[i];
        
        itoa_original(n, s);
        printf("Original itoa(%d) = %s\n", n, s);
        
        itoa(n, s);
        printf("Fixed itoa(%d) = %s\n", n, s);
        printf("\n");
    }
    
    return 0;
} 