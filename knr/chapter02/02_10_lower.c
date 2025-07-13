/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Exercise 2-10: Rewrite the function lower, which converts upper case letters to lower case, 
   with a conditional expression instead of if-else */

#include <stdio.h>

int lower(int c);

int main() {
    char test[] = "Hello World 123!";
    int i;
    
    printf("Original: %s\n", test);
    printf("Lower case: ");
    
    for (i = 0; test[i] != '\0'; i++) {
        putchar(lower(test[i]));
    }
    printf("\n");
    
    return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
} 
