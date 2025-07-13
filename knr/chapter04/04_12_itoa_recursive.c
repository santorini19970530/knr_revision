/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 4.12 - Recursive itoa
 * 
 * Adapt the ideas of printd to write a recursive version
 * of itoa; that is, convert an integer into a string by
 * calling a recursive routine.
 */

#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main() {
    char s[100];
    int test_cases[] = {123, -456, 0, 999999, -999999};
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("Recursive itoa function\n\n");
    
    for (int i = 0; i < num_tests; i++) {
        itoa(test_cases[i], s);
        printf("itoa(%d) = \"%s\"\n", test_cases[i], s);
    }
    
    return 0;
}

/* itoa: convert n to characters in s - recursive version */
void itoa(int n, char s[]) {
    static int i = 0;
    static int sign = 0;
    
    if (i == 0) {
        /* First call - initialize */
        i = 0;
        sign = (n < 0) ? -1 : 1;
        if (sign < 0) {
            s[i++] = '-';
            n = -n;
        }
    }
    
    if (n / 10) {
        itoa(n / 10, s);
    }
    
    s[i++] = n % 10 + '0';
    s[i] = '\0';
    
    if (i > 0 && s[i-1] != '-') {
        /* Reset static variables for next call */
        i = 0;
        sign = 0;
    }
}

/* reverse: reverse string s in place */
void reverse(char s[]) {
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
} 