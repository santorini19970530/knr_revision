/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 7.2 - Convert to uppercase */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Write a program that converts upper case to lower or lower case to upper,
   depending on the name it is invoked with, as found in argv[0]. */

int main(int argc, char *argv[]) {
    int c;
    char *prog = argv[0];
    
    /* Check if program name contains 'upper' or 'lower' */
    if (strstr(prog, "upper") != NULL) {
        /* Convert to uppercase */
        while ((c = getchar()) != EOF)
            putchar(toupper(c));
    } else if (strstr(prog, "lower") != NULL) {
        /* Convert to lowercase */
        while ((c = getchar()) != EOF)
            putchar(tolower(c));
    } else {
        printf("Program name should contain 'upper' or 'lower'\n");
        printf("Current name: %s\n", prog);
        return 1;
    }
    
    return 0;
} 