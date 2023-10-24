#include <stdio.h>

int main(void){
    printf("Ingrese los dos Caracteres: ");
    int car1 = getchar();
    int car2 = getchar();
    int comp = car1 > car2 ? car1:car2;
    printf("%c", comp);
}

//Cuando ingresamos ABCD nos devuelve B como respuesta pues solo tomo a A y B
/*
Cuando ingresamos
 A
 B
 C
 D
 toma como entrada la A y el enter y nos devuelve A como respuesta */

//Cuando ingresamos A(tab)B toma A y (tab) como los caracteres y nos devuelve A como respuesta