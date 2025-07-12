/* Exercise A.1 - Lexical analyzer */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS, NUMBER, STRING, CHAR };

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int gettoken(void);
int getch(void);
void ungetch(int);

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
    } else if (isdigit(c)) {
        for (*p++ = c; isdigit(c = getch()); )
            *p++ = c;
        if (c == '.') {
            *p++ = c;
            while (isdigit(c = getch()))
                *p++ = c;
        }
        if (c == 'e' || c == 'E') {
            *p++ = c;
            c = getch();
            if (c == '+' || c == '-') {
                *p++ = c;
                c = getch();
            }
            while (isdigit(c)) {
                *p++ = c;
                c = getch();
            }
        }
        *p = '\0';
        ungetch(c);
        return tokentype = NUMBER;
    } else if (c == '"') {
        for (*p++ = c; (c = getch()) != '"'; )
            *p++ = c;
        *p++ = c;
        *p = '\0';
        return tokentype = STRING;
    } else if (c == '\'') {
        *p++ = c;
        c = getch();
        if (c == '\\') {
            *p++ = c;
            c = getch();
        }
        *p++ = c;
        if ((c = getch()) == '\'')
            *p++ = c;
        else
            ungetch(c);
        *p = '\0';
        return tokentype = CHAR;
    } else
        return tokentype = c;
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
    int type;
    
    printf("Lexical analyzer for C tokens\n");
    printf("Enter C code (EOF to end):\n");
    
    while ((type = gettoken()) != EOF) {
        switch (type) {
            case NAME:
                printf("NAME: %s\n", token);
                break;
            case NUMBER:
                printf("NUMBER: %s\n", token);
                break;
            case STRING:
                printf("STRING: %s\n", token);
                break;
            case CHAR:
                printf("CHAR: %s\n", token);
                break;
            case PARENS:
                printf("PARENS: %s\n", token);
                break;
            case BRACKETS:
                printf("BRACKETS: %s\n", token);
                break;
            default:
                printf("OPERATOR: %c\n", type);
                break;
        }
    }
    
    return 0;
} 