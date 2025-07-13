/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Exercise 1-2: Experiment to find out what happens when printf's argument string 
   contains \c, where c is some character not listed above */

#include <stdio.h>

int main() {
    printf("Testing escape sequences:\n");
    printf("\\n = newline: hello\\nworld\n");
    printf("\\t = tab: hello\\tworld\n");
    printf("\\b = backspace: hello\\bworld\n");
    printf("\\r = carriage return: hello\\rworld\n");
    printf("\\a = alert (bell): hello\\aworld\n");
    printf("\\v = vertical tab: hello\\vworld\n");
    printf("\\f = form feed: hello\\fworld\n");
    printf("\\? = question mark: hello\\?world\n");
    printf("\\\" = double quote: hello\\\"world\n");
    printf("\\' = single quote: hello\\'world\n");
    printf("\\\\ = backslash: hello\\\\world\n");
    
    /* Test some undefined escape sequences */
    printf("\\c = undefined escape: hello\\cworld\n");
    printf("\\x = undefined escape: hello\\xworld\n");
    printf("\\z = undefined escape: hello\\zworld\n");
    
    return 0;
} 
