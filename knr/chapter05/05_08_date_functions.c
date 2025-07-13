/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/*
 * Exercise 5.8 - Day of year and month day
 * 
 * There is no error checking in day_of_year or month_day.
 * Remedy this defect.
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
    
    printf("Testing day_of_year function:\n");
    printf("day_of_year(2024, 3, 15) = %d\n", day_of_year(2024, 3, 15));
    printf("day_of_year(2023, 12, 31) = %d\n", day_of_year(2023, 12, 31));
    printf("day_of_year(2024, 2, 29) = %d\n", day_of_year(2024, 2, 29));
    
    printf("\nTesting month_day function:\n");
    month_day(2024, 75, &month, &day);
    printf("month_day(2024, 75) = month %d, day %d\n", month, day);
    
    month_day(2023, 365, &month, &day);
    printf("month_day(2023, 365) = month %d, day %d\n", month, day);
    
    return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int i, leap;
    
    /* Error checking */
    if (month < 1 || month > 12) {
        printf("error: invalid month %d\n", month);
        return -1;
    }
    
    if (day < 1 || day > daytab[leap = (year%4 == 0 && year%100 != 0 || year%400 == 0)][month]) {
        printf("error: invalid day %d for month %d\n", day, month);
        return -1;
    }
    
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    
    /* Error checking */
    if (yearday < 1 || yearday > (leap ? 366 : 365)) {
        printf("error: invalid yearday %d for year %d\n", yearday, year);
        *pmonth = *pday = -1;
        return;
    }
    
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
} 