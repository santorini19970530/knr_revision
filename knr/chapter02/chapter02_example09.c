/* KnR Book Second Edition, written by Brian Kernighan and Dennis Ritchie */

/* Example 2.9: rand and srand demonstration */

#include <stdio.h>
#include <time.h>

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..32767 */
int rand(void){
    next = next * 1103515245 + 12345;
    
    return (unsigned int)(next/65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed){
    next = seed;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
        printf("%d ", rand() % 100);

    printf("\n");

    return 0;
} 
