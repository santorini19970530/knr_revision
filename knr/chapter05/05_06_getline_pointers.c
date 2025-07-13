/*
 * Exercise 5.6 - Rewrite getline with pointers
 * 
 * Rewrite appropriate programs from earlier chapters and
 * exercises with pointers instead of array indexing.
 * Good possibilities include getline (Chapters 1 and 4),
 * atoi, itoa, and their variants (Chapters 2, 3, and 4),
 * reverse (Chapter 3), and strindex and getop (Chapter 4).
 */

#include <stdio.h>
#include <string.h>

int getline(char *s, int lim);
void copy(char *to, char *from);

int main() {
    char line[1000];
    char longest[1000];
    int len;
    int max = 0;
    
    printf("Enter lines of text (Ctrl+D to end):\n");
    
    while ((len = getline(line, 1000)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    
    if (max > 0) {
        printf("\nLongest line (%d characters):\n%s", max, longest);
    }
    
    return 0;
}

/* getline: read a line into s, return length - pointer version */
int getline(char *s, int lim) {
    int c;
    char *t = s;
    
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

/* copy: copy 'from' into 'to'; assume to is big enough - pointer version */
void copy(char *to, char *from) {
    while ((*to = *from) != '\0') {
        to++;
        from++;
    }
} 