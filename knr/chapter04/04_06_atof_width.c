/*
 * Exercise 4.6 - Add field width support to atof
 * 
 * Extend atof to handle scientific notation of the form
 * 123.45e-6 where a floating-point number may be followed
 * by e or E and an optionally signed exponent.
 */

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {
    char test1[] = "123.45e-6";
    char test2[] = "1.23E+3";
    char test3[] = "0.001e2";
    
    printf("atof(\"%s\") = %g\n", test1, atof(test1));
    printf("atof(\"%s\") = %g\n", test2, atof(test2));
    printf("atof(\"%s\") = %g\n", test3, atof(test3));
    
    return 0;
}

/* atof: convert string s to double with scientific notation support */
double atof(char s[]) {
    double val, power;
    int i, sign, exp_sign, exp_val;
    
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
        for (exp_val = 0; isdigit(s[i]); i++)
            exp_val = 10 * exp_val + (s[i] - '0');
        
        /* Apply exponent */
        if (exp_sign == 1) {
            for (int j = 0; j < exp_val; j++)
                val *= 10.0;
        } else {
            for (int j = 0; j < exp_val; j++)
                val /= 10.0;
        }
    }
    
    return sign * val / power;
} 