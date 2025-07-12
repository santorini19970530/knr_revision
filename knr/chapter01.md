# Chapter 1 - A Tutorial Introduction

## 1.1 Getting Started

- [Hello world](./chapter01/01_01_hello_world.c)

- [Hello world with change line character](./chapter01/01_02_hello_world.c)

## 1.2 Variables and Arithmetic Expressions

- [Fahrenheit and Celsius convertion](./chapter01/01_03_F2C.c)

- [Fahrenheit and Celsius convertion - floating point version](./chapter01/01_04_F2C.c)

* printf formatting

| example | what printf shows                                                |
| :-----: | ---------------------------------------------------------------- |
|   %d    | print as decimal integer                                         |
|   %6d   | print as decimal integer, at least 6 characters wide             |
|   %f    | print as floating point                                          |
|   %6f   | print as floating point, at least 6 characters wide              |
|  %.2f   | print as floating point, 2 characters after decimal point        |
|  %6.2f  | print as floating point, at least 6wide and 2after decimal point |
|   %o    | octal number                                                     |
|   %x    | hexadesimal number                                               |
|   %c    | character                                                        |
|   %s    | character string                                                 |
|   %%    | % itself                                                         |

- [Exercise 1.3 - Fahrenheit and Celsius convertion - floating point with heading version](./chapter01/01_05_F2C.c)

- [Exercise 1.4 - Celsius and Fahrenheit convertion](./chapter01/01_06_C2F.c)

## 1.3 The **_For_** Statement

- [Fahrenheit and Celsius convertion](./chapter01/01_07_F2C.c)

- [Exercise 1.5 - Fahrenheit and Celsius convertion(reversed)](./chapter01/01_08_F2C.c)

## 1.4 Symbolic Constraints

- [Fahrenheit and Celsius convertion (with symbolic name)](./chapter01/01_08_F2C.c)

## 1.5 Character Input and Output

### 1.5.1 File Copying

- using `getchar()` and `putchar()` to write anything about input and output

```pseudocode

read a character

while (character is not end-of-file indicator)
    output the character just read
    read a character

```

- [Copy input to output](./chapter01/01_10_input2output.c)

- [Copy input to output (simplified)](./chapter01/01_11_input2output.c)

- [Exercise 1.6 - print the condition value](./chapter01/01_12_validateTF.c)

- [Exercise 1.7 - print the EOF value](./chapter01/01_13_EOF_value.c)

### 1.5.2 Character Counting
