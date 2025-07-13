/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 5.2 - getfloat function */

#include <stdio.h>
#include <ctype.h>

/* Write getfloat, the floating-point analog of getint. What type does
   getfloat return as its function value? */

int getch(void);
void ungetch(int);

int getfloat(float *pn) {
    int c, sign;
    float power;
    
    while (isspace(c = getch()))  /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);  /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c) && c != '.') {
            ungetch(c);  /* push back non-digit */
            ungetch(sign == 1 ? '+' : '-');  /* push back sign */
            return 0;
        }
    }
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;
    }
    *pn = sign * *pn / power;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int main() {
    float n;
    int ret;
    
    printf("Enter floating-point numbers:\n");
    while ((ret = getfloat(&n)) != EOF) {
        if (ret == 0)
            printf("Not a valid number\n");
        else
            printf("Got: %f\n", n);
    }
    
    return 0;
} 