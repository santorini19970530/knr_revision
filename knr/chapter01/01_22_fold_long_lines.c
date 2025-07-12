#include <stdio.h>

/* Exercise 1-22: Write a program to "fold" long input lines into two or more shorter lines 
   after the last non-blank character that occurs before the n-th column of input */

#define MAXLINE 1000
#define FOLDCOL 80

int getline(char line[], int maxline);
void fold(char line[], int len);

int main() {
    char line[MAXLINE];
    int len;
    
    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > FOLDCOL) {
            fold(line, len);
        } else {
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

/* fold: fold long lines at appropriate points */
void fold(char line[], int len) {
    int i, last_blank;
    
    for (i = 0; i < len; ++i) {
        if (i > 0 && i % FOLDCOL == 0) {
            /* Find last blank before fold point */
            last_blank = i - 1;
            while (last_blank > i - FOLDCOL && line[last_blank] != ' ' && line[last_blank] != '\t')
                --last_blank;
            
            if (last_blank > i - FOLDCOL) {
                /* Fold at blank */
                line[last_blank] = '\n';
                i = last_blank;
            } else {
                /* No blank found, force fold */
                putchar('\n');
            }
        }
        putchar(line[i]);
    }
} 