#include <stdlib.h>
#include <stdio.h>

int main(void){
    char * fecha = "27/09/1993";
    int dia = atoi(fecha);
    int mes = atoi(fecha+3);
    int anio = atoi(fecha+6);

    printf("%d dia %d mes %d anio\n", dia, mes, anio);

    for (int i = 0; fecha[i] != '\0'; ++i) {
        printf("%c", fecha[i]);
    }
    printf("\n");

    printf("%d\n", *fecha > 11);
    printf("%s\n", fecha);
    printf("%d\n", *fecha);



}