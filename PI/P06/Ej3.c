#define EPSILON 0.000001
#include <math.h>
#include <assert.h>
#include <stdio.h>

/* Calcula la maxima diferencia entre dos valores consecutivos de un arreglo de reales */
double
maxDiferencia(const double arreglo[]);

int main(void) {

    double v[] = {1.0, 0.0};
    assert(fabs(maxDiferencia(v))==0.0);

    double v2[] = {1.0, 1.0, 1.0, 0.0};
    assert(fabs(maxDiferencia(v2))==0.0);

    double v3[] = {1.5, 3.0, -1.0, 0.0};
    assert(fabs(maxDiferencia(v3) - 4.0) < EPSILON);

    double v4[] = {1.5, 3.0, 4.5, 3.0, 0.0};
    assert(fabs(maxDiferencia(v4) -1.5) < EPSILON);

    double v5[] = {2.5, 1.0, 1.5, 2.0, 0.0};
    assert(fabs(maxDiferencia(v5)- 1.5) < EPSILON );

    double v6[] = {1.5,  -1.0, 3.0, 0.0};
    assert(fabs(maxDiferencia(v6) - 4.0) < EPSILON);

    puts("OK!");
    return 0;
}

int distancia(int x, const int array[]){
    int tamaño = sizeof(array) / sizeof(array[0]);
    int k, q, dist = 0;
    k = array[x];
    q = array[x+1];
    if (tamaño > 1) {
        dist = abs(k)+ abs(q);
        if(k<0 || q<0){
            return dist;
        }else {
            dist = dist-2* abs(q);
        }
    }
    return dist;
}


int main(void) {
    int array[]={10,9,8,7,9,-5,4,3,2,1,0};
    printf("%d\n", array[0]);
    int b = distancia(4, array);
    printf("%d", b);
}