/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise B.4 - Math library functions */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Custom math functions */

double myabs(double x) {
    return x < 0 ? -x : x;
}

double myfloor(double x) {
    if (x >= 0) {
        return (double)((long)x);
    } else {
        return (double)((long)(x - 1));
    }
}

double myceil(double x) {
    if (x >= 0) {
        return (double)((long)(x + 1));
    } else {
        return (double)((long)x);
    }
}

double myfmod(double x, double y) {
    if (y == 0.0) {
        return 0.0; /* Error case */
    }
    double q = x / y;
    return x - y * myfloor(q);
}

double mypow(double x, double y) {
    if (y == 0.0) return 1.0;
    if (x == 0.0) return 0.0;
    if (y == 1.0) return x;
    if (y == -1.0) return 1.0 / x;
    
    /* Simple implementation for integer powers */
    if (y == (double)((long)y)) {
        long n = (long)y;
        double result = 1.0;
        if (n > 0) {
            for (long i = 0; i < n; i++)
                result *= x;
        } else {
            for (long i = 0; i < -n; i++)
                result /= x;
        }
        return result;
    }
    
    /* For non-integer powers, use log and exp */
    return exp(y * log(x));
}

double mysqrt(double x) {
    if (x < 0.0) return 0.0; /* Error case */
    if (x == 0.0) return 0.0;
    if (x == 1.0) return 1.0;
    
    double guess = x / 2.0;
    double prev;
    
    do {
        prev = guess;
        guess = (guess + x / guess) / 2.0;
    } while (myabs(guess - prev) > 1e-10);
    
    return guess;
}

double myexp(double x) {
    if (x == 0.0) return 1.0;
    if (x < 0.0) return 1.0 / myexp(-x);
    
    double result = 1.0;
    double term = 1.0;
    double n = 1.0;
    
    while (term > 1e-10) {
        term *= x / n;
        result += term;
        n += 1.0;
    }
    
    return result;
}

double mylog(double x) {
    if (x <= 0.0) return 0.0; /* Error case */
    if (x == 1.0) return 0.0;
    
    double y = (x - 1.0) / (x + 1.0);
    double result = 0.0;
    double term = y;
    double n = 1.0;
    
    while (myabs(term) > 1e-10) {
        result += term / n;
        term *= y * y;
        n += 2.0;
    }
    
    return 2.0 * result;
}

double mysin(double x) {
    /* Reduce to [-π, π] */
    while (x > M_PI) x -= 2 * M_PI;
    while (x < -M_PI) x += 2 * M_PI;
    
    double result = 0.0;
    double term = x;
    double n = 1.0;
    int sign = 1;
    
    while (myabs(term) > 1e-10) {
        result += sign * term;
        term *= x * x / ((2 * n) * (2 * n + 1));
        sign = -sign;
        n += 1.0;
    }
    
    return result;
}

double mycos(double x) {
    return mysin(x + M_PI / 2.0);
}

int main() {
    double x = 2.5;
    double y = 3.0;
    
    printf("Testing custom math functions:\n\n");
    
    printf("x = %f, y = %f\n\n", x, y);
    
    printf("abs(%f) = %f\n", -x, myabs(-x));
    printf("floor(%f) = %f\n", x, myfloor(x));
    printf("ceil(%f) = %f\n", x, myceil(x));
    printf("fmod(%f, %f) = %f\n", x, y, myfmod(x, y));
    printf("pow(%f, %f) = %f\n", x, y, mypow(x, y));
    printf("sqrt(%f) = %f\n", x, mysqrt(x));
    printf("exp(%f) = %f\n", x, myexp(x));
    printf("log(%f) = %f\n", x, mylog(x));
    printf("sin(%f) = %f\n", x, mysin(x));
    printf("cos(%f) = %f\n", x, mycos(x));
    
    printf("\nComparison with standard library:\n");
    printf("Standard abs: %f\n", fabs(-x));
    printf("Standard floor: %f\n", floor(x));
    printf("Standard ceil: %f\n", ceil(x));
    printf("Standard fmod: %f\n", fmod(x, y));
    printf("Standard pow: %f\n", pow(x, y));
    printf("Standard sqrt: %f\n", sqrt(x));
    printf("Standard exp: %f\n", exp(x));
    printf("Standard log: %f\n", log(x));
    printf("Standard sin: %f\n", sin(x));
    printf("Standard cos: %f\n", cos(x));
    
    return 0;
} 