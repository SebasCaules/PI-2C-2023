#include <stdio.h>

int eliminaRepetidosOrdenado(int array[], int dim, int resp[]) {
    int dimResp = 0;
    for(int i = 0; i<dim; i++){
        if(array[i] != array[i+1]){
            resp[dimResp++] = array[i];
        }
    }
    return dimResp;
}


int main(void) {
    int v[] = {1, 1, 3, 4, 5, 6, 7, 8, 9};
    int dim = sizeof(v) / sizeof(v[0]);
    int res[20];
    int b  = eliminaRepetidosOrdenado(v, dim, res);
    printf("%d",b);
}