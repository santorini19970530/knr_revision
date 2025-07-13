/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 4.7 - Ungetch with single character buffer
 * 
 * Modify ungetch to use a single character buffer instead
 * of an array. This simplifies the implementation but limits
 * the ability to push back multiple characters.
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

static int buf = EOF;  /* single character buffer */

int main() {
    int c;
    
    printf("Type some characters, then press Ctrl+D (EOF):\n");
    
    while ((c = getch()) != EOF) {
        if (c == 'u') {
            printf("Pushing back 'u'\n");
            ungetch('u');
        } else {
            putchar(c);
        }
    }
    
    return 0;
}

/* getch: get a (possibly pushed back) character */
int getch(void) {
    int c;
    
    if (buf != EOF) {
        c = buf;
        buf = EOF;
        return c;
    } else {
        return getchar();
    }
}

/* ungetch: push character back on input */
void ungetch(int c) {
    if (buf != EOF) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
    }
} 