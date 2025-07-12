/* Exercise 3.5 - itob function */

#include <stdio.h>
#include <string.h>

/* Write the function itob(n,s,b) that converts the integer n into a base b
   character representation in the string s. In particular, itob(n,s,16)
   formats s as a hexadecimal integer in s. */

void reverse(char s[]) {
    int i, j, c;
    
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itob(int n, char s[], int b) {
    int i, sign, digit;
    
    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {      /* generate digits in reverse order */
        digit = n % b;
        if (digit < 10)
            s[i++] = digit + '0';
        else
            s[i++] = digit - 10 + 'a';
    } while ((n /= b) > 0);     /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {
    char s[100];
    int n = 12345;
    
    printf("Converting %d to different bases:\n", n);
    
    itob(n, s, 2);
    printf("Binary: %s\n", s);
    
    itob(n, s, 8);
    printf("Octal: %s\n", s);
    
    itob(n, s, 10);
    printf("Decimal: %s\n", s);
    
    itob(n, s, 16);
    printf("Hexadecimal: %s\n", s);
    
    printf("\nTesting with negative number:\n");
    n = -12345;
    itob(n, s, 16);
    printf("Hexadecimal: %s\n", s);
    
    return 0;
} 