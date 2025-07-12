/* Exercise 7.1 - Convert to lowercase */

#include <stdio.h>
#include <ctype.h>

/* Write a program that converts upper case to lower or lower case to upper,
   depending on the name it is invoked with, as found in argv[0]. */

int main(int argc, char *argv[]) {
    int c;
    
    if (argc < 2) {
        printf("Usage: %s [upper|lower]\n", argv[0]);
        return 1;
    }
    
    if (strcmp(argv[1], "lower") == 0) {
        /* Convert to lowercase */
        while ((c = getchar()) != EOF)
            putchar(tolower(c));
    } else if (strcmp(argv[1], "upper") == 0) {
        /* Convert to uppercase */
        while ((c = getchar()) != EOF)
            putchar(toupper(c));
    } else {
        printf("Invalid option: %s\n", argv[1]);
        printf("Use 'upper' or 'lower'\n");
        return 1;
    }
    
    return 0;
} 