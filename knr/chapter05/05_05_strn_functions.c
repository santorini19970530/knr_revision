/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 5.5 - strncpy, strncat, strncmp */

#include <stdio.h>

/* Write versions of the library functions strncpy, strncat, and strncmp,
   which operate on at most the first n characters of their argument strings. */

char *strncpy_ptr(char *s, char *t, int n) {
    char *s_start = s;
    
    while (n > 0 && (*s++ = *t++))
        n--;
    while (n > 0) {
        *s++ = '\0';
        n--;
    }
    return s_start;
}

char *strncat_ptr(char *s, char *t, int n) {
    char *s_start = s;
    
    while (*s)
        s++;
    while (n > 0 && (*s++ = *t++))
        n--;
    *s = '\0';
    return s_start;
}

int strncmp_ptr(char *s, char *t, int n) {
    while (n > 0 && *s == *t) {
        if (*s == '\0')
            return 0;
        s++;
        t++;
        n--;
    }
    if (n == 0)
        return 0;
    return *s - *t;
}

int main() {
    char s1[50] = "Hello";
    char t1[] = "World";
    
    printf("strncpy test:\n");
    printf("Before: '%s'\n", s1);
    strncpy_ptr(s1, t1, 3);
    printf("After strncpy(s1, t1, 3): '%s'\n", s1);
    
    char s2[50] = "Hello";
    char t2[] = "World";
    
    printf("\nstrncat test:\n");
    printf("Before: '%s'\n", s2);
    strncat_ptr(s2, t2, 3);
    printf("After strncat(s2, t2, 3): '%s'\n", s2);
    
    char s3[] = "Hello";
    char t3[] = "Help";
    char t4[] = "Hello";
    
    printf("\nstrncmp test:\n");
    printf("strncmp('%s', '%s', 3): %d\n", s3, t3, strncmp_ptr(s3, t3, 3));
    printf("strncmp('%s', '%s', 5): %d\n", s3, t4, strncmp_ptr(s3, t4, 5));
    printf("strncmp('%s', '%s', 2): %d\n", s3, t3, strncmp_ptr(s3, t3, 2));
    
    return 0;
} 