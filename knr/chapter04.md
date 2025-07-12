# Chapter 4 - Functions and Program Structure

## 4.1 Basics of Functions

### Function Definition:
```c
return-type function-name(parameter declarations) {
    declarations and statements
}
```

### Function Declaration:
```c
int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
```

### Example - Pattern Matching:
```c
#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";  /* pattern to search for */

/* find all lines matching pattern */
int main() {
    char line[MAXLINE];
    int found = 0;
    
    while (getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    return found;
}
```

### Return Statement:
```c
return expression;
```

## 4.2 Functions Returning Non-integers

### Function Returning Double:
```c
double atof(char s[]) {
    double val, power;
    int i, sign;
    
    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}
```

### Function Declaration:
```c
double atof(char s[]);
```

## 4.3 External Variables

### External Variable Declaration:
```c
int sp = 0;           /* next free stack position */
double val[MAXVAL];    /* value stack */
```

### External Variable Definition:
```c
/* in file stack.c */
int sp = 0;
double val[MAXVAL];
```

### External Variable Declaration in Other Files:
```c
/* in file main.c */
extern int sp;
extern double val[];
```

### Example - Stack Operations:
```c
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
```

## 4.4 Scope Rules

### Local Variables:
- Declared inside a function
- Accessible only within that function
- Created when function is called, destroyed when function returns

### External Variables:
- Declared outside any function
- Accessible to all functions in the file
- Exist for the entire program execution

### Static Variables:
```c
static int buf[BUFSIZE];  /* buffer for ungetch */
static int bufp = 0;      /* next free position in buf */
```

## 4.5 Header Files

### Including Header Files:
```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
```

### Custom Header Files:
```c
#include "calc.h"
```

### Header File Example (calc.h):
```c
#define NUMBER '0'

void push(double);
double pop(void);
int getop(char []);
int getch(void);
void ungetch(int);
```

## 4.6 Static Variables

### Static External Variables:
```c
static char buf[BUFSIZE];  /* buffer for ungetch */
static int bufp = 0;       /* next free position in buf */
```

### Static Internal Variables:
```c
int getch(void) {
    static char buf[BUFSIZE];
    static int bufp = 0;
    
    return (bufp > 0) ? buf[--bufp] : getchar();
}
```

## 4.7 Register Variables

### Register Declaration:
```c
register int x;
register char c;
```

### Usage:
- Suggests to compiler that variable should be kept in register
- Only for automatic variables and formal parameters
- Compiler may ignore the suggestion

## 4.8 Block Structure

### Nested Blocks:
```c
if (n > 0) {
    int i;  /* declare a new variable */
    for (i = 0; i < n; i++)
        /* ... */
}
```

### Variable Scope:
- Variables declared in inner blocks hide outer declarations
- Inner variables are accessible only within their block

## 4.9 Initialization

### Array Initialization:
```c
int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
```

### Character Array Initialization:
```c
char pattern[] = "ould";
```

### Structure Initialization:
```c
struct point pt = {320, 200};
```

## 4.10 Recursion

### Recursive Function:
```c
/* printd: print n in decimal */
void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}
```

### Quick Sort Example:
```c
void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);
    
    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}
```

## 4.11 The C Preprocessor

### 4.11.1 File Inclusion

### Include Directives:
```c
#include <filename>  /* system header files */
#include "filename"  /* local header files */
```

### 4.11.2 Macro Substitution

### Simple Macros:
```c
#define name replacement text
#define forever for (;;)
#define max(A, B) ((A) > (B) ? (A) : (B))
```

### Macro with Arguments:
```c
#define max(A, B) ((A) > (B) ? (A) : (B))
```

### Stringizing:
```c
#define dprint(expr) printf(#expr " = %g\n", expr)
```

### Token Concatenation:
```c
#define paste(front, back) front ## back
```

### 4.11.3 Conditional Inclusion

### Conditional Compilation:
```c
#if !defined(HDR)
#define HDR
/* contents of hdr.h go here */
#endif
```

### System-specific Code:
```c
#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif
#include HDR
```

## Exercises

- [Exercise 4.1 - Rightmost occurrence of substring](./chapter04/04_01_strrindex.c)
- [Exercise 4.2 - Extend atof to handle scientific notation](./chapter04/04_02_atof_scientific.c)
- [Exercise 4.3 - Reverse Polish calculator with modulus](./chapter04/04_03_rpn_mod.c)
- [Exercise 4.4 - Add commands to calculator](./chapter04/04_04_calc_commands.c)
- [Exercise 4.5 - Add access to library functions](./chapter04/04_05_library_functions.c)
- [Exercise 4.6 - Add field width support to atof](./chapter04/04_06_atof_width.c)
- [Exercise 4.7 - Ungetch with single character buffer](./chapter04/04_07_ungetch_single.c)
- [Exercise 4.8 - Getch and ungetch with EOF](./chapter04/04_08_getch_eof.c)
- [Exercise 4.9 - Handle pushed-back EOF](./chapter04/04_09_eof_handling.c)
- [Exercise 4.10 - Alternative getch implementation](./chapter04/04_10_getch_alt.c)
- [Exercise 4.11 - Modify getop to use ungetch](./chapter04/04_11_getop_ungetch.c)
- [Exercise 4.12 - Recursive itoa](./chapter04/04_12_itoa_recursive.c)
- [Exercise 4.13 - Recursive reverse](./chapter04/04_13_reverse_recursive.c)
- [Exercise 4.14 - Swap macro](./chapter04/04_14_swap_macro.c) 