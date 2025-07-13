/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */
/* Exercise 3.1 - Binary search with one test inside loop */

#include <stdio.h>

/* Our binary search makes two tests inside the loop, when one would suffice
   (at the price of more tests outside). Write a version with only one test
   inside the loop and measure the difference in run-time. */

int binsearch(int x, int v[], int n) {
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1;   /* no match */
}

/* Version with one test inside loop */
int binsearch_one_test(int x, int v[], int n) {
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return (x == v[low]) ? low : -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    
    printf("Original binary search for %d: %d\n", x, binsearch(x, arr, n));
    printf("One-test binary search for %d: %d\n", x, binsearch_one_test(x, arr, n));
    
    x = 10;
    printf("Original binary search for %d: %d\n", x, binsearch(x, arr, n));
    printf("One-test binary search for %d: %d\n", x, binsearch_one_test(x, arr, n));
    
    return 0;
} 