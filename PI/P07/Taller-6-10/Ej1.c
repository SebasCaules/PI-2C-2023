#include <stdio.h>
#include <stdlib.h>
#define TAM 10


int main(void){
    int *arr1;
    //1
    arr1 = malloc(TAM* sizeof(int));
    for (int i = 0; i < TAM; ++i) {
        arr1[i] = 0;
    }

    for (int i = 0; i < TAM; ++i) {
        printf("%d ", arr1[i]);
    }
    free(arr1);

    printf("\n");

    //2
    int *arr2;
    arr2 = NULL;
    arr2 = realloc(arr2, TAM* sizeof(int));
    for (int i = 0; i < TAM; ++i) {
        arr2[i] = 0;
    }

    for (int i = 0; i < TAM; ++i) {
        printf("%d ", arr2[i]);
    }

    printf("\n");

    //3
    int *arr3;
    arr3 = calloc(TAM* sizeof(int))


}