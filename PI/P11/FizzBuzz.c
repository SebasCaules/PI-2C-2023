#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *v = malloc(50000);
    *v = 1;


    for (long int i = 1; i < 11; ++i) {
        if (i % 15 == 0) {
            printf("FizzBuzz\n");
            continue;
        }
        if (i % 3 == 0) {
            printf("Fizz\n");
            continue;
        }
        if(i%5 == 0){
            printf("Buzz\n");
            continue;
        }
        printf("%d\n", i);
    }
    return 0;
}