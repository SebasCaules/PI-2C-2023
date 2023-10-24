#include <stdio.h>
#include "getnum.h"
#define Semanal 300

int main(void){
    float salario = Semanal;
    int ventas = getint("Ingrese el valor: ");
    //Chequeo si es Negativo
    while (ventas<0){
        printf("Ingreso un valor Negativo, porfavor reingrese el valor. \n");
        ventas = getint("Reingrese el valor: ");
    }

    if(ventas<= 1000){
        return 0;
    }else if(ventas<=2000) {
        salario += ventas*0.05;
    }else if(ventas>2000 && ventas<=4000){
        salario += ventas*0.07;
    }else {
        salario += ventas*0.09;
    }

    printf("Las ventas fueron de %d.\n", ventas);
    printf("El salario final queda en %f$ pesos.\n", salario);
}