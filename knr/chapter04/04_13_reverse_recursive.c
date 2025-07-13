/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 4.13 - Recursive reverse
 * 
 * Write a recursive version of the function reverse(s),
 * which reverses the string s in place.
 */

#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void reverse_recursive(char s[], int left, int right);

int main() {
    char test_strings[][50] = {
        "hello",
        "world",
        "recursion",
        "a",
        "",
        "12345"
    };
    int num_tests = sizeof(test_strings) / sizeof(test_strings[0]);
    
    printf("Recursive reverse function\n\n");
    
    for (int i = 0; i < num_tests; i++) {
        printf("Original: \"%s\"\n", test_strings[i]);
        reverse(test_strings[i]);
        printf("Reversed: \"%s\"\n\n", test_strings[i]);
    }
    
    return 0;
}

/* reverse: reverse string s in place - wrapper function */
void reverse(char s[]) {
    int len = strlen(s);
    if (len > 1) {
        reverse_recursive(s, 0, len - 1);
    }
}

/* reverse_recursive: recursive implementation of reverse */
void reverse_recursive(char s[], int left, int right) {
    if (left >= right) {
        return;
    }
    
    /* Swap characters at left and right positions */
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    
    /* Recursively reverse the middle portion */
    reverse_recursive(s, left + 1, right - 1);
} 