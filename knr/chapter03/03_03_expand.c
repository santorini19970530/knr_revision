/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 3.3 - Expand shorthand notation */

#include <stdio.h>

/* Write a function expand(s1,s2) that expands shorthand notations like a-z
   in the string s1 into the equivalent complete list abc...xyz in s2. Allow
   for letters of either case and digits, and be prepared to handle cases
   like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing -
   is taken literally. */

void expand(char s1[], char s2[]) {
    int i, j, k;
    
    for (i = j = 0; s1[i] != '\0'; i++) {
        if (s1[i] == '-' && i > 0 && s1[i+1] != '\0') {
            char start = s1[i-1];
            char end = s1[i+1];
            
            /* Check if it's a valid range */
            if ((start >= 'a' && start <= 'z' && end >= 'a' && end <= 'z') ||
                (start >= 'A' && start <= 'Z' && end >= 'A' && end <= 'Z') ||
                (start >= '0' && start <= '9' && end >= '0' && end <= '9')) {
                
                if (start <= end) {
                    /* Expand the range */
                    for (k = start; k <= end; k++) {
                        s2[j++] = k;
                    }
                } else {
                    /* Reverse range */
                    for (k = start; k >= end; k--) {
                        s2[j++] = k;
                    }
                }
                i++; /* Skip the next character since we've processed it */
            } else {
                /* Not a valid range, copy the dash literally */
                s2[j++] = s1[i];
            }
        } else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "a-z";
    char s2[100];
    
    expand(s1, s2);
    printf("'%s' -> '%s'\n", s1, s2);
    
    char s3[] = "A-Z";
    expand(s3, s2);
    printf("'%s' -> '%s'\n", s3, s2);
    
    char s4[] = "0-9";
    expand(s4, s2);
    printf("'%s' -> '%s'\n", s4, s2);
    
    char s5[] = "a-b-c";
    expand(s5, s2);
    printf("'%s' -> '%s'\n", s5, s2);
    
    char s6[] = "a-z0-9";
    expand(s6, s2);
    printf("'%s' -> '%s'\n", s6, s2);
    
    char s7[] = "-a-z";
    expand(s7, s2);
    printf("'%s' -> '%s'\n", s7, s2);
    
    return 0;
} 