/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Exercise 1-8: Write a program to count blanks, tabs, and newlines */

#include <stdio.h>

int main() {
    int c, blanks, tabs, newlines;
    
    blanks = tabs = newlines = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++newlines;
    }
    
    printf("blanks: %d, tabs: %d, newlines: %d\n", 
           blanks, tabs, newlines);
    
    return 0;
} 
