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

**Expected Output (typical values on most systems):**

```
Ranges of data types:

char:
  signed: -128 to 127
  unsigned: 0 to 255

short:
  signed: -32768 to 32767
  unsigned: 0 to 65535

int:
  signed: -2147483648 to 2147483647
  unsigned: 0 to 4294967295

long:
  signed: -9223372036854775808 to 9223372036854775807
  unsigned: 0 to 18446744073709551615

float:
  range: 1.175494e-38 to 3.402823e+38
  precision: 6 digits

double:
  range: 2.225074e-308 to 1.797693e+308
  precision: 15 digits

long double:
  range: 3.362103e-4932 to 1.189731e+4932
  precision: 18 digits
```

_Note: Actual values may vary depending on the system architecture and compiler._

## 2.3 Constants

Constants are values that cannot be changed during program execution. C provides several types of constants with specific syntax and rules.

### Integer Constants:

Integer constants can be written in different number systems:

- **Decimal constants:** 123, 456, -789
  - Can be positive or negative
  - No leading zeros (except 0 itself)
- **Octal constants:** 0123, 0777 (starts with 0)
  - Use digits 0-7 only
  - Common in Unix file permissions (e.g., 0644)
- **Hexadecimal constants:** 0x123, 0XABC, 0xff

  - Use digits 0-9 and letters a-f or A-F
  - Case insensitive for letters
  - Common in bit manipulation and memory addresses

- **Suffixes for type specification:**
  - `L` or `l` for long: 123L, 0x123L
  - `U` or `u` for unsigned: 123U, 0x123U
  - `UL` or `ul` for unsigned long: 123UL

### Character Constants:

Character constants represent single characters:

- **Single quotes:** 'A', '1', 'z', '+'
  - Must be exactly one character
  - Value is the ASCII code of the character
- **Escape sequences:** Special characters with backslash
  - `\n` - newline
  - `\t` - tab
  - `\b` - backspace
  - `\r` - carriage return
  - `\f` - form feed
  - `\a` - alert (bell)
  - `\\` - backslash
  - `\'` - single quote
  - `\"` - double quote
  - `\?` - question mark
  - `\0` - null character
  - `\ooo` - octal escape (1-3 digits)
  - `\xhh` - hexadecimal escape (1-2 digits)

### String Constants (String Literals):

String constants are sequences of characters:

- **Double quotes:** "hello", "C programming"
  - Can contain any character except unescaped double quotes
  - Automatically terminated with null character '\0'
  - Length is number of characters + 1 (for null terminator)
- **Concatenation:** Adjacent string literals are concatenated
  ```c
  "hello" "world"  /* becomes "helloworld" */
  ```
- **Escape sequences:** Same as character constants
  - `\"` for double quote within string
  - `\\` for backslash within string

### Floating-Point Constants:

- **Decimal notation:** 3.14159, -2.5, 1.0
- **Scientific notation:** 1.23e-4, 6.02e23
  - `e` or `E` for exponent
  - Exponent must be integer
- **Suffixes:**
  - `F` or `f` for float: 3.14f
  - `L` or `l` for long double: 3.14L

### String Functions:

- [Example 2.1 - strlen function demonstration](./chapter02/chapter02_example01.c)

### Enumeration Constants:

Enumerations define sets of named integer constants:

- [Example 2.2 - Enumeration constants](./chapter02/chapter02_example02.c)

```c
enum boolean { NO, YES };  /* NO = 0, YES = 1 */
enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t' };
enum months { JAN = 1, FEB, MAR, APR, MAY, JUN,
              JUL, AUG, SEP, OCT, NOV, DEC };
```

**Key points:**

- Values start at 0 unless explicitly assigned
- Subsequent values increment by 1
- Can assign explicit values to any element
- Values must be integer constants
- Enum constants are `int` type
- Scope follows normal C rules

### Constant Expressions:

Expressions that containes only constants. Such expressions can be evaluated during compilation rather than run-time:

- Integer arithmetic: `2 + 3 * 4`

```c
#define MAXLINE 1000
char line[MAXLINE+1];
```

or

```c
#define LEAP 1 /* in leap years */
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];
```

- Character arithmetic: `'A' + 1`
- Sizeof expressions: `sizeof(int)`
- Cast expressions: `(int)3.14`
- Used in array sizes, case labels, initializers

## 2.4 Declarations

### Variable Declarations:

- [Example 2.3 - Variable declarations](./chapter02/chapter02_example03.c)

### Function Declarations:

- [Example 2.4 - Function declaration](./chapter02/chapter02_example04.c)

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

### Examples:

- [Example 2.5 - Increment and decrement operators](./chapter02/chapter02_example05.c)

- check leap years

```c
if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    printf("%d is a leap year\n", year);
else
    printf("%d is not a leap year\n", year);
```

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

### Examples:

- [Example 2.6 - Bitwise operators](./chapter02/chapter02_example06.c)

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

### Examples:

- [Example 2.7 - atoi function demonstration](./chapter02/chapter02_example07.c)

- [Example 2.8 - lower function demonstration](./chapter02/chapter02_example08.c)

- [Example 2.9 - rand and srand demonstration](./chapter02/chapter02_example09.c)

- [Exercise 2.3 - Hexadecimal to integer conversion](./chapter02/02_03_htoi.c)

## 2.8 Increment and Decrement Operators

### Prefix and Postfix:

- `++n` - increment before use
- `n++` - increment after use
- `--n` - decrement before use
- `n--` - decrement after use

### Examples:

- [Example 2.10 - squeeze function demonstration](./chapter02/chapter02_example10.c)

- [Example 2.11 - strcat function demonstration](./chapter02/chapter02_example11.c)

- [Exercise 2.4 - Alternative squeeze function](./chapter02/02_04_squeeze.c)

- [Exercise 2.5 - any function](./chapter02/02_05_any.c)

## 2.9 Bitwise Operators

### Bitwise Operators:

- `&` bitwise AND
- `|` bitwise OR
- `^` bitwise XOR
- `<<` left shift
- `>>` right shift
- `~` bitwise NOT

### Examples:

- [Example 2.12 - getbits function demonstration](./chapter02/chapter02_example12.c)

```c
n = n & 0177;  // turn off all bits except the low-order 7
x = x | SET_ON;  // turn on the bits in SET_ON
```

- [Exercise 2.6 - setbits function](./chapter02/02_06_setbits.c)

- [Exercise 2.7 - invert function](./chapter02/02_07_invert.c)

- [Exercise 2.8 - rightrot function](./chapter02/02_08_rightrot.c)

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

- [Example 2.13 - bitcount function demonstration](./chapter02/chapter02_example13.c)

```c
i += 2;  // same as i = i + 2
x *= y + 1;  // same as x = x * (y + 1)
```

- [Exercise 2.9 - Fast bitcount](./chapter02/02_09_bitcount.c)

## 2.11 Conditional Expressions

### Ternary Operator:

```c
expr1 ? expr2 : expr3
```

### Example:

- [Example 2.14 - Conditional expressions](./chapter02/chapter02_example14.c)

```c
z = (a > b) ? a : b;  // z = max(a, b)
```

- [Exercise 2.10 - Lower function with conditional](./chapter02/02_10_lower.c)

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
