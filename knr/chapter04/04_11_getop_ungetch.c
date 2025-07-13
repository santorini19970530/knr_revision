/*
 * Exercise 4.11 - Modify getop to use ungetch
 * 
 * Modify getop so that it doesn't need to use ungetch.
 * Use an internal static variable to keep track of the
 * last character read.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main() {
    int type;
    double op2;
    char s[MAXOP];
    
    printf("Calculator with modified getop\n");
    printf("Enter expressions like: 3 4 +\n");
    printf("Press Ctrl+D to exit\n\n");
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    
    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* Modified getop that doesn't use ungetch */
int getop(char s[]) {
    int i, c;
    static int last_char = ' ';
    
    /* Skip white space */
    while ((c = (last_char == ' ') ? getchar() : last_char) == ' ' || c == '\t') {
        last_char = ' ';
    }
    
    s[0] = c;
    s[1] = '\0';
    
    if (!isdigit(c) && c != '.') {
        last_char = ' ';
        return c;
    }
    
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    
    if (c != EOF)
        last_char = c;
    else
        last_char = ' ';
    
    return NUMBER;
} 