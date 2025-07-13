# Chapter 3 - Control Flow

## 3.1 Statements and Blocks

### Expression Statements:
```c
x = 0;
i++;
printf("...");
```

### Compound Statements (Blocks):
```c
{
    int x = 1;
    int y = 2;
    printf("%d %d\n", x, y);
}
```

## 3.2 If-Else

### Basic If Statement:
```c
if (expression)
    statement
```

### If-Else Statement:
```c
if (expression)
    statement1
else
    statement2
```

### Examples:
```c
if (n > 0)
    printf("positive\n");
else if (n < 0)
    printf("negative\n");
else
    printf("zero\n");
```

## 3.3 Else-If

### Multi-way Decision:
```c
if (expression1)
    statement1
else if (expression2)
    statement2
else if (expression3)
    statement3
else
    statement4
```

### Example - Binary Search:
```c
if (x < v[mid])
    high = mid - 1;
else if (x > v[mid])
    low = mid + 1;
else
    return mid;  /* found match */
```

- [Exercise 3.1 - Binary search with one test inside loop](./chapter03/03_01_binary_search.c)

## 3.4 Switch

### Switch Statement:
```c
switch (expression) {
    case const-expr: statements
    case const-expr: statements
    default: statements
}
```

### Example:
```c
switch (c) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        ndigit[c-'0']++;
        break;
    case ' ':
    case '\n':
    case '\t':
        nwhite++;
        break;
    default:
        nother++;
        break;
}
```

### Important Notes:
- `break` is needed to exit switch
- Without `break`, execution falls through to next case
- `default` is optional
- Expression must be integer type

- [Exercise 3.2 - Escape sequence conversion](./chapter03/03_02_escape.c)
- [Exercise 3.3 - Expand shorthand notation](./chapter03/03_03_expand.c)

## 3.5 Loops - While and For

### While Loop:
```c
while (expression)
    statement
```

### For Loop:
```c
for (expr1; expr2; expr3)
    statement
```

### Equivalent While Loop:
```c
expr1;
while (expr2) {
    statement
    expr3;
}
```

### Examples:
```c
/* Count characters */
while ((c = getchar()) != EOF)
    ++nc;

/* Fahrenheit to Celsius table */
for (fahr = 0; fahr <= 300; fahr = fahr + 20)
    printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
```

## 3.6 Loops - Do-While

### Do-While Loop:
```c
do
    statement
while (expression);
```

### Characteristics:
- Body is executed at least once
- Test is made at the bottom
- Useful when you want to execute body at least once

### Example:
```c
do {
    n = getchar();
    /* process n */
} while (n != EOF);
```

- [Exercise 3.4 - itoa function](./chapter03/03_04_itoa.c)
- [Exercise 3.5 - itob function](./chapter03/03_05_itob.c)
- [Exercise 3.6 - Add field width support to itoa](./chapter03/03_06_itoa_width.c)

## 3.7 Break and Continue

### Break Statement:
- Exits the innermost enclosing loop or switch
- Cannot break out of multiple nested loops

### Continue Statement:
- Skips to the end of the loop body
- Continues with the next iteration
- Only applies to loops, not switch

### Examples:
```c
/* Skip negative elements */
for (i = 0; i < n; i++) {
    if (a[i] < 0)
        continue;
    /* process positive elements */
}

/* Exit loop when condition met */
while ((c = getchar()) != EOF) {
    if (c == '\n')
        break;
    /* process character */
}
```

## 3.8 Goto and Labels

### Goto Statement:
```c
goto label;
```

### Label:
```c
label: statement
```

### Usage:
- Rarely needed
- Can be used to break out of deeply nested loops
- Should be used sparingly

### Example:
```c
for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
        if (a[i] == b[j])
            goto found;
/* didn't find any common element */
found:
/* got one: a[i] == b[j] */
```

### Alternative without goto:
```c
found = 0;
for (i = 0; i < n && !found; i++)
    for (j = 0; j < m && !found; j++)
        if (a[i] == b[j])
            found = 1;
``` 