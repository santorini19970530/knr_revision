#include <stdio.h>

/* Exercise 1-23: Write a program to remove all comments from a C program */

int main() {
    int c, next;
    
    while ((c = getchar()) != EOF) {
        if (c == '/') {
            next = getchar();
            if (next == '*') {
                /* Skip comment */
                int prev = 0;
                while ((c = getchar()) != EOF) {
                    if (prev == '*' && c == '/')
                        break;
                    prev = c;
                }
            } else if (next == '/') {
                /* Skip single line comment */
                while ((c = getchar()) != EOF && c != '\n')
                    ;
                if (c == '\n')
                    putchar(c);
            } else {
                putchar(c);
                putchar(next);
            }
        } else {
            putchar(c);
        }
    }
    
    return 0;
} 