#include <stdio.h>

int main(void){
    printf("Ingrese su Caracter: ");
    int car = getchar();
    int conversionRate = 'a' - 'A';
    int conversion = car - conversionRate;
    printf("%c", conversion);
}
