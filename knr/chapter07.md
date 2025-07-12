# Chapter 7 - Input and Output

## 7.1 Standard Input and Output

### File Descriptors:
- `stdin` - standard input (file descriptor 0)
- `stdout` - standard output (file descriptor 1)
- `stderr` - standard error (file descriptor 2)

### Character Input/Output:
```c
int getchar(void);     /* returns next character from stdin */
int putchar(int c);    /* writes character c to stdout */
```

### Example - Character Copy:
```c
#include <stdio.h>

int main() {
    int c;
    
    while ((c = getchar()) != EOF)
        putchar(c);
    return 0;
}
```

## 7.2 Formatted Output - printf

### Basic Format Specifiers:
```c
%d    decimal integer
%i    integer (same as %d)
%o    octal integer
%x    hexadecimal integer
%X    hexadecimal integer (uppercase)
%u    unsigned decimal integer
%c    character
%s    string
%f    floating point
%e    scientific notation
%E    scientific notation (uppercase)
%g    shortest of %e or %f
%G    shortest of %E or %f
%p    pointer
%n    number of characters written
%%    percent sign
```

### Field Width and Precision:
```c
%5d    field width of 5 characters
%.3f   precision of 3 decimal places
%5.3f  field width 5, precision 3
%-5d   left-justified in field of 5
%+5d   always show sign
% 5d   space for positive, minus for negative
%#x    show 0x prefix for hexadecimal
%05d   pad with zeros
```

### Example - Formatted Output:
```c
printf("Hello, %s\n", "world");
printf("Integer: %d\n", 42);
printf("Float: %.2f\n", 3.14159);
printf("Hex: %x\n", 255);
printf("Width: %5d\n", 123);
```

## 7.3 Variable-length Argument Lists

### Function with Variable Arguments:
```c
#include <stdarg.h>

void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;
    
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
        case 'd':
            ival = va_arg(ap, int);
            printf("%d", ival);
            break;
        case 'f':
            dval = va_arg(ap, double);
            printf("%f", dval);
            break;
        case 's':
            for (sval = va_arg(ap, char *); *sval; sval++)
                putchar(*sval);
            break;
        default:
            putchar(*p);
            break;
        }
    }
    va_end(ap);
}
```

## 7.4 Formatted Input - Scanf

### Basic Scanf Format Specifiers:
```c
%d    decimal integer
%i    integer (accepts octal, decimal, hex)
%o    octal integer
%x    hexadecimal integer
%u    unsigned decimal integer
%c    character
%s    string
%f    floating point
%e    scientific notation
%g    shortest of %e or %f
%p    pointer
%n    number of characters read
%[    character class
%%    percent sign
```

### Example - Input Processing:
```c
int day, month, year;
char monthname[20];

scanf("%d %s %d", &day, monthname, &year);
scanf("%d/%d/%d", &month, &day, &year);
```

### Custom Input Function:
```c
int getint(int *pn) {
    int c, sign;
    
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
```

## 7.5 File Access

### File Operations:
```c
FILE *fopen(char *name, char *mode);
int fclose(FILE *fp);
int getc(FILE *fp);
int putc(int c, FILE *fp);
```

### File Modes:
```c
"r"    read
"w"    write (truncate)
"a"    append
"r+"   read and write
"w+"   read and write (truncate)
"a+"   read and append
```

### Example - File Copy:
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    void filecopy(FILE *, FILE *);
    
    if (argc == 1)
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                printf("cat: can't open %s\n", *argv);
                return 1;
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
    return 0;
}

void filecopy(FILE *ifp, FILE *ofp) {
    int c;
    
    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}
```

## 7.6 Error Handling - Stderr and Exit

### Error Output:
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(1);
    }
    
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "can't open %s\n", argv[1]);
        exit(1);
    }
    
    /* process file */
    fclose(fp);
    return 0;
}
```

### Exit Status:
```c
exit(0);    /* successful termination */
exit(1);    /* error termination */
```

## 7.7 Line Input and Output

### Line Input Functions:
```c
char *fgets(char *line, int maxline, FILE *fp);
int fputs(char *line, FILE *fp);
```

### Example - Line Copy:
```c
#include <stdio.h>

#define MAXLINE 1000

int getline(char *line, int max, FILE *fp) {
    int c, i;
    
    i = 0;
    while (--max > 0 && (c = getc(fp)) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}

int main() {
    char line[MAXLINE];
    
    while (getline(line, MAXLINE, stdin) > 0)
        fputs(line, stdout);
    return 0;
}
```

## 7.8 Miscellaneous Functions

### 7.8.1 String Operations

### String Functions:
```c
#include <string.h>

char *strcpy(char *s, char *t);
char *strncpy(char *s, char *t, int n);
char *strcat(char *s, char *t);
char *strncat(char *s, char *t, int n);
int strcmp(char *s, char *t);
int strncmp(char *s, char *t, int n);
char *strchr(char *s, int c);
char *strrchr(char *s, int c);
```

### 7.8.2 Character Class Testing and Conversion

### Character Functions:
```c
#include <ctype.h>

int isalpha(int c);
int isupper(int c);
int islower(int c);
int isdigit(int c);
int isalnum(int c);
int isspace(int c);
int ispunct(int c);
int isprint(int c);
int iscntrl(int c);
int isgraph(int c);

int toupper(int c);
int tolower(int c);
```

### 7.8.3 Ungetc

### Push Back Character:
```c
int ungetc(int c, FILE *fp);
```

### Example:
```c
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
```

### 7.8.4 Command Execution

### System Command:
```c
#include <stdlib.h>

int system(char *command);
```

### Example:
```c
system("ls -l");
system("gcc -o program program.c");
```

### 7.8.5 Storage Management

### Memory Management:
```c
#include <stdlib.h>

void *malloc(size_t size);
void *calloc(size_t nobj, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
```

### Example:
```c
char *alloc(int n) {
    char *p;
    
    p = malloc(n);
    if (p == NULL)
        printf("alloc: out of memory\n");
    return p;
}
```

### 7.8.6 Mathematical Functions

### Math Functions:
```c
#include <math.h>

double sin(double x);
double cos(double x);
double atan2(double y, double x);
double exp(double x);
double log(double x);
double pow(double x, double y);
double sqrt(double x);
double fabs(double x);
```

### 7.8.7 Random Number Generation

### Random Numbers:
```c
#include <stdlib.h>

int rand(void);
void srand(unsigned int seed);
```

### Example:
```c
unsigned long int next = 1;

int rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

void srand(unsigned int seed) {
    next = seed;
}
```

## Exercises

- [Exercise 7.1 - Convert to lowercase](./chapter07/07_01_lower.c)
- [Exercise 7.2 - Convert to uppercase](./chapter07/07_02_upper.c)
- [Exercise 7.3 - Minprintf function](./chapter07/07_03_minprintf.c)
- [Exercise 7.4 - Miniscanf function](./chapter07/07_04_miniscanf.c)
- [Exercise 7.5 - Rewrite postfix calculator](./chapter07/07_05_postfix.c)
- [Exercise 7.6 - Compare files](./chapter07/07_06_compare.c)
- [Exercise 7.7 - Pattern matching](./chapter07/07_07_pattern.c)
- [Exercise 7.8 - Print directory](./chapter07/07_08_directory.c)
- [Exercise 7.9 - Functions like isupper](./chapter07/07_09_isupper.c)
- [Exercise 7.10 - Convert to lowercase with conditional](./chapter07/07_10_lower_cond.c) 