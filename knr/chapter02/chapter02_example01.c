/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.1: strlen function demonstration */

#include <stdio.h>

/* strlen: return length of s */
int strlen(char s[]){
    int i;
    
    while (s[i] != '\0')
        ++i;
    
    return i;
}

int main() {
    char s[] = "Hello, world!";

    printf("String: %s\n", s);
    printf("Length: %zu\n", strlen(s));

    return 0;
} 
