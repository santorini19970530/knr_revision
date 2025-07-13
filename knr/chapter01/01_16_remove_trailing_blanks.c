/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include <stdio.h>

/* Exercise 1-16: Write a program to remove trailing blanks and tabs from each line of input, 
   and to delete entirely blank lines */

#define MAXLINE 1000

int getline(char line[], int maxline);
int remove_trailing(char line[]);

int main() {
    char line[MAXLINE];
    int len;
    
    while ((len = getline(line, MAXLINE)) > 0) {
        if (remove_trailing(line) > 0)  /* if line is not empty after removing trailing */
            printf("%s", line);
    }
    
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim) {
    int c, i;
    
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* remove_trailing: remove trailing blanks and tabs from character string s */
int remove_trailing(char s[]) {
    int i;
    
    /* Find the end of the string */
    for (i = 0; s[i] != '\n' && s[i] != '\0'; ++i)
        ;
    
    /* Go back and remove trailing blanks and tabs */
    for (--i; i >= 0 && (s[i] == ' ' || s[i] == '\t'); --i)
        ;
    
    /* Put back newline and null terminator */
    if (i >= 0) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    
    return i;
} 