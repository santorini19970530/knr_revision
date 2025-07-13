/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 6.1 - getword function */

#include <stdio.h>
#include <ctype.h>

/* Our version of getword does not properly handle underscores, string constants,
   comments, or preprocessor control lines. Write a better version. */

#define MAXWORD 100

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    
    while (isspace(c = getch()))
        ;
    
    if (c != EOF)
        *w++ = c;
    
    if (!isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }
    
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch()) && *w != '_') {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int main() {
    char word[MAXWORD];
    int c;
    
    printf("Enter words (alphanumeric and underscores):\n");
    while ((c = getword(word, MAXWORD)) != EOF) {
        if (isalpha(word[0]) || word[0] == '_')
            printf("Word: %s\n", word);
        else if (c != ' ' && c != '\n' && c != '\t')
            printf("Non-word: %c\n", c);
    }
    
    return 0;
} 