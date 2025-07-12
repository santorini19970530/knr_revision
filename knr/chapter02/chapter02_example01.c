/* Chapter 2 Example 1: Enumeration Constants */

#include <stdio.h>

/* Enumeration constants example */
enum boolean { NO, YES };
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t' };

int main() {
    enum boolean flag = YES;
    enum escapes bell = BELL;
    
    printf("NO = %d, YES = %d\n", NO, YES);
    printf("BELL = %d, BACKSPACE = %d, TAB = %d\n", BELL, BACKSPACE, TAB);
    printf("flag = %d\n", flag);
    
    return 0;
} 