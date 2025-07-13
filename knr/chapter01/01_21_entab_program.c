/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include <stdio.h>

/* Exercise 1-21: Write a program entab that replaces strings of blanks by the minimum 
   number of tabs and blanks to achieve the same spacing */

#define TABSTOP 8

int main() {
    int c, pos, spaces;
    
    pos = 0;      /* position in the line */
    spaces = 0;   /* count of consecutive spaces */
    
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++spaces;
            ++pos;
        } else if (c == '\t') {
            spaces = 0;  /* reset spaces count */
            pos = pos + (TABSTOP - (pos % TABSTOP));
        } else {
            /* Output accumulated spaces as tabs and remaining spaces */
            while (spaces >= TABSTOP) {
                putchar('\t');
                spaces -= TABSTOP;
            }
            while (spaces > 0) {
                putchar(' ');
                --spaces;
            }
            
            putchar(c);
            if (c == '\n') {
                pos = 0;
            } else {
                ++pos;
            }
        }
    }
    
    return 0;
} 