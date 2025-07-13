/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 6.5 - Undefine macro */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

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

void undef(char *name) {
    struct nlist *np, *prev;
    unsigned hashval = hash(name);
    
    for (np = hashtab[hashval], prev = NULL; np != NULL; prev = np, np = np->next) {
        if (strcmp(name, np->name) == 0) {
            if (prev == NULL)
                hashtab[hashval] = np->next;
            else
                prev->next = np->next;
            free(np->name);
            free(np->defn);
            free(np);
            return;
        }
    }
}

void print_table(void) {
    struct nlist *np;
    int i;
    
    printf("Hash table contents:\n");
    for (i = 0; i < HASHSIZE; i++) {
        for (np = hashtab[i]; np != NULL; np = np->next) {
            printf("%s: %s\n", np->name, np->defn);
        }
    }
}

int main() {
    printf("Testing macro table with undef:\n");
    
    install("MAX", "100");
    install("MIN", "0");
    install("SIZE", "50");
    
    printf("After installing macros:\n");
    print_table();
    
    undef("MIN");
    printf("\nAfter undefining MIN:\n");
    print_table();
    
    undef("MAX");
    printf("\nAfter undefining MAX:\n");
    print_table();
    
    return 0;
} 