/*
 * Exercise 4.8 - Getch and ungetch with EOF
 * 
 * Modify getch and ungetch to handle EOF properly.
 * EOF should not be pushed back, and getch should return
 * EOF when appropriate.
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

#define BUFSIZE 100

static char buf[BUFSIZE];  /* buffer for ungetch */
static int bufp = 0;       /* next free position in buf */

int main() {
    int c;
    
    printf("Type some characters, then press Ctrl+D (EOF):\n");
    
    while ((c = getch()) != EOF) {
        if (c == 'e') {
            printf("Pushing back 'e'\n");
            ungetch('e');
        } else {
            putchar(c);
        }
    }
    
    printf("\nTrying to push back EOF...\n");
    ungetch(EOF);
    
    return 0;
}

/* getch: get a (possibly pushed back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c) {
    if (c == EOF) {
        printf("ungetch: cannot push back EOF\n");
        return;
    }
    
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
} 