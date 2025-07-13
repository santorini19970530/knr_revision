/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include <stdio.h>

/* Exercise 1-20: Write a program detab that replaces tabs in the input with the proper 
   number of blanks to space to the next tab stop */

#define TABSTOP 8

int main() {
    int c, pos;
    
    pos = 0;  /* position in the line */
    
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            /* Calculate how many spaces to add */
            int spaces = TABSTOP - (pos % TABSTOP);
            for (int i = 0; i < spaces; ++i) {
                putchar(' ');
                ++pos;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 0;  /* reset position for new line */
        } else {
            putchar(c);
            ++pos;
        }
    }
    
    return 0;
} 