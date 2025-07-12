/* Exercise 4.4 - Add commands to calculator */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define COMMAND 'c'

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

void print_top(void) {
    if (sp > 0)
        printf("Top of stack: %.8g\n", val[sp-1]);
    else
        printf("error: stack empty\n");
}

void duplicate_top(void) {
    if (sp > 0)
        push(val[sp-1]);
    else
        printf("error: stack empty\n");
}

void swap_top(void) {
    if (sp >= 2) {
        double temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    } else
        printf("error: not enough elements to swap\n");
}

void clear_stack(void) {
    sp = 0;
    printf("Stack cleared\n");
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
    
    printf("Enhanced Reverse Polish Calculator\n");
    printf("Commands: p (print top), d (duplicate), s (swap), c (clear), q (quit)\n");
    
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
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push((int)pop() % (int)op2);
                else
                    printf("error: zero divisor\n");
                break;
            case 'p':
                print_top();
                break;
            case 'd':
                duplicate_top();
                break;
            case 's':
                swap_top();
                break;
            case 'c':
                clear_stack();
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