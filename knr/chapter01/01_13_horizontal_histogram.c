#include <stdio.h>

/* Exercise 1-13: Write a program to print a histogram of the lengths of words in its input */

#define MAXWORD 20  /* maximum word length */
#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */

int main() {
    int c, i, nc, state;
    int word_lengths[MAXWORD];  /* array to store word length counts */
    
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
                    ++word_lengths[MAXWORD - 1];  /* count long words in last bucket */
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
    
    /* Print horizontal histogram */
    printf("Word length histogram:\n");
    for (i = 1; i < MAXWORD; ++i) {
        printf("%2d: ", i);
        for (int j = 0; j < word_lengths[i]; ++j)
            printf("*");
        printf("\n");
    }
    
    return 0;
} 
