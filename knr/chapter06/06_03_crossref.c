/* Exercise 6.3 - Cross-reference program */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAXLINES 1000

struct tnode {
    char *word;
    int lines[MAXLINES];
    int line_count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);
int line_number = 1;

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, int line) {
    int cond;
    
    if (p == NULL) {
        p = (struct tnode *) malloc(sizeof(struct tnode));
        p->word = strdup(w);
        p->line_count = 0;
        p->lines[p->line_count++] = line;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        /* Check if line number already exists */
        int found = 0;
        for (int i = 0; i < p->line_count; i++) {
            if (p->lines[i] == line) {
                found = 1;
                break;
            }
        }
        if (!found && p->line_count < MAXLINES)
            p->lines[p->line_count++] = line;
    } else if (cond < 0)
        p->left = addtree(p->left, w, line);
    else
        p->right = addtree(p->right, w, line);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%-20s", p->word);
        for (int i = 0; i < p->line_count; i++) {
            printf("%d", p->lines[i]);
            if (i < p->line_count - 1)
                printf(", ");
        }
        printf("\n");
        treeprint(p->right);
    }
}

int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    
    while (isspace(c = getch())) {
        if (c == '\n')
            line_number++;
    }
    
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
    struct tnode *root;
    char word[MAXWORD];
    
    root = NULL;
    printf("Enter text (words will be cross-referenced with line numbers):\n");
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]))
            root = addtree(root, word, line_number);
    }
    printf("\nCross-reference:\n");
    treeprint(root);
    return 0;
} 