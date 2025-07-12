/* Exercise 6.4 - Print tree in order */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
char *strdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
    
    if (p == NULL) {
        p = (struct tnode *) malloc(sizeof(struct tnode));
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

char *strdup(char *s) {
    char *p;
    
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

int main() {
    struct tnode *root;
    char word[100];
    
    root = NULL;
    printf("Enter words (EOF to end):\n");
    while (scanf("%s", word) == 1) {
        root = addtree(root, word);
    }
    printf("\nWord frequency (in alphabetical order):\n");
    treeprint(root);
    return 0;
} 