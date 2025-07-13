/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Exercise 1-9: Write a program to copy its input to its output, 
   replacing each string of one or more blanks by a single blank */

#include <stdio.h>

int main() {
    int c;
    int last_was_blank = 0;  /* flag to track if last char was blank */
    
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (!last_was_blank) {
                putchar(c);
                last_was_blank = 1;
            }
            /* skip additional blanks */
        } else {
            putchar(c);
            last_was_blank = 0;
        }
    }
    
    return 0;
} 
