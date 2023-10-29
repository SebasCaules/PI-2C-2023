#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int esPotenciaDe3(int num);

int main(void){
    printf("%d\n", esPotenciaDe3(27));
    printf("%d\n", esPotenciaDe3(0));
}


int esPotenciaDe3(int num) {
    if(num == 1)
        return 1;
    if(num == 0 || num %3 != 0)
        return 0;
    return esPotenciaDe3(num/3);
}