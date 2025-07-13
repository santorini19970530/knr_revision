/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include <stdio.h>

/* Exercise 1-12 */

int main() {
    int c;
    int in_word = 0;  /* flag to track if we're inside a word */
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (in_word) {
                putchar('\n');
                in_word = 0;
            }
        } else {
            putchar(c);
            in_word = 1;
        }
    }
    
    return 0;
} 
