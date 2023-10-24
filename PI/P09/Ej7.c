#include <stdio.h>
#include <assert.h>
#include <math.h>

int busquedaBinaria(int datos[], int dim, int num);

int main(void) {

    int v[] = {-10, -5, 0, 5, 10, 15, 20, 25, 30, 35, 40, 45};

    assert(busquedaBinaria(v, 0, -10)==0);
    assert(busquedaBinaria(v, 1, -10)==1);
    assert(busquedaBinaria(v, 2, -10)==1);
    assert(busquedaBinaria(v, 2, -5)==1);
    assert(busquedaBinaria(v, 2, 0)==0);

    assert(busquedaBinaria(v+1, 2, -10)==0);
    assert(busquedaBinaria(v+1, 2, -5)==1);
    assert(busquedaBinaria(v+1, 2, 0)==1);

    for(int i=0; i < 12; i++)
        assert(busquedaBinaria(v, 12, v[i])==1);

    for(int i=0; i < 11; i++)
        assert(busquedaBinaria(v, 11, v[i])==1);


    printf ("OK!\n");
    return 0;
}

int busquedaBinaria(int datos[], int dim, int num){
    int l= 0;
    int r = dim-1;
    int m;
    for (int i = 0; i < dim; ++i) {
        m = floor((l+r) /2);
        if(datos[m] == num)
            return 1;
        if(datos[m] < num)
            l = m+1;
        if(datos[m] > num)
            r = m-1;
    }
    return 0;

}
