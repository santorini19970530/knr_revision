/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 5.11 - Modify entab and detab
 * 
 * Modify the programs entab and detab (written as exercises
 * in Chapter 1) to accept a list of tab stops as arguments.
 * Use the default tab settings if there are no arguments.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TABSTOP 8

void detab(char *line, int *tabstops, int n);
void entab(char *line, int *tabstops, int n);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int tabstops[MAXLINE];
    int n = 0;
    
    /* Parse tab stop arguments */
    for (int i = 1; i < argc; i++) {
        tabstops[n++] = atoi(argv[i]);
    }
    
    /* Use default tab stops if none provided */
    if (n == 0) {
        for (int i = 0; i < MAXLINE; i++) {
            tabstops[i] = (i + 1) * TABSTOP;
        }
        n = MAXLINE;
    }
    
    printf("Enter lines to process (Ctrl+D to end):\n");
    printf("Lines with spaces will be converted to tabs (entab)\n");
    printf("Lines with tabs will be converted to spaces (detab)\n\n");
    
    while (fgets(line, MAXLINE, stdin) != NULL) {
        printf("Original: %s", line);
        
        /* Apply detab */
        detab(line, tabstops, n);
        printf("After detab: %s", line);
        
        /* Apply entab */
        entab(line, tabstops, n);
        printf("After entab: %s", line);
        printf("\n");
    }
    
    return 0;
}

void detab(char *line, int *tabstops, int n) {
    char temp[MAXLINE];
    int i, j, k, col;
    
    for (i = j = col = 0; line[i] != '\0'; i++) {
        if (line[i] == '\t') {
            /* Find next tab stop */
            int next_tab = TABSTOP;
            for (k = 0; k < n; k++) {
                if (tabstops[k] > col) {
                    next_tab = tabstops[k];
                    break;
                }
            }
            
            /* Insert spaces */
            int spaces = next_tab - col;
            while (spaces-- > 0) {
                temp[j++] = ' ';
                col++;
            }
        } else {
            temp[j++] = line[i];
            if (line[i] == '\n')
                col = 0;
            else
                col++;
        }
    }
    temp[j] = '\0';
    strcpy(line, temp);
}

void entab(char *line, int *tabstops, int n) {
    char temp[MAXLINE];
    int i, j, k, col, spaces;
    
    for (i = j = col = spaces = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ') {
            spaces++;
            col++;
        } else {
            /* Convert accumulated spaces to tabs */
            while (spaces > 0) {
                int next_tab = TABSTOP;
                for (k = 0; k < n; k++) {
                    if (tabstops[k] > col - spaces) {
                        next_tab = tabstops[k];
                        break;
                    }
                }
                
                int tab_spaces = next_tab - (col - spaces);
                if (spaces >= tab_spaces) {
                    temp[j++] = '\t';
                    spaces -= tab_spaces;
                } else {
                    while (spaces-- > 0)
                        temp[j++] = ' ';
                }
            }
            
            temp[j++] = line[i];
            if (line[i] == '\n')
                col = 0;
            else
                col++;
        }
    }
    temp[j] = '\0';
    strcpy(line, temp);
} 