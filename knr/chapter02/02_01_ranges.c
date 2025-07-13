/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Exercise 2.1: Write a program to determine the ranges of char, short, int, and long
   variables, both signed and unsigned, by printing appropriate values from standard headers
   and by direct computation. Harder if you compute them: determine the ranges of the various
   floating-point types. */

int main() {
    printf("Ranges of data types:\n\n");
    
    /* Character types */
    printf("char:\n");
    printf("  signed: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("  unsigned: 0 to %u\n\n", UCHAR_MAX);
    
    /* Short integer types */
    printf("short:\n");
    printf("  signed: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("  unsigned: 0 to %u\n\n", USHRT_MAX);
    
    /* Integer types */
    printf("int:\n");
    printf("  signed: %d to %d\n", INT_MIN, INT_MAX);
    printf("  unsigned: 0 to %u\n\n", UINT_MAX);
    
    /* Long integer types */
    printf("long:\n");
    printf("  signed: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("  unsigned: 0 to %lu\n\n", ULONG_MAX);
    
    /* Floating point types */
    printf("float:\n");
    printf("  range: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("  precision: %d digits\n\n", FLT_DIG);
    
    printf("double:\n");
    printf("  range: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("  precision: %d digits\n\n", DBL_DIG);
    
    printf("long double:\n");
    printf("  range: %Le to %Le\n", LDBL_MIN, LDBL_MAX);
    printf("  precision: %d digits\n\n", LDBL_DIG);
    
    return 0;
} 