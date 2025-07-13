# Chapter 2 - Types, Operators and Expressions

## 2.1 Variable Names

- Variable names can be letters, digits, and underscore
- Must start with a letter or underscore
- Case sensitive
- Keywords cannot be used as names
- No length limit, but only first 31 characters are significant

## 2.2 Data Types and Sizes

### Basic Types:
- `char` - single byte, can hold one character
- `int` - integer, typically 16 or 32 bits
- `short` - short integer
- `long` - long integer
- `float` - single-precision floating point
- `double` - double-precision floating point

### Size Qualifiers:
- `signed` and `unsigned` can be applied to char, int, short, long
- `unsigned` numbers are always positive
- `signed` is the default

- [Exercise 2.1 - Determine ranges of char, short, int, long](./chapter02/02_01_ranges.c)

## 2.3 Constants

### Integer Constants:
- Decimal: 123, 456
- Octal: 0123 (starts with 0)
- Hexadecimal: 0x123 or 0X123

### Character Constants:
- Single quotes: 'A', '1', '\n'
- Escape sequences: `\n`, `\t`, `\b`, `\"`, `\\`

### String Constants:
- Double quotes: "hello"
- Automatically terminated with '\0'

### Enumeration Constants:
- [Example 2.1 - Enumeration constants](./chapter02/chapter02_example01.c)
```c
enum boolean { NO, YES };
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t' };
```

## 2.4 Declarations

### Variable Declarations:
- [Example 2.2 - Variable declarations](./chapter02/chapter02_example02.c)
```c
int lower, upper, step;
char c, line[1000];
```

### Function Declarations:
- [Example 2.3 - Function declaration](./chapter02/chapter02_example03.c)
```c
int power(int m, int n);
```

## 2.5 Arithmetic Operators

### Binary Operators:
- `+` addition
- `-` subtraction
- `*` multiplication
- `/` division
- `%` modulus (remainder)

### Unary Operators:
- `+` unary plus
- `-` unary minus

### Precedence:
- `*`, `/`, `%` have higher precedence than `+`, `-`
- Parentheses can override precedence

## 2.6 Relational and Logical Operators

### Relational Operators:
- `>` greater than
- `>=` greater than or equal
- `<` less than
- `<=` less than or equal
- `==` equal to
- `!=` not equal to

### Logical Operators:
- `&&` logical AND
- `||` logical OR
- `!` logical NOT

### Short-circuit Evaluation:
- `&&` and `||` evaluate left to right
- Stop as soon as truth or falsehood is determined

- [Exercise 2.2 - Loop without && or ||](./chapter02/02_02_loop.c)

## 2.7 Type Conversions

### Automatic Conversions:
- `char` and `short` → `int`
- `float` → `double`
- `int` → `float` or `double`

### Cast Operator:
```c
(double) n
```

### Conversion Rules:
1. If either operand is `long double`, convert other to `long double`
2. Otherwise, if either operand is `double`, convert other to `double`
3. Otherwise, if either operand is `float`, convert other to `float`
4. Otherwise, convert `char` and `short` to `int`
5. Then, if either operand is `long`, convert other to `long`

- [Exercise 2.3 - Hexadecimal to integer conversion](./chapter02/02_03_htoi.c)

## 2.8 Increment and Decrement Operators

### Prefix and Postfix:
- `++n` - increment before use
- `n++` - increment after use
- `--n` - decrement before use
- `n--` - decrement after use

### Examples:
- [Example 2.4 - Increment and decrement operators](./chapter02/chapter02_example04.c)
```c
x = n++;  // x gets old value of n, then n is incremented
x = ++n;  // n is incremented, then x gets new value
```

## 2.9 Bitwise Operators

### Bitwise Operators:
- `&` bitwise AND
- `|` bitwise OR
- `^` bitwise XOR
- `<<` left shift
- `>>` right shift
- `~` bitwise NOT

### Examples:
- [Example 2.5 - Bitwise operators](./chapter02/chapter02_example05.c)
```c
n = n & 0177;  // turn off all bits except the low-order 7
x = x | SET_ON;  // turn on the bits in SET_ON
```

- [Exercise 2.4 - Alternative squeeze function](./chapter02/02_04_squeeze.c)
- [Exercise 2.5 - any function](./chapter02/02_05_any.c)
- [Exercise 2.6 - setbits function](./chapter02/02_06_setbits.c)
- [Exercise 2.7 - invert function](./chapter02/02_07_invert.c)
- [Exercise 2.8 - rightrot function](./chapter02/02_08_rightrot.c)
- [Exercise 2.9 - Fast bitcount](./chapter02/02_09_bitcount.c)

## 2.10 Assignment Operators and Expressions

### Assignment Operators:
- `=` simple assignment
- `+=` add and assign
- `-=` subtract and assign
- `*=` multiply and assign
- `/=` divide and assign
- `%=` modulo and assign
- `<<=` left shift and assign
- `>>=` right shift and assign
- `&=` bitwise AND and assign
- `^=` bitwise XOR and assign
- `|=` bitwise OR and assign

### Examples:
- [Example 2.6 - Assignment operators](./chapter02/chapter02_example06.c)
```c
i += 2;  // same as i = i + 2
x *= y + 1;  // same as x = x * (y + 1)
```

- [Exercise 2.10 - Lower function with conditional](./chapter02/02_10_lower.c)

## 2.11 Conditional Expressions

### Ternary Operator:
```c
expr1 ? expr2 : expr3
```

### Example:
- [Example 2.7 - Conditional expressions](./chapter02/chapter02_example07.c)
```c
z = (a > b) ? a : b;  // z = max(a, b)
```

## 2.12 Precedence and Order of Evaluation

### Operator Precedence (highest to lowest):
1. `()` `[]` `->` `.`
2. `!` `~` `++` `--` `+` `-` `*` `&` `(type)` `sizeof`
3. `*` `/` `%`
4. `+` `-`
5. `<<` `>>`
6. `<` `<=` `>` `>=`
7. `==` `!=`
8. `&`
9. `^`
10. `|`
11. `&&`
12. `||`
13. `?:`
14. `=` `+=` `-=` etc.
15. `,`

### Associativity:
- Most operators are left-associative
- Unary operators and assignment operators are right-associative 