/*
 * Exercise 7.6 - Compare files
 * 
 * Write a program to compare two files, printing the first
 * line where they differ.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline(char *line, int max);

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char line1[MAXLINE], line2[MAXLINE];
    int lineno = 0;
    
    if (argc != 3) {
        printf("Usage: %s file1 file2\n", argv[0]);
        return 1;
    }
    
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open %s\n", argv[1]);
        return 1;
    }
    
    if ((fp2 = fopen(argv[2], "r")) == NULL) {
        printf("Cannot open %s\n", argv[2]);
        fclose(fp1);
        return 1;
    }
    
    printf("Comparing %s and %s:\n\n", argv[1], argv[2]);
    
    while (fgets(line1, MAXLINE, fp1) != NULL) {
        lineno++;
        
        if (fgets(line2, MAXLINE, fp2) == NULL) {
            printf("Files differ at line %d: %s has more lines\n", 
                   lineno, argv[1]);
            break;
        }
        
        if (strcmp(line1, line2) != 0) {
            printf("Files differ at line %d:\n", lineno);
            printf("< %s", line1);
            printf("> %s", line2);
            break;
        }
    }
    
    if (fgets(line2, MAXLINE, fp2) != NULL) {
        printf("Files differ at line %d: %s has more lines\n", 
               lineno + 1, argv[2]);
    } else if (feof(fp1) && feof(fp2)) {
        printf("Files are identical\n");
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}

int getline(char *line, int max) {
    int c, i;
    
    for (i = 0; i < max-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
} 