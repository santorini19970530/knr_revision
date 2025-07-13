/*
 * Exercise 7.7 - Pattern matching
 * 
 * Write a program to find lines matching a pattern.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char *line, int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";  /* pattern to search for */

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int found = 0;
    
    /* Use command line argument as pattern if provided */
    if (argc > 1) {
        strcpy(pattern, argv[1]);
    }
    
    printf("Searching for pattern: \"%s\"\n", pattern);
    printf("Enter lines to search (Ctrl+D to end):\n\n");
    
    while (getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    
    printf("\nFound %d lines matching the pattern.\n", found);
    return found;
}

/* getline: get line into s, return length */
int getline(char s[], int lim) {
    int c, i;
    
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
    int i, j, k;
    
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
} 