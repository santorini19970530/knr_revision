/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise B.1 - Custom printf implementation */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

void myprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    unsigned uval;
    
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'i':
                ival = va_arg(ap, int);
                printf("%i", ival);
                break;
            case 'u':
                uval = va_arg(ap, unsigned);
                printf("%u", uval);
                break;
            case 'o':
                ival = va_arg(ap, int);
                printf("%o", ival);
                break;
            case 'x':
                ival = va_arg(ap, int);
                printf("%x", ival);
                break;
            case 'X':
                ival = va_arg(ap, int);
                printf("%X", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 'F':
                dval = va_arg(ap, double);
                printf("%F", dval);
                break;
            case 'e':
                dval = va_arg(ap, double);
                printf("%e", dval);
                break;
            case 'E':
                dval = va_arg(ap, double);
                printf("%E", dval);
                break;
            case 'g':
                dval = va_arg(ap, double);
                printf("%g", dval);
                break;
            case 'G':
                dval = va_arg(ap, double);
                printf("%G", dval);
                break;
            case 'a':
                dval = va_arg(ap, double);
                printf("%a", dval);
                break;
            case 'A':
                dval = va_arg(ap, double);
                printf("%A", dval);
                break;
            case 'c':
                ival = va_arg(ap, int);
                putchar(ival);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'p':
                ival = va_arg(ap, int);
                printf("%p", (void *)ival);
                break;
            case 'n':
                /* Not implemented - would store count */
                break;
            case '%':
                putchar('%');
                break;
            default:
                putchar('%');
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}

int main() {
    int i = 42;
    double d = 3.14159;
    char *s = "Hello, World!";
    char c = 'A';
    unsigned u = 12345;
    
    printf("Testing custom printf:\n");
    myprintf("Integer: %d\n", i);
    myprintf("Unsigned: %u\n", u);
    myprintf("Octal: %o\n", i);
    myprintf("Hex: %x\n", i);
    myprintf("HEX: %X\n", i);
    myprintf("Float: %f\n", d);
    myprintf("Scientific: %e\n", d);
    myprintf("General: %g\n", d);
    myprintf("String: %s\n", s);
    myprintf("Character: %c\n", c);
    myprintf("Percent: %%\n");
    
    return 0;
} 