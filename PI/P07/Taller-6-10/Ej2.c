#include <stdlib.h>
#include <stdio.h>
#include "getnum.h"
#define BLOQUE 10

int *cargaNumeros(int *dim);

int main(void){
    int dim;
    int *arr;
    arr = cargaNumeros(&dim);

    for (int i = 0; i < dim; ++i) {
        printf("%d", arr[i]);
    }

    free(arr);
    return 0;
}

int *cargaNumeros(int *v){
    int num;
    int dim = 0;
    int *arr = NULL;
    do{
        if(dim%BLOQUE == 0)
            arr = realloc(arr, (dim+BLOQUE)* sizeof(int));
    }while();
    while((num = getint("Ingrese un numero: ")) != '\n'){

    }
}
