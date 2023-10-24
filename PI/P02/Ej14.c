#include <stdio.h>
#include "getnum.h"

int main(void){
    int num1 = getint("Ingrese su primer Numero: ");
    int num2 = getint("Ingrese su segundo Numero: ");
    float promedio = (float)(num1+num2)/2;
    int suma = num1+num2;
    int mayor = num1 > num2 ? num1:num2;
    int menor = num1 < num2 ? num1:num2;
    int iguales = (num1==num2) ? printf("son iguales\n"):printf("no son iguales\n");
    printf("%f es el promedio entre %d y %d\n", promedio, num1, num2);
    printf("%d es la suma entre %d y %d\n", suma, num1, num2);
    printf("%d es el mayor entre %d y %d\n", mayor, num1, num2);
    printf("%d es el menor entre %d y %d\n", menor, num1, num2);
    return 0;
}
