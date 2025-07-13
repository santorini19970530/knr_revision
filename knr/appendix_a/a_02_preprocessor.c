/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise A.2 - Preprocessor implementation */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 1000
#define MAXDEF 100

struct definition {
    char *name;
    char *defn;
};

struct definition defs[MAXDEF];
int ndefs = 0;

int getline(char *line, int max);
void process_line(char *line);
void define_macro(char *name, char *defn);
char *lookup_macro(char *name);
void expand_macro(char *line, char *name, char *defn);

int getline(char *line, int max) {
    int c, i;
    
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

void define_macro(char *name, char *defn) {
    if (ndefs >= MAXDEF) {
        printf("Too many definitions\n");
        return;
    }
    defs[ndefs].name = strdup(name);
    defs[ndefs].defn = strdup(defn);
    ndefs++;
}

char *lookup_macro(char *name) {
    for (int i = 0; i < ndefs; i++) {
        if (strcmp(defs[i].name, name) == 0)
            return defs[i].defn;
    }
    return NULL;
}

void expand_macro(char *line, char *name, char *defn) {
    char *p = strstr(line, name);
    if (p) {
        char temp[MAXLINE];
        strcpy(temp, p + strlen(name));
        strcpy(p, defn);
        strcat(line, temp);
    }
}

void process_line(char *line) {
    char *p = line;
    
    /* Skip leading whitespace */
    while (isspace(*p))
        p++;
    
    /* Check for #define */
    if (strncmp(p, "#define", 7) == 0) {
        p += 7;
        while (isspace(*p))
            p++;
        
        char name[100], defn[100];
        int i = 0;
        while (isalnum(*p) || *p == '_') {
            name[i++] = *p++;
        }
        name[i] = '\0';
        
        while (isspace(*p))
            p++;
        
        i = 0;
        while (*p && *p != '\n') {
            defn[i++] = *p++;
        }
        defn[i] = '\0';
        
        define_macro(name, defn);
        printf("Defined: %s -> %s\n", name, defn);
        return;
    }
    
    /* Expand macros in the line */
    for (int i = 0; i < ndefs; i++) {
        expand_macro(line, defs[i].name, defs[i].defn);
    }
    
    printf("%s", line);
}

int main() {
    char line[MAXLINE];
    
    printf("Simple C preprocessor\n");
    printf("Supports #define and macro expansion\n");
    printf("Type 'quit' to exit\n\n");
    
    while (getline(line, MAXLINE) > 0) {
        if (strncmp(line, "quit", 4) == 0)
            break;
        process_line(line);
    }
    
    return 0;
} 