#include <stdio.h>
#include <errno.h>
#include <math.h>
#include "getnum.h"
#define SALIR 5

int
menu(void)
{
    int opcion;
    do
    {
        printf("\nBiblioteca Matematica\n");
        printf("1- Sin\n");
        printf("2- Cos\n");
        printf("3- Exp\n");
        printf("4- Log10\n");
        printf("5- Salir\n");
        opcion=getint("Ingrese opcion:");
    }  while (opcion < 1 || opcion > 5);
    return opcion;
}

int
main( void )
{
    char opcion;
    double numero;
    double rta;
    double (*vecFun[])(double)={sin, cos, exp, log10};

    do
    {
        if ( (opcion= menu()) != SALIR)
        {
            numero= getdouble("");
            errno= 0;
            rta= (* vecFun[opcion - 1]) (numero);
            if (errno != 0)
                printf("Problemas en el calculo\n");
            else
                printf("%s(%g)=%g\n", "FUNCION", numero, rta);
        }
    } while (opcion != SALIR);
    return 0;
}