/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 3.2 - Escape sequence conversion */

#include <stdio.h>

/* Write a function escape(s,t) that converts characters like newline and tab
   into visible escape sequences like \n and \t as it copies the string t to s.
   Use a switch. Write a function for the other direction as well, converting
   escape sequences into the real characters. */

void escape(char s[], char t[]) {
    int i, j;
    
    for (i = j = 0; t[i] != '\0'; i++) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\b':
                s[j++] = '\\';
                s[j++] = 'b';
                break;
            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
                break;
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j;
    
    for (i = j = 0; t[i] != '\0'; i++) {
        if (t[i] == '\\' && t[i+1] != '\0') {
            switch (t[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                case 'b':
                    s[j++] = '\b';
                    break;
                case 'r':
                    s[j++] = '\r';
                    break;
                case '\\':
                    s[j++] = '\\';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        } else {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}

int main() {
    char t[] = "Hello\tWorld\nThis is a test\\string";
    char s[100];
    char u[100];
    
    printf("Original string: %s\n", t);
    
    escape(s, t);
    printf("After escape: %s\n", s);
    
    unescape(u, s);
    printf("After unescape: %s\n", u);
    
    return 0;
} 