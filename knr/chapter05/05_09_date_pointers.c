/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 5.9 - Rewrite day functions with pointers
 * 
 * Rewrite the routines day_of_year and month_day with pointers
 * instead of indexing.
 */

#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
    int month, day;
    
    printf("Testing day_of_year with pointers:\n");
    printf("day_of_year(2024, 3, 15) = %d\n", day_of_year(2024, 3, 15));
    printf("day_of_year(2023, 12, 31) = %d\n", day_of_year(2023, 12, 31));
    printf("day_of_year(2024, 2, 29) = %d\n", day_of_year(2024, 2, 29));
    
    printf("\nTesting month_day with pointers:\n");
    month_day(2024, 75, &month, &day);
    printf("month_day(2024, 75) = month %d, day %d\n", month, day);
    
    month_day(2023, 365, &month, &day);
    printf("month_day(2023, 365) = month %d, day %d\n", month, day);
    
    return 0;
}

/* day_of_year: set day of year from month & day - pointer version */
int day_of_year(int year, int month, int day) {
    int leap;
    char *p;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = daytab[leap];
    
    while (--month > 0)
        day += *++p;
    return day;
}

/* month_day: set month, day from day of year - pointer version */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int leap;
    char *p;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = daytab[leap];
    
    while (yearday > *++p)
        yearday -= *p;
    *pmonth = p - daytab[leap];
    *pday = yearday;
} 