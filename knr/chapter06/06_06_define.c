/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 6.6 - Simple version of #define */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define HASHSIZE 101
#define MAXLINE 1000

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
    unsigned hashval;
    
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

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

void process_line(char *line) {
    char word[MAXLINE];
    char *p = line;
    char output[MAXLINE];
    char *out = output;
    
    while (*p) {
        if (isalpha(*p) || *p == '_') {
            char *word_start = p;
            while (isalnum(*p) || *p == '_')
                p++;
            int len = p - word_start;
            strncpy(word, word_start, len);
            word[len] = '\0';
            
            struct nlist *np = lookup(word);
            if (np != NULL) {
                strcpy(out, np->defn);
                out += strlen(np->defn);
            } else {
                strcpy(out, word);
                out += len;
            }
        } else {
            *out++ = *p++;
        }
    }
    *out = '\0';
    printf("%s", output);
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
    char line[MAXLINE];
    
    /* Install some test macros */
    install("MAX", "100");
    install("MIN", "0");
    install("SIZE", "50");
    
    printf("Simple #define processor\n");
    printf("Type lines with macros (MAX, MIN, SIZE will be expanded):\n");
    printf("Type 'quit' to exit\n");
    
    while (fgets(line, MAXLINE, stdin) != NULL) {
        if (strncmp(line, "quit", 4) == 0)
            break;
        process_line(line);
    }
    
    return 0;
} 