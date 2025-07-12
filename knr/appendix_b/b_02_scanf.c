/* Exercise B.2 - Custom scanf implementation */

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>

int myscanf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int *ival;
    double *dval;
    unsigned *uval;
    int c, count = 0;
    
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            if (getchar() != *p)
                break;
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int *);
                if (scanf("%d", ival) == 1)
                    count++;
                break;
            case 'i':
                ival = va_arg(ap, int *);
                if (scanf("%i", ival) == 1)
                    count++;
                break;
            case 'u':
                uval = va_arg(ap, unsigned *);
                if (scanf("%u", uval) == 1)
                    count++;
                break;
            case 'o':
                ival = va_arg(ap, int *);
                if (scanf("%o", ival) == 1)
                    count++;
                break;
            case 'x':
                ival = va_arg(ap, int *);
                if (scanf("%x", ival) == 1)
                    count++;
                break;
            case 'X':
                ival = va_arg(ap, int *);
                if (scanf("%X", ival) == 1)
                    count++;
                break;
            case 'f':
                dval = va_arg(ap, double *);
                if (scanf("%lf", dval) == 1)
                    count++;
                break;
            case 'F':
                dval = va_arg(ap, double *);
                if (scanf("%lf", dval) == 1)
                    count++;
                break;
            case 'e':
                dval = va_arg(ap, double *);
                if (scanf("%le", dval) == 1)
                    count++;
                break;
            case 'E':
                dval = va_arg(ap, double *);
                if (scanf("%lE", dval) == 1)
                    count++;
                break;
            case 'g':
                dval = va_arg(ap, double *);
                if (scanf("%lg", dval) == 1)
                    count++;
                break;
            case 'G':
                dval = va_arg(ap, double *);
                if (scanf("%lG", dval) == 1)
                    count++;
                break;
            case 'a':
                dval = va_arg(ap, double *);
                if (scanf("%la", dval) == 1)
                    count++;
                break;
            case 'A':
                dval = va_arg(ap, double *);
                if (scanf("%lA", dval) == 1)
                    count++;
                break;
            case 'c':
                ival = va_arg(ap, int *);
                if ((c = getchar()) != EOF) {
                    *ival = c;
                    count++;
                }
                break;
            case 's':
                sval = va_arg(ap, char *);
                if (scanf("%s", sval) == 1)
                    count++;
                break;
            case 'p':
                ival = va_arg(ap, int *);
                if (scanf("%p", (void **)ival) == 1)
                    count++;
                break;
            case 'n':
                ival = va_arg(ap, int *);
                *ival = count;
                break;
            case '%':
                if (getchar() != '%')
                    break;
                break;
            default:
                if (getchar() != *p)
                    break;
                break;
        }
    }
    va_end(ap);
    return count;
}

int main() {
    int i, j;
    double d;
    char s[100];
    char c;
    unsigned u;
    
    printf("Testing custom scanf:\n");
    printf("Enter: integer double string character unsigned\n");
    printf("Example: 42 3.14 hello A 12345\n");
    
    int result = myscanf("%d %f %s %c %u", &i, &d, s, &c, &u);
    printf("Read %d values:\n", result);
    printf("Integer: %d\n", i);
    printf("Double: %f\n", d);
    printf("String: %s\n", s);
    printf("Character: %c\n", c);
    printf("Unsigned: %u\n", u);
    
    return 0;
} 