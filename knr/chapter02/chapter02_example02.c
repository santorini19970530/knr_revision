/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.2: Enumeration constants */

#include <stdio.h>

enum boolean { NO, YES };
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t',
               NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
              JUL, AUG, SEP, OCT, NOV, DEC };
/* FEB = 2, MAR = 3, etc. */

int main() {
    enum boolean flag = YES;
    
    printf("Boolean enum:\n");
    printf("NO = %d, YES = %d, flag = %d\n\n", NO, YES, flag);
    
    printf("Escapes enum:\n");
    printf("BELL = %d, BACKSPACE = %d, TAB = %d\n", BELL, BACKSPACE, TAB);
    printf("NEWLINE = %d, VTAB = %d, RETURN = %d\n\n", NEWLINE, VTAB, RETURN);
    
    printf("Months enum:\n");
    printf("JAN = %d, FEB = %d, MAR = %d, APR = %d\n", JAN, FEB, MAR, APR);
    printf("MAY = %d, JUN = %d, JUL = %d, AUG = %d\n", MAY, JUN, JUL, AUG);
    printf("SEP = %d, OCT = %d, NOV = %d, DEC = %d\n", SEP, OCT, NOV, DEC);
    
    return 0;
} 
