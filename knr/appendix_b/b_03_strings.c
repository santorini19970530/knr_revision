/* Exercise B.3 - String library functions */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Custom string functions */

char *mystrcpy(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++) != '\0')
        ;
    return dest;
}

char *mystrncpy(char *dest, const char *src, size_t n) {
    char *d = dest;
    while (n > 0 && *src) {
        *d++ = *src++;
        n--;
    }
    while (n > 0) {
        *d++ = '\0';
        n--;
    }
    return dest;
}

char *mystrcat(char *dest, const char *src) {
    char *d = dest;
    while (*d)
        d++;
    while ((*d++ = *src++) != '\0')
        ;
    return dest;
}

char *mystrncat(char *dest, const char *src, size_t n) {
    char *d = dest;
    while (*d)
        d++;
    while (n > 0 && *src) {
        *d++ = *src++;
        n--;
    }
    *d = '\0';
    return dest;
}

int mystrcmp(const char *s1, const char *s2) {
    while (*s1 == *s2) {
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int mystrncmp(const char *s1, const char *s2, size_t n) {
    while (n > 0 && *s1 == *s2) {
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
        n--;
    }
    if (n == 0)
        return 0;
    return *s1 - *s2;
}

char *mystrchr(const char *s, int c) {
    while (*s != c) {
        if (*s == '\0')
            return NULL;
        s++;
    }
    return (char *)s;
}

char *mystrrchr(const char *s, int c) {
    char *last = NULL;
    while (*s) {
        if (*s == c)
            last = (char *)s;
        s++;
    }
    return last;
}

size_t mystrlen(const char *s) {
    const char *p = s;
    while (*p)
        p++;
    return p - s;
}

char *mystrstr(const char *haystack, const char *needle) {
    if (*needle == '\0')
        return (char *)haystack;
    
    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;
        while (*h && *n && *h == *n) {
            h++;
            n++;
        }
        if (*n == '\0')
            return (char *)haystack;
        haystack++;
    }
    return NULL;
}

int main() {
    char dest[100];
    char src[] = "Hello, World!";
    char test[] = "Hello, World!";
    
    printf("Testing custom string functions:\n\n");
    
    /* Test strcpy */
    mystrcpy(dest, src);
    printf("strcpy: '%s'\n", dest);
    
    /* Test strncpy */
    mystrncpy(dest, "Test", 4);
    printf("strncpy: '%s'\n", dest);
    
    /* Test strcat */
    mystrcat(dest, " String");
    printf("strcat: '%s'\n", dest);
    
    /* Test strncat */
    mystrncat(dest, " Functions", 9);
    printf("strncat: '%s'\n", dest);
    
    /* Test strcmp */
    printf("strcmp('%s', '%s'): %d\n", src, test, mystrcmp(src, test));
    printf("strcmp('%s', 'Hello'): %d\n", src, mystrcmp(src, "Hello"));
    
    /* Test strncmp */
    printf("strncmp('%s', '%s', 5): %d\n", src, test, mystrncmp(src, test, 5));
    
    /* Test strchr */
    char *p = mystrchr(src, 'o');
    printf("strchr('%s', 'o'): %s\n", src, p);
    
    /* Test strrchr */
    p = mystrrchr(src, 'o');
    printf("strrchr('%s', 'o'): %s\n", src, p);
    
    /* Test strlen */
    printf("strlen('%s'): %zu\n", src, mystrlen(src));
    
    /* Test strstr */
    p = mystrstr(src, "World");
    printf("strstr('%s', 'World'): %s\n", src, p);
    
    return 0;
} 