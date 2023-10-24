#include <stdio.h>
#include "getnum.h"

int main(void){
    int num = 0;
    int count = 0;
    do {
        num = getint("Ingrese un numero positivo: ");
    } while (num<0);
    while (num>0){
        count += (num%2);
        num /= 2;
    }
    printf("La cantidad de bits \"encendidos\" es %d \n", count);
}
