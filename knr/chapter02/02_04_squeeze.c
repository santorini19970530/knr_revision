#include <stdio.h>

/* Exercise 2.4: Write an alternative version of squeeze(s1,s2) that deletes each character
   in s1 that matches any character in the string s2. */

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    
    for (i = j = 0; s1[i] != '\0'; i++) {
        /* Check if current character is in s2 */
        for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; k++)
            ;
        
        /* If character not found in s2, keep it */
        if (s2[k] == '\0')
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

int main() {
    char s1[] = "hello world";
    char s2[] = "lo";
    
    printf("Original string: \"%s\"\n", s1);
    printf("Characters to remove: \"%s\"\n", s2);
    
    squeeze(s1, s2);
    
    printf("After squeeze: \"%s\"\n", s1);
    
    return 0;
} 