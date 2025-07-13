/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 4.5 - Add access to library functions */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
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

int getch(void);
void ungetch(int);

int getop(char s[]) {
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    
    i = 0;
    if (c == '-') {
        s[++i] = c;
        c = getch();
    }
    
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
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
    int type;
    double op2;
    char s[MAXOP];
    
    printf("Calculator with Library Functions\n");
    printf("Functions: sin, cos, exp, pow, sqrt\n");
    printf("Usage: sin 3.14, pow 2 3, sqrt 16\n");
    
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
            case 's':  /* sin */
                if (strcmp(s, "sin") == 0)
                    push(sin(pop()));
                else if (strcmp(s, "sqrt") == 0)
                    push(sqrt(pop()));
                else
                    printf("error: unknown command %s\n", s);
                break;
            case 'c':  /* cos */
                if (strcmp(s, "cos") == 0)
                    push(cos(pop()));
                else
                    printf("error: unknown command %s\n", s);
                break;
            case 'e':  /* exp */
                if (strcmp(s, "exp") == 0)
                    push(exp(pop()));
                else
                    printf("error: unknown command %s\n", s);
                break;
            case 'p':  /* pow */
                if (strcmp(s, "pow") == 0) {
                    op2 = pop();
                    push(pow(pop(), op2));
                } else
                    printf("error: unknown command %s\n", s);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case 'q':
                return 0;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
} 