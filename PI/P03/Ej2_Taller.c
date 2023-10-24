#include <stdio.h>
#include "getnum.h"


int main(void){
    float num = getfloat("Ingrese un Numero: ");
    num = (num<0) ? (-num):(num);
    //inicializar el num
    int suma = 0;

    while (num != 0){
        num -= (int)num;
        num *= 10;
        suma += num;
        printf("%f nj %d\n", num, suma);

    }
    printf("%d la suma es", suma);

}