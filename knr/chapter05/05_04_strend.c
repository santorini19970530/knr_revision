/* Exercise 5.4 - strend function */

#include <stdio.h>

/* Write the function strend(s,t), which returns 1 if the string t occurs
   at the end of the string s, and zero otherwise. */

int strend(char *s, char *t) {
    char *s_end = s;
    char *t_end = t;
    
    /* Find end of both strings */
    while (*s_end)
        s_end++;
    while (*t_end)
        t_end++;
    
    /* If t is longer than s, it can't be at the end */
    if (t_end - t > s_end - s)
        return 0;
    
    /* Compare from the end */
    while (t_end > t) {
        if (*--s_end != *--t_end)
            return 0;
    }
    return 1;
}

int main() {
    char s1[] = "hello world";
    char t1[] = "world";
    char t2[] = "hello";
    char t3[] = "xyz";
    
    printf("'%s' ends with '%s': %d\n", s1, t1, strend(s1, t1));
    printf("'%s' ends with '%s': %d\n", s1, t2, strend(s1, t2));
    printf("'%s' ends with '%s': %d\n", s1, t3, strend(s1, t3));
    
    char s2[] = "programming";
    char t4[] = "ing";
    char t5[] = "gram";
    
    printf("'%s' ends with '%s': %d\n", s2, t4, strend(s2, t4));
    printf("'%s' ends with '%s': %d\n", s2, t5, strend(s2, t5));
    
    return 0;
} 