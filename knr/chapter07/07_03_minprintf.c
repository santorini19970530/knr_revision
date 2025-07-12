/* Exercise 7.3 - Minprintf function */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/* Write a minprintf that handles more of the other facilities of printf. */

void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    
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
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'c':
                ival = va_arg(ap, int);
                putchar(ival);
                break;
            case 'x':
                ival = va_arg(ap, int);
                printf("%x", ival);
                break;
            case 'o':
                ival = va_arg(ap, int);
                printf("%o", ival);
                break;
            case 'u':
                ival = va_arg(ap, int);
                printf("%u", ival);
                break;
            case 'g':
                dval = va_arg(ap, double);
                printf("%g", dval);
                break;
            case 'e':
                dval = va_arg(ap, double);
                printf("%e", dval);
                break;
            default:
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
    
    printf("Testing minprintf:\n");
    minprintf("Integer: %d\n", i);
    minprintf("Float: %f\n", d);
    minprintf("String: %s\n", s);
    minprintf("Character: %c\n", c);
    minprintf("Hex: %x\n", i);
    minprintf("Octal: %o\n", i);
    minprintf("Unsigned: %u\n", i);
    minprintf("Scientific: %e\n", d);
    minprintf("General: %g\n", d);
    
    return 0;
} 