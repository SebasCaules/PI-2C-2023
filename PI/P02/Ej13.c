#include <stdio.h>
#include "getnum.h"

int main(void){
    int num1 = getint("Ingrese su primer Numero: ");
    int num2 = getint("Ingrese su segundo Numero: ");
    int division = num2%num1;
    int comp = division == 0 ? num2:0;
    printf("%d\n", comp);

}
