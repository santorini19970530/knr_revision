/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 3.6 - Add field width support to itoa */

#include <stdio.h>
#include <string.h>

/* Write a version of itoa that accepts three arguments instead of two. The
   third argument is a minimum field width; the converted number must be
   padded with blanks on the left if necessary to make it wide enough. */

void reverse(char s[]) {
    int i, j, c;
    
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa_width(int n, char s[], int w) {
    int i, sign, len;
    
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
    
    /* Add padding if necessary */
    len = strlen(s);
    if (len < w) {
        /* Move string to the right to make room for padding */
        for (i = len; i >= 0; i--)
            s[i + w - len] = s[i];
        /* Fill with blanks */
        for (i = 0; i < w - len; i++)
            s[i] = ' ';
    }
}

int main() {
    char s[100];
    int test_cases[] = {123, -123, 0, 9999, -9999};
    int widths[] = {5, 8, 10, 3, 6};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("Testing itoa with field width:\n");
    for (int i = 0; i < num_tests; i++) {
        int n = test_cases[i];
        int w = widths[i];
        
        itoa_width(n, s, w);
        printf("itoa(%d, width=%d) = '%s'\n", n, w, s);
    }
    
    return 0;
} 