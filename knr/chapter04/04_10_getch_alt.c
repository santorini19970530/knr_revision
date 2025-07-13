/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 4.10 - Alternative getch implementation
 * 
 * Write an alternative version of getch that uses a different
 * approach for handling pushed-back characters.
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int main() {
    int c;
    
    printf("Alternative getch implementation\n");
    printf("Type some characters, then press Ctrl+D (EOF):\n");
    
    while ((c = getch()) != EOF) {
        if (c == 'a') {
            printf("Pushing back 'a'\n");
            ungetch('a');
        } else {
            putchar(c);
        }
    }
    
    return 0;
}

/* Alternative getch: get a (possibly pushed back) character */
int getch(void) {
    if (bufp > 0) {
        return buf[--bufp];
    } else {
        int c = getchar();
        /* Handle EOF specially */
        if (c == EOF) {
            return EOF;
        }
        return c;
    }
}

/* Alternative ungetch: push character back on input */
void ungetch(int c) {
    if (c == EOF) {
        /* Don't push back EOF */
        return;
    }
    
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
} 