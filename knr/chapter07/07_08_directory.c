/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 7.8 - Print directory
 * 
 * Write a program to print a set of files, starting each
 * new one on a new page, with a title and a running page
 * count for each file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
#define LINES_PER_PAGE 50

void print_file(char *filename, int *page_count);

int main(int argc, char *argv[]) {
    int page_count = 1;
    
    if (argc < 2) {
        printf("Usage: %s file1 file2 ...\n", argv[0]);
        return 1;
    }
    
    printf("=== File Printer ===\n\n");
    
    for (int i = 1; i < argc; i++) {
        print_file(argv[i], &page_count);
    }
    
    printf("\n=== End of Files ===\n");
    printf("Total pages: %d\n", page_count - 1);
    
    return 0;
}

void print_file(char *filename, int *page_count) {
    FILE *fp;
    char line[MAXLINE];
    int line_count = 0;
    
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Cannot open %s\n", filename);
        return;
    }
    
    printf("\n");
    printf("========================================\n");
    printf("File: %s\n", filename);
    printf("Page: %d\n", *page_count);
    printf("========================================\n\n");
    
    while (fgets(line, MAXLINE, fp) != NULL) {
        printf("%s", line);
        line_count++;
        
        if (line_count % LINES_PER_PAGE == 0) {
            printf("\n--- Page %d ---\n\n", *page_count);
            (*page_count)++;
        }
    }
    
    if (line_count % LINES_PER_PAGE != 0) {
        printf("\n--- End of Page %d ---\n", *page_count);
        (*page_count)++;
    }
    
    fclose(fp);
} 