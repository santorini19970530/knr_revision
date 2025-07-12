#include<stdio.h>

/* copy input to output : print true or false value */

int main(){
    int c, value;

    while((value = (c = getchar()) != EOF)){
        printf("%d\n", value);

    return 0;
}
