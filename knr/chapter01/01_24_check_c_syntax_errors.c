/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include <stdio.h>

/* Exercise 1-24: Write a program to check a C program for rudimentary syntax errors 
   like unmatched parentheses, brackets and braces */

int main() {
    int c;
    int paren, bracket, brace, quote, comment;
    
    paren = bracket = brace = quote = comment = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == '"' && !comment) {
            quote = !quote;
        } else if (!quote && !comment) {
            if (c == '(') ++paren;
            else if (c == ')') --paren;
            else if (c == '[') ++bracket;
            else if (c == ']') --bracket;
            else if (c == '{') ++brace;
            else if (c == '}') --brace;
            else if (c == '/') {
                int next = getchar();
                if (next == '*') comment = 1;
                else ungetc(next, stdin);
            }
        } else if (comment && c == '*') {
            int next = getchar();
            if (next == '/') comment = 0;
            else ungetc(next, stdin);
        }
    }
    
    /* Check for errors */
    if (paren != 0) printf("Unmatched parentheses: %d\n", paren);
    if (bracket != 0) printf("Unmatched brackets: %d\n", bracket);
    if (brace != 0) printf("Unmatched braces: %d\n", brace);
    if (quote) printf("Unclosed quote\n");
    if (comment) printf("Unclosed comment\n");
    
    if (paren == 0 && bracket == 0 && brace == 0 && !quote && !comment)
        printf("No syntax errors found\n");
    
    return 0;
} 