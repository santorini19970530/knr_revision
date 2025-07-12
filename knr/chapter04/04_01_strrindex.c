/* Exercise 4.1 - Rightmost occurrence of substring */

#include <stdio.h>

/* Write the function strrindex(s,t) which returns the position of the
   rightmost occurrence of t in s, or -1 if there is none. */

int strrindex(char s[], char t[]) {
    int i, j, k, pos = -1;
    
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;
    }
    return pos;
}

int main() {
    char s[] = "hello world hello";
    char t1[] = "hello";
    char t2[] = "world";
    char t3[] = "xyz";
    
    printf("String: '%s'\n", s);
    printf("Rightmost 'hello': %d\n", strrindex(s, t1));
    printf("Rightmost 'world': %d\n", strrindex(s, t2));
    printf("Rightmost 'xyz': %d\n", strrindex(s, t3));
    
    return 0;
} 