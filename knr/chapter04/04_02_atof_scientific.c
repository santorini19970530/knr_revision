/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 4.2 - Extend atof to handle scientific notation */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* Extend atof to handle scientific notation of the form 123.45e-6
   where a floating-point number may be followed by e or E and an
   optionally signed exponent. */

double atof_scientific(char s[]) {
    double val, power, exp_val;
    int i, sign, exp_sign, exp;
    
    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    
    /* Handle scientific notation */
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
        exp_val = pow(10.0, exp_sign * exp);
        return sign * val / power * exp_val;
    }
    
    return sign * val / power;
}

int main() {
    char test_cases[][20] = {
        "123.45",
        "123.45e-6",
        "123.45E+3",
        "-123.45e2",
        "0.001e3"
    };
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    printf("Testing atof with scientific notation:\n");
    for (int i = 0; i < num_tests; i++) {
        double result = atof_scientific(test_cases[i]);
        printf("'%s' -> %g\n", test_cases[i], result);
    }
    
    return 0;
} 