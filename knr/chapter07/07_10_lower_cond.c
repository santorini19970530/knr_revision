/*
 * Exercise 7.10 - Convert to lowercase with conditional
 * 
 * Write a program to convert upper case to lower or lower
 * case to upper, depending on the name it is invoked with,
 * as found in argv[0].
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    int c;
    int to_upper = 0;
    
    /* Check program name to determine conversion */
    if (strstr(argv[0], "upper") != NULL) {
        to_upper = 1;
        printf("Converting to UPPERCASE\n");
    } else {
        printf("Converting to lowercase\n");
    }
    
    printf("Enter text (Ctrl+D to end):\n");
    
    while ((c = getchar()) != EOF) {
        if (to_upper) {
            putchar(toupper(c));
        } else {
            putchar(tolower(c));
        }
    }
    
    return 0;
} 