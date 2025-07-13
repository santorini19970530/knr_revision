/*
 * Exercise 5.12 - Extend entab and detab
 * 
 * Extend entab and detab to accept the shorthand
 * "entab -m +n" to mean tab stops every n columns,
 * starting at column m. Choose convenient (for the user)
 * default behavior.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
#define DEFAULT_TABSTOP 8

void detab_extended(char *line, int *tabstops, int n, int start_col);
void entab_extended(char *line, int *tabstops, int n, int start_col);

int main(int argc, char *argv[]) {
    char line[MAXLINE];
    int tabstops[MAXLINE];
    int n = 0;
    int start_col = 0;
    
    /* Parse arguments */
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            start_col = atoi(argv[i] + 1);
        } else if (argv[i][0] == '+') {
            int tab_interval = atoi(argv[i] + 1);
            for (int j = 0; j < MAXLINE; j++) {
                tabstops[j] = start_col + (j + 1) * tab_interval;
            }
            n = MAXLINE;
        } else {
            tabstops[n++] = atoi(argv[i]);
        }
    }
    
    /* Use default tab stops if none provided */
    if (n == 0) {
        for (int i = 0; i < MAXLINE; i++) {
            tabstops[i] = start_col + (i + 1) * DEFAULT_TABSTOP;
        }
        n = MAXLINE;
    }
    
    printf("Tab stops starting at column %d:\n", start_col);
    for (int i = 0; i < 10; i++) {
        printf("%d ", tabstops[i]);
    }
    printf("...\n\n");
    
    printf("Enter lines to process (Ctrl+D to end):\n");
    
    while (fgets(line, MAXLINE, stdin) != NULL) {
        printf("Original: %s", line);
        
        /* Apply detab */
        detab_extended(line, tabstops, n, start_col);
        printf("After detab: %s", line);
        
        /* Apply entab */
        entab_extended(line, tabstops, n, start_col);
        printf("After entab: %s", line);
        printf("\n");
    }
    
    return 0;
}

void detab_extended(char *line, int *tabstops, int n, int start_col) {
    char temp[MAXLINE];
    int i, j, k, col;
    
    for (i = j = col = 0; line[i] != '\0'; i++) {
        if (line[i] == '\t') {
            /* Find next tab stop */
            int next_tab = start_col + DEFAULT_TABSTOP;
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

void entab_extended(char *line, int *tabstops, int n, int start_col) {
    char temp[MAXLINE];
    int i, j, k, col, spaces;
    
    for (i = j = col = spaces = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ') {
            spaces++;
            col++;
        } else {
            /* Convert accumulated spaces to tabs */
            while (spaces > 0) {
                int next_tab = start_col + DEFAULT_TABSTOP;
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