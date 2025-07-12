#include <stdio.h>

/* Exercise 1-14: Write a program to print a vertical histogram of the lengths of words in its input */

#define MAXWORD 20  /* maximum word length */
#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */

int main() {
    int c, i, j, nc, state;
    int word_lengths[MAXWORD];  /* array to store word length counts */
    int max_count = 0;          /* maximum count for scaling */
    
    state = OUT;
    nc = 0;
    
    /* Initialize array */
    for (i = 0; i < MAXWORD; ++i)
        word_lengths[i] = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (nc < MAXWORD)
                    ++word_lengths[nc];
                else
                    ++word_lengths[MAXWORD - 1];
                nc = 0;
            }
            state = OUT;
        } else {
            ++nc;
            state = IN;
        }
    }
    
    /* Handle last word if input doesn't end with whitespace */
    if (state == IN) {
        if (nc < MAXWORD)
            ++word_lengths[nc];
        else
            ++word_lengths[MAXWORD - 1];
    }
    
    /* Find maximum count for scaling */
    for (i = 1; i < MAXWORD; ++i)
        if (word_lengths[i] > max_count)
            max_count = word_lengths[i];
    
    /* Print vertical histogram */
    printf("Vertical word length histogram:\n");
    for (i = max_count; i > 0; --i) {
        for (j = 1; j < MAXWORD; ++j) {
            if (word_lengths[j] >= i)
                printf(" * ");
            else
                printf("   ");
        }
        printf("\n");
    }
    
    /* Print length labels */
    for (j = 1; j < MAXWORD; ++j)
        printf("%2d ", j);
    printf("\n");
    
    return 0;
} 
