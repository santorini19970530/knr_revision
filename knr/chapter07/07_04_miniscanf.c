/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 7.4 - Miniscanf function */

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

/* Write a miniscanf that handles more of the other facilities of scanf. */

int getch(void);
void ungetch(int);

int miniscanf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int *ival;
    double *dval;
    int c, count = 0;
    
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            if (getch() != *p)
                break;
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int *);
                if (scanf("%d", ival) == 1)
                    count++;
                break;
            case 'f':
                dval = va_arg(ap, double *);
                if (scanf("%lf", dval) == 1)
                    count++;
                break;
            case 's':
                sval = va_arg(ap, char *);
                if (scanf("%s", sval) == 1)
                    count++;
                break;
            case 'c':
                ival = va_arg(ap, int *);
                if ((c = getch()) != EOF) {
                    *ival = c;
                    count++;
                }
                break;
            case 'x':
                ival = va_arg(ap, int *);
                if (scanf("%x", ival) == 1)
                    count++;
                break;
            case 'o':
                ival = va_arg(ap, int *);
                if (scanf("%o", ival) == 1)
                    count++;
                break;
            case 'u':
                ival = va_arg(ap, int *);
                if (scanf("%u", ival) == 1)
                    count++;
                break;
            default:
                if (getch() != *p)
                    break;
                break;
        }
    }
    va_end(ap);
    return count;
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
    int i, j;
    double d;
    char s[100];
    char c;
    
    printf("Testing miniscanf:\n");
    printf("Enter: integer double string character\n");
    printf("Example: 42 3.14 hello A\n");
    
    int result = miniscanf("%d %f %s %c", &i, &d, s, &c);
    printf("Read %d values:\n", result);
    printf("Integer: %d\n", i);
    printf("Double: %f\n", d);
    printf("String: %s\n", s);
    printf("Character: %c\n", c);
    
    return 0;
} 