/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 7.9 - Functions like isupper
 * 
 * Write functions like isupper which can be implemented to
 * save space or to save time. Explore both possibilities.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h> // Added for strlen

/* Space-efficient version using lookup table */
int isupper_space(char c) {
    static int initialized = 0;
    static int upper_table[256];
    
    if (!initialized) {
        for (int i = 0; i < 256; i++) {
            upper_table[i] = (i >= 'A' && i <= 'Z') ? 1 : 0;
        }
        initialized = 1;
    }
    
    return upper_table[(unsigned char)c];
}

/* Time-efficient version using direct comparison */
int isupper_time(char c) {
    return (c >= 'A' && c <= 'Z');
}

/* Test function to compare implementations */
void test_isupper() {
    char test_chars[] = "Hello World 123 !@#";
    int len = strlen(test_chars);
    
    printf("Testing isupper implementations:\n");
    printf("Character | Space | Time  | Standard\n");
    printf("----------|-------|-------|---------\n");
    
    for (int i = 0; i < len; i++) {
        char c = test_chars[i];
        printf("'%c'       | %s     | %s     | %s\n",
               c,
               isupper_space(c) ? "Yes" : "No",
               isupper_time(c) ? "Yes" : "No",
               isupper(c) ? "Yes" : "No");
    }
}

int main() {
    test_isupper();
    
    printf("\nPerformance comparison:\n");
    printf("- Space-efficient: Uses lookup table, faster for repeated calls\n");
    printf("- Time-efficient: Direct comparison, minimal memory usage\n");
    printf("- Standard: Library implementation, optimized for general use\n");
    
    return 0;
} 