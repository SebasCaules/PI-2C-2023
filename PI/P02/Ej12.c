#include <stdio.h>
#include "getnum.h"
#define letra = 0
#define noLetra = 1

int main(void){
    printf("ingrese su caracter: \n");
    int caracter = getchar();
    int comp = ((caracter > 64 && caracter < 91) | (caracter > 96 && caracter < 123)) ? printf("%c es letra", caracter): printf("%c no es letra", caracter);
    printf("%c", comp);
    return 0;
}
