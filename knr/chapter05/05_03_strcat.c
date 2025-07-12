/* Exercise 5.3 - strcat with pointers */

#include <stdio.h>

/* Write a pointer version of the function strcat that we showed in Chapter 2:
   strcat(s,t) copies the string t to the end of s. */

void strcat_ptr(char *s, char *t) {
    while (*s)  /* find end of s */
        s++;
    while (*s++ = *t++)  /* copy t */
        ;
}

int main() {
    char s[100] = "Hello, ";
    char t[] = "World!";
    
    printf("Before strcat: '%s'\n", s);
    strcat_ptr(s, t);
    printf("After strcat: '%s'\n", s);
    
    char s2[100] = "Programming in ";
    char t2[] = "C";
    
    printf("Before strcat: '%s'\n", s2);
    strcat_ptr(s2, t2);
    printf("After strcat: '%s'\n", s2);
    
    return 0;
} 