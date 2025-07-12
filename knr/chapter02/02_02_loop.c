#include <stdio.h>

/* Exercise 2.2: Write a loop equivalent to the for loop above without using && or || */

int main() {
    int i, lim, c;
    char s[1000];
    
    lim = 1000;
    
    /* Original loop with && */
    printf("Original loop with &&:\n");
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    printf("Read: %s\n\n", s);
    
    /* Equivalent loop without && or || */
    printf("Equivalent loop without && or ||:\n");
    for (i = 0; i < lim - 1; ++i) {
        c = getchar();
        if (c == EOF)
            break;
        if (c == '\n')
            break;
        s[i] = c;
    }
    s[i] = '\0';
    printf("Read: %s\n", s);
    
    return 0;
} 