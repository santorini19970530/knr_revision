# Appendix B - Standard Library

## B.1 Input and Output: <stdio.h>

### B.1.1 File Operations

#### File Opening and Closing:
```c
FILE *fopen(const char *filename, const char *mode);
int fclose(FILE *stream);
```

#### File Modes:
```c
"r"    /* read */
"w"    /* write (truncate) */
"a"    /* append */
"r+"   /* read and write */
"w+"   /* read and write (truncate) */
"a+"   /* read and append */
"rb"   /* binary read */
"wb"   /* binary write */
"ab"   /* binary append */
```

#### Example:
```c
FILE *fp;
if ((fp = fopen("file.txt", "r")) == NULL) {
    fprintf(stderr, "Cannot open file\n");
    return 1;
}
/* use file */
fclose(fp);
```

### B.1.2 Formatted Output

#### printf Functions:
```c
int printf(const char *format, ...);
int fprintf(FILE *stream, const char *format, ...);
int sprintf(char *s, const char *format, ...);
```

#### Format Specifiers:
```c
%d    /* decimal integer */
%i    /* integer */
%o    /* octal integer */
%x    /* hexadecimal integer */
%X    /* hexadecimal integer (uppercase) */
%u    /* unsigned decimal */
%c    /* character */
%s    /* string */
%f    /* floating point */
%e    /* scientific notation */
%E    /* scientific notation (uppercase) */
%g    /* shortest of %e or %f */
%G    /* shortest of %E or %f */
%p    /* pointer */
%n    /* number of characters written */
%%    /* percent sign */
```

#### Field Width and Precision:
```c
%5d    /* field width of 5 */
%.3f    /* precision of 3 */
%5.3f   /* field width 5, precision 3 */
%-5d    /* left-justified */
%+5d    /* always show sign */
% 5d    /* space for positive */
%#x     /* show 0x prefix */
%05d    /* pad with zeros */
```

#### Example:
```c
printf("Integer: %d\n", 42);
printf("Float: %.2f\n", 3.14159);
printf("Hex: %x\n", 255);
printf("Width: %5d\n", 123);
printf("String: %s\n", "Hello");
```

### B.1.3 Formatted Input

#### scanf Functions:
```c
int scanf(const char *format, ...);
int fscanf(FILE *stream, const char *format, ...);
int sscanf(const char *s, const char *format, ...);
```

#### Format Specifiers:
```c
%d    /* decimal integer */
%i    /* integer (octal, decimal, hex) */
%o    /* octal integer */
%u    /* unsigned decimal */
%x    /* hexadecimal integer */
%c    /* character */
%s    /* string */
%f    /* floating point */
%e    /* scientific notation */
%g    /* shortest of %e or %f */
%p    /* pointer */
%n    /* number of characters read */
%[...] /* character class */
%[^...] /* inverted character class */
%%    /* percent sign */
```

#### Example:
```c
int day, month, year;
char monthname[20];

scanf("%d %s %d", &day, monthname, &year);
scanf("%d/%d/%d", &month, &day, &year);
```

### B.1.4 Character Input and Output Functions

#### Character I/O:
```c
int fgetc(FILE *stream);
int fputc(int c, FILE *stream);
int getc(FILE *stream);
int putc(int c, FILE *stream);
int getchar(void);
int putchar(int c);
```

#### String I/O:
```c
char *fgets(char *s, int n, FILE *stream);
int fputs(const char *s, FILE *stream);
char *gets(char *s);
int puts(const char *s);
```

#### Pushback:
```c
int ungetc(int c, FILE *stream);
```

#### Example:
```c
int c;
while ((c = getchar()) != EOF)
    putchar(c);

char line[100];
while (fgets(line, sizeof(line), stdin) != NULL)
    fputs(line, stdout);
```

### B.1.5 Direct Input and Output Functions

#### Binary I/O:
```c
size_t fread(void *ptr, size_t size, size_t nobj, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nobj, FILE *stream);
```

#### Example:
```c
struct record {
    int id;
    char name[50];
};

struct record rec;
fread(&rec, sizeof(rec), 1, fp);
fwrite(&rec, sizeof(rec), 1, fp);
```

### B.1.6 File Positioning Functions

#### File Positioning:
```c
int fseek(FILE *stream, long offset, int origin);
long ftell(FILE *stream);
void rewind(FILE *stream);
int fgetpos(FILE *stream, fpos_t *ptr);
int fsetpos(FILE *stream, const fpos_t *ptr);
```

#### Origins:
```c
SEEK_SET    /* beginning of file */
SEEK_CUR    /* current position */
SEEK_END    /* end of file */
```

#### Example:
```c
FILE *fp = fopen("file.txt", "r");
fseek(fp, 10L, SEEK_SET);  /* seek to position 10 */
long pos = ftell(fp);       /* get current position */
rewind(fp);                 /* go to beginning */
```

### B.1.7 Error Functions

#### Error Handling:
```c
void clearerr(FILE *stream);
int feof(FILE *stream);
int ferror(FILE *stream);
void perror(const char *s);
```

#### Example:
```c
FILE *fp = fopen("nonexistent.txt", "r");
if (fp == NULL) {
    perror("fopen");
    return 1;
}

while ((c = fgetc(fp)) != EOF) {
    if (ferror(fp)) {
        fprintf(stderr, "Read error\n");
        clearerr(fp);
        break;
    }
    if (feof(fp)) {
        printf("End of file\n");
        break;
    }
}
```

## B.2 Character Class Tests: <ctype.h>

### Character Classification:
```c
int isalnum(int c);   /* alphanumeric */
int isalpha(int c);   /* alphabetic */
int iscntrl(int c);   /* control character */
int isdigit(int c);   /* decimal digit */
int isgraph(int c);   /* printing character except space */
int islower(int c);   /* lower-case letter */
int isprint(int c);   /* printing character including space */
int ispunct(int c);   /* printing character except space or letter or digit */
int isspace(int c);   /* space, formfeed, newline, carriage return, tab, vertical tab */
int isupper(int c);   /* upper-case letter */
int isxdigit(int c);  /* hexadecimal digit */
```

### Character Conversion:
```c
int tolower(int c);   /* convert to lower case */
int toupper(int c);   /* convert to upper case */
```

#### Example:
```c
int c;
while ((c = getchar()) != EOF) {
    if (isalpha(c)) {
        if (isupper(c))
            putchar(tolower(c));
        else
            putchar(toupper(c));
    } else {
        putchar(c);
    }
}
```

## B.3 String Functions: <string.h>

### String Copying:
```c
char *strcpy(char *s, const char *t);
char *strncpy(char *s, const char *t, size_t n);
char *strcat(char *s, const char *t);
char *strncat(char *s, const char *t, size_t n);
```

### String Comparison:
```c
int strcmp(const char *s, const char *t);
int strncmp(const char *s, const char *t, size_t n);
```

### String Length:
```c
size_t strlen(const char *s);
```

### String Search:
```c
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
char *strstr(const char *s, const char *t);
char *strpbrk(const char *s, const char *t);
char *strtok(char *s, const char *delim);
```

### Memory Operations:
```c
void *memcpy(void *s, const void *t, size_t n);
void *memmove(void *s, const void *t, size_t n);
int memcmp(const void *s, const void *t, size_t n);
void *memchr(const void *s, int c, size_t n);
void *memset(void *s, int c, size_t n);
```

#### Example:
```c
char s[100];
strcpy(s, "Hello");
strcat(s, " World");
printf("Length: %zu\n", strlen(s));
printf("String: %s\n", s);

if (strcmp(s, "Hello World") == 0)
    printf("Strings are equal\n");

char *p = strchr(s, 'o');
if (p)
    printf("Found 'o' at position %ld\n", p - s);
```

## B.4 Mathematical Functions: <math.h>

### Trigonometric Functions:
```c
double sin(double x);
double cos(double x);
double tan(double x);
double asin(double x);
double acos(double x);
double atan(double x);
double atan2(double y, double x);
```

### Hyperbolic Functions:
```c
double sinh(double x);
double cosh(double x);
double tanh(double x);
```

### Exponential and Logarithmic Functions:
```c
double exp(double x);
double log(double x);
double log10(double x);
double pow(double x, double y);
double sqrt(double x);
```

### Other Mathematical Functions:
```c
double ceil(double x);
double floor(double x);
double fabs(double x);
double fmod(double x, double y);
double ldexp(double x, int n);
double frexp(double x, int *exp);
double modf(double x, double *ip);
```

#### Example:
```c
#include <math.h>

double x = 3.14159;
printf("sin(x) = %f\n", sin(x));
printf("cos(x) = %f\n", cos(x));
printf("sqrt(x) = %f\n", sqrt(x));
printf("pow(x, 2) = %f\n", pow(x, 2));
printf("ceil(x) = %f\n", ceil(x));
printf("floor(x) = %f\n", floor(x));
```

## B.5 Utility Functions: <stdlib.h>

### Memory Management:
```c
void *malloc(size_t size);
void *calloc(size_t nobj, size_t size);
void *realloc(void *ptr, size_t size);
void free(void *ptr);
```

### String Conversion:
```c
int atoi(const char *s);
long atol(const char *s);
double atof(const char *s);
```

### Random Numbers:
```c
int rand(void);
void srand(unsigned int seed);
```

### Environment:
```c
void abort(void);
void exit(int status);
int system(const char *s);
char *getenv(const char *name);
```

### Search and Sort:
```c
void *bsearch(const void *key, const void *base, size_t n, size_t size, int (*cmp)(const void *, const void *));
void qsort(void *base, size_t n, size_t size, int (*cmp)(const void *, const void *));
```

#### Example:
```c
#include <stdlib.h>

/* Memory allocation */
int *p = malloc(10 * sizeof(int));
if (p == NULL) {
    fprintf(stderr, "Out of memory\n");
    exit(1);
}
free(p);

/* String conversion */
int n = atoi("123");
double x = atof("3.14159");

/* Random numbers */
srand(time(NULL));
int r = rand() % 100;

/* Environment */
char *path = getenv("PATH");
if (path)
    printf("PATH: %s\n", path);

/* Sort */
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int arr[] = {3, 1, 4, 1, 5, 9};
qsort(arr, 6, sizeof(int), compare);
```

## B.6 Diagnostics: <assert.h>

### Assertions:
```c
void assert(int expression);
```

#### Example:
```c
#include <assert.h>

int factorial(int n) {
    assert(n >= 0);  /* check precondition */
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}
```

## B.7 Variable Argument Lists: <stdarg.h>

### Variable Arguments:
```c
void va_start(va_list ap, last);
type va_arg(va_list ap, type);
void va_end(va_list ap);
```

#### Example:
```c
#include <stdarg.h>

int sum(int n, ...) {
    va_list ap;
    int sum = 0;
    
    va_start(ap, n);
    for (int i = 0; i < n; i++)
        sum += va_arg(ap, int);
    va_end(ap);
    
    return sum;
}

int result = sum(3, 1, 2, 3);  /* returns 6 */
```

## B.8 Non-local Jumps: <setjmp.h>

### Non-local Jumps:
```c
int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val);
```

#### Example:
```c
#include <setjmp.h>

jmp_buf env;

void function() {
    if (setjmp(env) == 0) {
        printf("First call\n");
        longjmp(env, 1);
    } else {
        printf("Returned via longjmp\n");
    }
}
```

## B.9 Signals: <signal.h>

### Signal Handling:
```c
void (*signal(int sig, void (*handler)(int)))(int);
int raise(int sig);
```

#### Example:
```c
#include <signal.h>

void handler(int sig) {
    printf("Received signal %d\n", sig);
    exit(1);
}

signal(SIGINT, handler);  /* handle Ctrl-C */
```

## B.10 Date and Time Functions: <time.h>

### Time Functions:
```c
time_t time(time_t *tp);
char *ctime(const time_t *tp);
struct tm *gmtime(const time_t *tp);
struct tm *localtime(const time_t *tp);
char *asctime(const struct tm *tp);
size_t strftime(char *s, size_t smax, const char *format, const struct tm *tp);
```

#### Example:
```c
#include <time.h>

time_t now = time(NULL);
printf("Current time: %s", ctime(&now));

struct tm *tm = localtime(&now);
printf("Year: %d\n", tm->tm_year + 1900);
printf("Month: %d\n", tm->tm_mon + 1);
printf("Day: %d\n", tm->tm_mday);
```

## B.11 Implementation-defined Limits: <limits.h> and <float.h>

### Integer Limits:
```c
CHAR_BIT    /* bits in char */
CHAR_MAX    /* maximum char value */
CHAR_MIN    /* minimum char value */
INT_MAX     /* maximum int value */
INT_MIN     /* minimum int value */
LONG_MAX    /* maximum long value */
LONG_MIN    /* minimum long value */
SCHAR_MAX   /* maximum signed char value */
SCHAR_MIN   /* minimum signed char value */
SHRT_MAX    /* maximum short value */
SHRT_MIN    /* minimum short value */
UCHAR_MAX   /* maximum unsigned char value */
UINT_MAX    /* maximum unsigned int value */
ULONG_MAX   /* maximum unsigned long value */
USHRT_MAX   /* maximum unsigned short value */
```

### Floating Point Limits:
```c
FLT_RADIX      /* radix of exponent representation */
FLT_ROUNDS     /* rounding mode */
FLT_DIG        /* decimal digits of precision */
FLT_EPSILON    /* smallest number such that 1.0 + x != 1.0 */
FLT_MANT_DIG   /* number of base FLT_RADIX digits in mantissa */
FLT_MAX        /* maximum float value */
FLT_MIN        /* minimum normalized float value */
FLT_MAX_EXP    /* maximum exponent */
FLT_MIN_EXP    /* minimum exponent */
```

#### Example:
```c
#include <limits.h>
#include <float.h>

printf("INT_MAX = %d\n", INT_MAX);
printf("INT_MIN = %d\n", INT_MIN);
printf("FLT_MAX = %e\n", FLT_MAX);
printf("FLT_MIN = %e\n", FLT_MIN);
printf("FLT_DIG = %d\n", FLT_DIG);
```

## Exercises

- [Exercise B.1 - Custom printf implementation](./appendix_b/b_01_printf.c)
- [Exercise B.2 - Custom scanf implementation](./appendix_b/b_02_scanf.c)
- [Exercise B.3 - String library functions](./appendix_b/b_03_strings.c)
- [Exercise B.4 - Math library functions](./appendix_b/b_04_math.c)
- [Exercise B.5 - Memory allocator](./appendix_b/b_05_malloc.c)
- [Exercise B.6 - Date/time utilities](./appendix_b/b_06_time.c)
- [Exercise B.7 - Signal handlers](./appendix_b/b_07_signals.c)
- [Exercise B.8 - File utilities](./appendix_b/b_08_files.c) 