/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.11: strcat function implementation */

#include <stdio.h>

/* strcat: concatenate t to end of s; s must be big enough */
void strcat_custom(char s[], char t[]) {
    int i, j;
    
    i = j = 0;
    while (s[i] != '\0')    /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0')    /* copy t */
        ;
}

int main() {
    char s[50] = "Hello, ";
    char t[] = "world!";
    
    printf("s = \"%s\"\n", s);
    printf("t = \"%s\"\n", t);
    strcat_custom(s, t);
    printf("After strcat: s = \"%s\"\n", s);
    
    return 0;
} 
