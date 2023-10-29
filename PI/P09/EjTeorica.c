#include <stdio.h>

int potencia(int i, int n);
int isNull(int vec[], int dim);

int main(void) {
    int i = 2;
    int n = 16;
    int b = potencia(i, n);
    printf("%d \n", b);

    int vec[] = {9,3,2,3};
    int vec1[] = {0,0,0,0};
    int dim = 4;
    printf("vec %s nulo\n", isNull(vec1, dim)? "es":"no es");
}

int potencia(int i, int n) {
    if (n == 0 || i == 0)
        return 1;
    return i * potencia(i, n - 1);
}

int isNull(int vec[], int dim){
    if(*vec != 0)
        return 0;
    if(dim == 0)
        return 1;
    isNull(vec+1, dim-1);
}