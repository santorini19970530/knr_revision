/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include <stdio.h>

/* Exercise 2.5: Write the function any(s1,s2), which returns the first location in a string s1
   where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
   (The standard library function strpbrk does the same job but returns a pointer to the location.) */

int any(char s1[], char s2[]) {
    int i, j;
    
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                return i;  /* Found a match */
        }
    }
    return -1;  /* No match found */
}

int main() {
    char s1[] = "hello world";
    char s2[] = "aeiou";
    char s3[] = "xyz";
    
    printf("String s1: \"%s\"\n", s1);
    printf("String s2: \"%s\"\n", s2);
    printf("String s3: \"%s\"\n\n", s3);
    
    int result1 = any(s1, s2);
    int result2 = any(s1, s3);
    
    if (result1 != -1)
        printf("First vowel found at position %d (character '%c')\n", result1, s1[result1]);
    else
        printf("No vowels found in s1\n");
    
    if (result2 != -1)
        printf("First character from s3 found at position %d\n", result2);
    else
        printf("No characters from s3 found in s1\n");
    
    return 0;
} 