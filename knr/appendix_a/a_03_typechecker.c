/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise A.3 - Type checker */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define MAXSYMBOLS 100

enum { NAME, PARENS, BRACKETS, NUMBER, STRING, CHAR };

struct symbol {
    char *name;
    char *type;
    int is_function;
};

struct symbol symbols[MAXSYMBOLS];
int nsymbols = 0;

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int gettoken(void);
void dcl(void);
void dirdcl(void);
void add_symbol(char *name, char *type, int is_function);
struct symbol *lookup_symbol(char *name);
char *get_type(void);

int gettoken(void) {
    int c, getch(void);
    void ungetch(int);
    char *p = token;
    
    while ((c = getch()) == ' ' || c == '\t' || c == '\n')
        ;
    
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}

void add_symbol(char *name, char *type, int is_function) {
    if (nsymbols >= MAXSYMBOLS) {
        printf("Too many symbols\n");
        return;
    }
    symbols[nsymbols].name = strdup(name);
    symbols[nsymbols].type = strdup(type);
    symbols[nsymbols].is_function = is_function;
    nsymbols++;
}

struct symbol *lookup_symbol(char *name) {
    for (int i = 0; i < nsymbols; i++) {
        if (strcmp(symbols[i].name, name) == 0)
            return &symbols[i];
    }
    return NULL;
}

char *get_type(void) {
    char *type = malloc(100);
    strcpy(type, datatype);
    strcat(type, out);
    return type;
}

void dcl(void) {
    int ns;
    
    for (ns = 0; gettoken() == '*'; )
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

void dirdcl(void) {
    int type;
    
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    } else if (tokentype == NAME) {
        strcpy(name, token);
        char *full_type = get_type();
        add_symbol(name, full_type, 0);
        free(full_type);
    } else
        printf("error: expected name or (dcl)\n");
    
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS) {
            strcat(out, " function returning");
            /* Mark as function */
            struct symbol *sym = lookup_symbol(name);
            if (sym)
                sym->is_function = 1;
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
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
    printf("C type checker\n");
    printf("Enter declarations (EOF to end):\n");
    printf("Example: int x\n");
    
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        else
            printf("%s: %s %s\n", name, out, datatype);
    }
    
    printf("\nSymbol table:\n");
    for (int i = 0; i < nsymbols; i++) {
        printf("%s: %s (%s)\n", 
               symbols[i].name, 
               symbols[i].type,
               symbols[i].is_function ? "function" : "variable");
    }
    
    return 0;
} 