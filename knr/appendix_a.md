# Appendix A - Reference Manual

## A.1 Introduction

This appendix is a concise reference manual for the C language as defined by the ANSI standard. The manual is not the standard, but our attempt to convey the essentials of the standard in a smaller space.

## A.2 Lexical Conventions

### A.2.1 Tokens

There are six classes of tokens: identifiers, keywords, constants, string literals, operators, and other separators.

### A.2.2 Comments

Comments are replaced by a single space. Comments do not nest.

```c
/* This is a comment */
// This is also a comment (C99)
```

### A.2.3 Identifiers

An identifier is a sequence of letters and digits. The first character must be a letter; the underscore _ counts as a letter.

```c
valid_identifier
_underscore_start
number123
```

### A.2.4 Keywords

The following identifiers are reserved for use as keywords:

```c
auto        break       case        char        const
continue    default     do          double      else
enum        extern      float       for         goto
if          int         long        register    return
short       signed      sizeof      static      struct
switch      typedef     union       unsigned    void
volatile    while
```

### A.2.5 Constants

#### Integer Constants:
```c
123         /* decimal */
0123        /* octal */
0x123       /* hexadecimal */
123L        /* long */
123U        /* unsigned */
123UL       /* unsigned long */
```

#### Character Constants:
```c
'a'         /* character */
'\n'        /* newline */
'\t'        /* tab */
'\0'        /* null */
'\x1F'      /* hex escape */
'\077'      /* octal escape */
```

#### Floating Constants:
```c
123.456     /* double */
123.456f    /* float */
123.456L    /* long double */
1.23e-4     /* scientific notation */
```

### A.2.6 String Literals

String literals are sequences of characters surrounded by double quotes.

```c
"Hello, World!"
"Line 1\nLine 2"
"Multi-line \
string"
```

- [Exercise A.1 - Lexical analyzer](./appendix_a/a_01_lexer.c)

## A.3 Syntax Notation

The syntax is specified using a notation similar to BNF (Backus-Naur Form):

- `{ }` indicates zero or more repetitions
- `[ ]` indicates optional parts
- `|` indicates alternatives
- `...` indicates repetition

## A.4 Meaning of Identifiers

### A.4.1 Storage Class

Storage classes determine the lifetime and scope of objects:

- `auto` - automatic storage (default for local variables)
- `register` - automatic storage with hint for register allocation
- `static` - static storage with internal linkage
- `extern` - external linkage
- `typedef` - creates type alias

### A.4.2 Basic Types

```c
char        /* character */
int         /* integer */
float       /* single precision floating */
double      /* double precision floating */
void        /* no value */
```

### A.4.3 Derived Types

```c
int *       /* pointer to int */
int [10]    /* array of 10 ints */
int (*)()   /* pointer to function returning int */
struct tag  /* structure */
union tag   /* union */
enum tag    /* enumeration */
```

### A.4.4 Type Qualifiers

```c
const       /* read-only */
volatile    /* may change unexpectedly */
```

## A.5 Objects and Lvalues

An object is a region of storage; an lvalue is an expression referring to an object.

## A.6 Conversions

### A.6.1 Integral Promotion

A `char`, `short`, or `int` bit-field is converted to `int` if it can represent all values of the original type.

### A.6.2 Integral Conversions

When converting between integer types:
- If the destination is unsigned, the value is reduced modulo 2^n
- If the destination is signed and the value cannot be represented, the result is implementation-defined

### A.6.3 Integer and Floating

When converting from integer to floating:
- If the value cannot be represented exactly, the result is the nearest higher or lower representable value

### A.6.4 Floating Types

When converting between floating types:
- If the value cannot be represented exactly, the result is the nearest higher or lower representable value

### A.6.5 Arithmetic Conversions

Many operators cause conversions and yield result types in a similar way:
1. If either operand is `long double`, convert the other to `long double`
2. Otherwise, if either operand is `double`, convert the other to `double`
3. Otherwise, if either operand is `float`, convert the other to `float`
4. Otherwise, convert `char` and `short` to `int`
5. Then, if either operand is `long`, convert the other to `long`

### A.6.6 Pointers and Integers

An expression of integral type may be added to or subtracted from a pointer.

### A.6.7 Void

The (nonexistent) value of a `void` expression may not be used in any way.

### A.6.8 Pointers to Void

Any pointer to an object may be converted to `void *` and back without change.

## A.7 Expressions

### A.7.1 Pointer Conversion

The unary `*` operator means indirection: the expression must be a pointer.

### A.7.2 Primary Expressions

```c
identifier    /* variable or function */
constant     /* literal */
string       /* string literal */
(expression) /* parenthesized expression */
```

### A.7.3 Postfix Expressions

```c
expression[expression]    /* array subscript */
expression(expression-list) /* function call */
expression.identifier     /* structure member */
expression->identifier    /* structure pointer member */
expression++              /* postfix increment */
expression--              /* postfix decrement */
```

### A.7.4 Unary Operators

```c
++expression              /* prefix increment */
--expression              /* prefix decrement */
&expression               /* address of */
*expression               /* indirection */
+expression               /* unary plus */
-expression                /* unary minus */
~expression               /* bitwise complement */
!expression               /* logical negation */
sizeof expression         /* size of object */
sizeof(type-name)         /* size of type */
```

### A.7.5 Casts

```c
(type-name) expression
```

### A.7.6 Multiplicative Operators

```c
expression * expression    /* multiplication */
expression / expression    /* division */
expression % expression    /* remainder */
```

### A.7.7 Additive Operators

```c
expression + expression    /* addition */
expression - expression    /* subtraction */
```

### A.7.8 Shift Operators

```c
expression << expression   /* left shift */
expression >> expression   /* right shift */
```

### A.7.9 Relational Operators

```c
expression < expression    /* less than */
expression > expression    /* greater than */
expression <= expression   /* less than or equal */
expression >= expression   /* greater than or equal */
```

### A.7.10 Equality Operators

```c
expression == expression   /* equal */
expression != expression   /* not equal */
```

### A.7.11 Bitwise AND Operator

```c
expression & expression
```

### A.7.12 Bitwise Exclusive OR Operator

```c
expression ^ expression
```

### A.7.13 Bitwise Inclusive OR Operator

```c
expression | expression
```

### A.7.14 Logical AND Operator

```c
expression && expression
```

### A.7.15 Logical OR Operator

```c
expression || expression
```

### A.7.16 Conditional Operator

```c
expression ? expression : expression
```

### A.7.17 Assignment Expressions

```c
expression = expression
expression *= expression
expression /= expression
expression %= expression
expression += expression
expression -= expression
expression <<= expression
expression >>= expression
expression &= expression
expression ^= expression
expression |= expression
```

### A.7.18 Comma Operator

```c
expression , expression
```

## A.8 Declarations

### A.8.1 Storage Class Specifiers

```c
auto
register
static
extern
typedef
```

### A.8.2 Type Specifiers

```c
void
char
short
int
long
float
double
signed
unsigned
struct-or-union-specifier
enum-specifier
typedef-name
```

### A.8.3 Structure and Union Declarations

```c
struct-or-union identifier { struct-declaration-list }
struct-or-union identifier
```

### A.8.4 Enumerations

```c
enum identifier { enumerator-list }
enum identifier
```

### A.8.5 Declarators

```c
pointer direct-declarator
direct-declarator
```

### A.8.6 Meaning of Declarators

A list of declarators appears after a sequence of type specifiers.

### A.8.7 Initialization

```c
declarator = initializer
```

### A.8.8 Type names

```c
type-specifier abstract-declarator
```

### A.8.9 Typedef

```c
typedef type-specifier declarator
```

### A.8.10 Type Equivalence

Two type declarations are equivalent if they are the same.

- [Exercise A.2 - Preprocessor implementation](./appendix_a/a_02_preprocessor.c)

## A.9 Statements

### A.9.1 Labeled Statements

```c
identifier : statement
case constant-expression : statement
default : statement
```

### A.9.2 Expression Statement

```c
expression ;
```

### A.9.3 Compound Statement

```c
{ declaration-list statement-list }
```

### A.9.4 Selection Statements

```c
if (expression) statement
if (expression) statement else statement
switch (expression) statement
```

### A.9.5 Iteration Statements

```c
while (expression) statement
do statement while (expression) ;
for (expression ; expression ; expression) statement
```

### A.9.6 Jump statements

```c
goto identifier ;
continue ;
break ;
return expression ;
```

## A.10 External Declarations

### A.10.1 Function Definitions

```c
declaration-specifiers declarator declaration-list compound-statement
```

### A.10.2 External Declarations

```c
function-definition
declaration
```

## A.11 Scope and Linkage

### A.11.1 Lexical Scope

The scope of an identifier begins at its declaration.

### A.11.2 Linkage

Within a translation unit, all declarations of the same object or function identifier with internal linkage refer to the same thing.

## A.12 Preprocessing

### A.12.1 Trigraph Sequences

```c
??= #    ??/ \    ??' ^    ??( [    ??) ]    ??! |
??< {    ??> }    ??- ~
```

### A.12.2 Line Splicing

A backslash followed by a newline is deleted.

### A.12.3 Macro Definition and Expansion

```c
#define identifier token-sequence
#define identifier(identifier-list) token-sequence
```

### A.12.4 File Inclusion

```c
#include <filename>
#include "filename"
```

### A.12.5 Conditional Compilation

```c
#if constant-expression
#ifdef identifier
#ifndef identifier
#elif constant-expression
#else
#endif
```

### A.12.6 Line Control

```c
#line constant "filename"
```

### A.12.7 Error Generation

```c
#error token-sequence
```

### A.12.8 Pragmas

```c
#pragma token-sequence
```

### A.12.9 Null directive

```c
#
```

### A.12.10 Predefined names

```c
__LINE__    /* current line number */
__FILE__    /* current file name */
__DATE__    /* compilation date */
__TIME__    /* compilation time */
__STDC__    /* 1 if ANSI conforming */
```

## A.13 Grammar

The complete grammar for the C language as defined by the ANSI standard.

- [Exercise A.3 - Type checker](./appendix_a/a_03_typechecker.c)
- [Exercise A.4 - Expression evaluator](./appendix_a/a_04_evaluator.c)
- [Exercise A.5 - Declaration parser](./appendix_a/a_05_decl_parser.c) 