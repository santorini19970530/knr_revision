# Chapter 5 - Pointers and Arrays

## 5.1 Pointers and Addresses

### Pointer Declaration:
```c
int *p;  /* p is a pointer to int */
```

### Address Operator:
```c
p = &c;  /* p now points to c */
```

### Dereferencing:
```c
*p = 0;  /* set c to 0 */
```

### Example:
```c
int x = 1, y = 2, z[10];
int *ip;  /* ip is a pointer to int */

ip = &x;  /* ip now points to x */
y = *ip;  /* y is now 1 */
*ip = 0;  /* x is now 0 */
ip = &z[0];  /* ip now points to z[0] */
```

## 5.2 Pointers and Function Arguments

### Call by Reference:
```c
void swap(int *px, int *py) {
    int temp;
    
    temp = *px;
    *px = *py;
    *py = temp;
}
```

### Usage:
```c
swap(&a, &b);
```

- [Exercise 5.1 - getint with pointer](./chapter05/05_01_getint.c)
- [Exercise 5.2 - getfloat function](./chapter05/05_02_getfloat.c)

## 5.3 Pointers and Arrays

### Array Name as Pointer:
```c
int a[10];
int *pa;
pa = &a[0];  /* pa points to element 0 of a */
pa = a;       /* same as pa = &a[0] */
```

### Pointer Arithmetic:
```c
pa + 1;      /* points to next element */
*(pa + 1);   /* contents of next element */
pa[i];       /* same as *(pa + i) */
```

### Example:
```c
int strlen(char *s) {
    int n;
    
    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
```

## 5.4 Address Arithmetic

### Pointer Subtraction:
```c
int *p, *q;
p = &a[5];
q = &a[1];
p - q;  /* number of elements between p and q */
```

### Pointer Comparison:
```c
p < q;  /* true if p points to earlier element than q */
```

## 5.5 Character Pointers and Functions

### String Constants:
```c
char *pmessage;
pmessage = "now is the time";  /* pmessage points to the array */
```

### String Copy Function:
```c
void strcpy(char *s, char *t) {
    int i;
    
    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}
```

### Pointer Version:
```c
void strcpy(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}
```

### Compact Version:
```c
void strcpy(char *s, char *t) {
    while (*s++ = *t++)
        ;
}
```

- [Exercise 5.3 - strcat with pointers](./chapter05/05_03_strcat.c)
- [Exercise 5.4 - strend function](./chapter05/05_04_strend.c)
- [Exercise 5.5 - strncpy, strncat, strncmp](./chapter05/05_05_strn_functions.c)

## 5.6 Pointer Arrays; Pointers to Pointers

### Array of Pointers:
```c
char *lineptr[MAXLINES];
```

### Example - Sort Lines:
```c
void qsort(char *lineptr[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);
    
    if (left >= right)
        return;
    swap(lineptr, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, ++last, i);
    swap(lineptr, left, last);
    qsort(lineptr, left, last-1);
    qsort(lineptr, last+1, right);
}
```

- [Exercise 5.6 - Rewrite getline with pointers](./chapter05/05_06_getline_pointers.c)
- [Exercise 5.7 - Read lines into array of pointers](./chapter05/05_07_readlines.c)

## 5.7 Multi-dimensional Arrays

### 2D Array Declaration:
```c
int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
```

### Function with 2D Array:
```c
int day_of_year(int year, int month, int day) {
    int i, leap;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}
```

## 5.8 Initialization of Pointer Arrays

### Array of Strings:
```c
char *month_name(int n) {
    static char *name[] = {
        "illegal month",
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };
    
    return (n < 1 || n > 12) ? name[0] : name[n];
}
```

- [Exercise 5.8 - Day of year and month day](./chapter05/05_08_date_functions.c)
- [Exercise 5.9 - Rewrite day functions with pointers](./chapter05/05_09_date_pointers.c)

## 5.9 Pointers vs. Multi-dimensional Arrays

### Array of Arrays:
```c
int a[10][20];  /* true 2D array */
```

### Array of Pointers:
```c
int *b[10];     /* array of 10 pointers to int */
```

### Key Differences:
- `a[3][4]` - accesses element at row 3, column 4
- `b[3][4]` - accesses 4th element of array pointed to by b[3]

## 5.10 Command-line Arguments

### Main Function:
```c
int main(int argc, char *argv[]) {
    int i;
    
    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc-1) ? " " : "");
    printf("\n");
    return 0;
}
```

### Example - Echo Program:
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    printf("\n");
    return 0;
}
```

- [Exercise 5.10 - Reverse Polish calculator with getline](./chapter05/05_10_rpn_getline.c)

## 5.11 Pointers to Functions

### Function Pointer Declaration:
```c
int (*comp)(void *, void *);
```

### Example - Sort with Function Pointer:
```c
void qsort(void *lineptr[], int left, int right,
           int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int i, int j);
    
    if (left >= right)
        return;
    swap(lineptr, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, ++last, i);
    swap(lineptr, left, last);
    qsort(lineptr, left, last-1, comp);
    qsort(lineptr, last+1, right, comp);
}
```

## 5.12 Complicated Declarations

### Declaration Rules:
1. Start with the variable name
2. Read to the right until you hit a closing parenthesis
3. Read to the left until you hit an opening parenthesis
4. Jump out of the parentheses and repeat

### Examples:
```c
int *f();      /* f: function returning pointer to int */
int (*pf)();   /* pf: pointer to function returning int */
char **argv;   /* argv: pointer to pointer to char */
int (*daytab)[13];  /* daytab: pointer to array[13] of int */
void *comp();  /* comp: function returning pointer to void */
```

### Declaration Program:
```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main() {
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
```

- [Exercise 5.11 - Modify entab and detab](./chapter05/05_11_entab_detab.c)
- [Exercise 5.12 - Extend entab and detab](./chapter05/05_12_entab_detab_ext.c)
- [Exercise 5.13 - Tail program](./chapter05/05_13_tail.c)
- [Exercise 5.14 - Reverse sort program](./chapter05/05_14_reverse_sort.c)
- [Exercise 5.15 - Add field-searching to sort](./chapter05/05_15_sort_fields.c)
- [Exercise 5.16 - Add directory sorting](./chapter05/05_16_sort_dir.c)
- [Exercise 5.17 - Add field-searching with memory](./chapter05/05_17_sort_memory.c)
- [Exercise 5.18 - Make dcl recover from errors](./chapter05/05_18_dcl_error.c)
- [Exercise 5.19 - Modify undcl to not add parentheses](./chapter05/05_19_undcl.c)
- [Exercise 5.20 - Expand dcl to handle declarations](./chapter05/05_20_dcl_expand.c) 