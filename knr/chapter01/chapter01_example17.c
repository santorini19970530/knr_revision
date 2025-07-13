/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* example 1-17 - Advanced Text Processing
   This program demonstrates character classification and basic text processing */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void process_line(char line[], int len);

int main() {
    char line[MAXLINE];
    int len;
    
    printf("Enter text (Ctrl+D to end):\n");
    while ((len = getline(line, MAXLINE)) > 0) {
        process_line(line, len);
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

/* process_line: analyze and process a line of text */
void process_line(char line[], int len) {
    int i;
    int chars = 0, digits = 0, spaces = 0, punct = 0;
    
    printf("Original: %s", line);
    printf("Analysis: ");
    
    for (i = 0; i < len && line[i] != '\0'; ++i) {
        if (isalpha(line[i])) {
            chars++;
            printf("A");  /* character */
        } else if (isdigit(line[i])) {
            digits++;
            printf("D");  /* Digit */
        } else if (isspace(line[i])) {
            spaces++;
            printf("S");  /* Space */
        } else if (ispunct(line[i])) {
            punct++;
            printf("P");  /* Punctuation */
        } else {
            printf("?");  /* Other */
        }
    }
    
    printf("\n");
    printf("  Characters: %d, Digits: %d, Spaces: %d, Punctuation: %d\n", 
           chars, digits, spaces, punct);
    printf("  Total length: %d\n\n", len);
} 
