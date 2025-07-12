#include <stdio.h>

/* Exercise 1-17: Write a program to print all input lines that are longer than 80 characters */

#define MAXLINE 1000
#define MINLENGTH 80

int getline(char line[], int maxline);

int main() {
    char line[MAXLINE];
    int len;
    
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > MINLENGTH) {
            printf("%s", line);
        }
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