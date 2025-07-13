/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.7: atoi function implementation */

#include <stdio.h>
#include <ctype.h>

/* atoi: convert s to integer */
int atoi(char s[]) {
    int i, n, sign;
    
    for (i = 0; isspace(s[i]); i++)  /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')  /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

int main() {
    char str1[] = "123";
    char str2[] = "-456";
    char str3[] = "  +789";
    
    printf("atoi(\"%s\") = %d\n", str1, atoi(str1));
    printf("atoi(\"%s\") = %d\n", str2, atoi(str2));
    printf("atoi(\"%s\") = %d\n", str3, atoi(str3));
    
    return 0;
}
