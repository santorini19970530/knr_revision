/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Exercise 1-19: Write a function reverse(s) that reverses the character string s. 
   Use it to write a program that reverses its input a line at a time */

#include <stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void reverse(char s[]);

int main() {
    char line[MAXLINE];
    int len;
    
    while ((len = getline(line, MAXLINE)) > 0) {
        reverse(line);
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

/* reverse: reverse string s in place */
void reverse(char s[]) {
    int i, j;
    char temp;
    
    /* Find the end of the string (excluding newline) */
    for (i = 0; s[i] != '\n' && s[i] != '\0'; ++i)
        ;
    
    /* Reverse the string */
    for (j = 0; j < i/2; ++j) {
        temp = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = temp;
    }
} 
