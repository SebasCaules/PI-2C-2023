#include <stdio.h>

int main(void){
    int num = 321;

    num = (num<0) ? (-num):(num);
    int suma = 0;
    while (num != 0){
        suma += num%10;
        num /= 10;
    }
    printf("%d", suma);
}