/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 5.10 - Reverse Polish calculator with getline
 * 
 * Write the program expr, which evaluates a reverse Polish
 * expression from the command line, where each operator or
 * operand is a separate argument.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main(int argc, char *argv[]) {
    int type;
    double op2;
    char s[MAXOP];
    
    if (argc < 2) {
        printf("Usage: %s expression\n", argv[0]);
        printf("Example: %s 3 4 +\n", argv[0]);
        return 1;
    }
    
    printf("Evaluating: ");
    for (int i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");
    
    for (int i = 1; i < argc; i++) {
        strcpy(s, argv[i]);
        
        if (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1]))) {
            type = NUMBER;
        } else {
            type = s[0];
        }
        
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
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    
    printf("Result: %.8g\n", pop());
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