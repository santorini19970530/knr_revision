# Chapter 1 - A Tutorial Introduction

## 1.1 Getting Started

- [Hello world](./chapter01/chapter01_example01.c)

- [Hello world with change line character](./chapter01/chapter01_example02.c)

- [Exercise 1-1 - Run the hello world program](./chapter01/01_01_run_hello_world.c)

- [Exercise 1-2 - Experiment with printf escape sequences](./chapter01/01_02_printf_escape_experiment.c)

## 1.2 Variables and Arithmetic Expressions

- [Fahrenheit and Celsius convertion](./chapter01/chapter01_example03.c)

- [Fahrenheit and Celsius convertion - floating point version](./chapter01/chapter01_example04.c)

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

- [Exercise 1-3 - Fahrenheit and Celsius convertion - floating point with heading version](./chapter01/01_03_f2c_with_heading.c)

- [Exercise 1-4 - Celsius and Fahrenheit convertion](./chapter01/01_04_celsius_to_fahrenheit.c)

## 1.3 The **_For_** Statement

- [Fahrenheit and Celsius convertion](./chapter01/chapter01_example05.c)

- [Exercise 1-5 - Fahrenheit and Celsius convertion(reversed)](./chapter01/01_05_f2c_reversed.c)

## 1.4 Symbolic Constraints

- [Fahrenheit and Celsius convertion (with symbolic name)](./chapter01/chapter01_example06.c)

## 1.5 Character Input and Output

### 1.5.1 File Copying

- using `getchar()` and `putchar()` to write anything about input and output

```pseudocode

read a character

while (character is not end-of-file indicator)
    output the character just read
    read a character

```

To distinguish the end of input from valid data `getchar` needs to return a distinctive value when there is no more input, a value that cannot be confused with any real character.
This value is called EOF, for "end of file".
We must declare c to be a type big enough to hold any value that `getchar` returns.
We cannot use char since c must be big enough to hold EOF in addition to any possible char.
Therefore we use int.

EOF is an integer defined in `<stdio.h>`, but the specific numeric value doesn't matter as long as it is not the same as any char value.
By using the symbolic constant, we are assured that nothing in the program depends on the specific numeric value.

- [Copy input to output](./chapter01/chapter01_example07.c)

- [Copy input to output (simplified)](./chapter01/chapter01_example08.c)

### 1.5.2 Character Counting

- [Character counting](./chapter01/chapter01_example09.c)

It may be possible to cope with even bigger numbers by using a double (double precision float).
We will also use a for statement instead of a while, to illustrate another way to write the loop.

- [Character counting](./chapter01/chapter01_example10.c)

### 1.5.3 Line Counting

- [Line counting](./chapter01/chapter01_example11.c)

### 1.5.4 Word Counting

- [Word counting](./chapter01/chapter01_example12.c)

These cases are likely to uncover bugs related to word boundary detection, off-by-one errors, and edge cases in input handling.

- [Exercise 1-6 - print the condition value](./chapter01/01_06_print_condition_value.c)

- [Exercise 1-7 - print the EOF value](./chapter01/01_07_print_eof_value.c)

- [Exercise 1-8 - Count blanks, tabs, and newlines](./chapter01/01_08_count_blanks_tabs_newlines.c)

- [Exercise 1-9 - Replace multiple blanks with single blank](./chapter01/01_09_replace_multiple_blanks.c)

- [Exercise 1-10 - Make tabs and backspaces visible](./chapter01/01_10_make_tabs_backspaces_visible.c)

**Exercise 1-11** : How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?

Answer:

To thoroughly test the word count program, I would use the following types of input:

- **Empty input:** To check if the program handles no data correctly.
- **Input with only spaces, tabs, or newlines:** To see if it counts words as zero and counts whitespace correctly.
- **Input with words separated by multiple spaces, tabs, or newlines:** To ensure it doesn't count extra words.
- **Input with punctuation and special characters:** To verify only valid word boundaries are counted.
- **Input with very long words or no whitespace at the end:** To check if the last word is counted.
- **Input with non-ASCII or Unicode characters (if supported):** To see how the program handles them.

- [Exercise 1-12 - Print input one word per line](./chapter01/01_12_one_word_per_line.c)

## 1.6 Arrays

- [Array example - digit counting](./chapter01/chapter01_example13.c)

- [Exercise 1-13 - Horizontal word length histogram](./chapter01/01_13_horizontal_histogram.c)

- [Exercise 1-14 - Vertical word length histogram](./chapter01/01_14_vertical_histogram.c)

## 1.7 Functions

- [Function example - power function](./chapter01/chapter01_example14.c)

- [Exercise 1-15 - Temperature conversion with function](./chapter01/01_15_temperature_conversion_function.c)

## 1.8 Arguments - Call by Value

- Functions receive copies of their arguments
- Changes to parameters don't affect the original variables
- Arrays are passed by reference (pointer to first element)

- [Call by value vs call by reference example](./chapter01/chapter01_example15.c)

## 1.9 Character Arrays

- [Character arrays - longest line finder](./chapter01/chapter01_example16.c)

- [Exercise 1-16 - Revise longest-line program for arbitrarily long lines](./chapter01/01_16_revise_longest_line.c)

- [Exercise 1-17 - Print lines longer than 80 characters](./chapter01/01_17_print_long_lines.c)

- [Exercise 1-18 - Remove trailing blanks and tabs](./chapter01/01_18_remove_trailing_blanks.c)

- [Exercise 1-19 - Reverse input lines](./chapter01/01_19_reverse_input_lines.c)

## 1.10 Advanced Text Processing

- [Advanced text processing example](./chapter01/chapter01_example17.c)

- [Exercise 1-20 - Detab program](./chapter01/01_20_detab_program.c)

- [Exercise 1-21 - Entab program](./chapter01/01_21_entab_program.c)

- [Exercise 1-22 - Fold long lines](./chapter01/01_22_fold_long_lines.c)

- [Exercise 1-23 - Remove C comments](./chapter01/01_23_remove_c_comments.c)

- [Exercise 1-24 - Check C syntax errors](./chapter01/01_24_check_c_syntax_errors.c)
