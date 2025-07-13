/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.8: lower function implementation */

#include <stdio.h>

/* lower: convert c to lower case; ASCII only */
int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int main() {
    char s[] = "HeLLo WoRLd!";

    printf("Original: %s\n", s);
    printf("Lowered:  ");
    
    for (int i = 0; s[i] != '\0'; i++)
        putchar(lower(s[i]));

    putchar('\n');
    
    return 0;
} 
