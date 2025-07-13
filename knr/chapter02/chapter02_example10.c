/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.10: squeeze function implementation */

#include <stdio.h>

/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

int main() {
    char s1[] = "Mississippi";
    char s2[] = "Hello World!";
    
    printf("Original: %s\n", s1);
    squeeze(s1, 's');
    printf("After squeeze(s, 's'): %s\n", s1);
    
    printf("Original: %s\n", s2);
    squeeze(s2, 'l');
    printf("After squeeze(s, 'l'): %s\n", s2);
    
    return 0;
} 
