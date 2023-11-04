#include <stdio.h>

int main(void) {
    for (long int i = 1; i < 100001; ++i) {
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
}