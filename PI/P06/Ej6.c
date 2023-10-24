#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

/*
 * arr ->[1,2,3,4,5]; dim =5
 * resp -> [5,4,2,3,1] dim = 5
 *
 *
 * */
void mezclaArreglo(int arr[], int n){
    int aux, idx;
    for(int i = 0; i < n; i++){
        idx = randInt(0,n-1);
        aux = arr[idx];
        arr[idx] = arr[i];
        arr[i] = aux;
        printf("%d ", arr[i]);
    }
}

int main(void) {
    randomize()
    int arr[] = {1,2,3,4,5};
    int dim = (sizeof(arr) / sizeof(arr[0]));
    mezclaArreglo(arr, dim);
}