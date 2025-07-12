#include <stdio.h>
#include <ctype.h>

/* Exercise 2.3: Write a function htoi(s), which converts a string of hexadecimal digits
   (including an optional 0x or 0X) into its equivalent integer value. The allowable digits
   are 0 through 9, a through f, and A through F. */

int htoi(char s[]) {
    int i, n;
    
    n = 0;
    i = 0;
    
    /* Skip optional 0x or 0X prefix */
    if (s[i] == '0') {
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }
    
    /* Convert hex digits to integer */
    for (; s[i] != '\0'; ++i) {
        if (isdigit(s[i]))
            n = 16 * n + (s[i] - '0');
        else if (s[i] >= 'a' && s[i] <= 'f')
            n = 16 * n + (s[i] - 'a' + 10);
        else if (s[i] >= 'A' && s[i] <= 'F')
            n = 16 * n + (s[i] - 'A' + 10);
        else
            break;  /* Invalid character */
    }
    
    return n;
}

int main() {
    char *test_cases[] = {
        "0x1A",
        "0X1A",
        "1A",
        "0xFF",
        "0xff",
        "0x1234",
        "0xABCD",
        "0xabcd"
    };
    int num_tests = 8;
    int i;
    
    printf("Hexadecimal to Integer Conversion:\n\n");
    
    for (i = 0; i < num_tests; ++i) {
        int result = htoi(test_cases[i]);
        printf("htoi(\"%s\") = %d\n", test_cases[i], result);
    }
    
    return 0;
} 