/* Exercise 5.1 - getint with pointer */

#include <stdio.h>
#include <ctype.h>

/* As written, getint treats a + or - not followed by a digit as a valid
   representation of zero. Fix it to push such a character back on the input. */

int getch(void);
void ungetch(int);

int getint(int *pn) {
    int c, sign;
    
    while (isspace(c = getch()))  /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);  /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);  /* push back non-digit */
            ungetch(sign == 1 ? '+' : '-');  /* push back sign */
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
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
    int n, ret;
    
    printf("Enter integers (non-digit after +/- will be pushed back):\n");
    while ((ret = getint(&n)) != EOF) {
        if (ret == 0)
            printf("Not a valid number\n");
        else
            printf("Got: %d\n", n);
    }
    
    return 0;
} 