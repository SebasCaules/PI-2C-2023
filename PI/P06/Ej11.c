#include <assert.h>
#include <stdio.h>

#define MAXCOL 10

/* Ordena por el método de burbujeo */
void ordenaFilas(int mat[][MAXCOL], int dimF, int dimCol, int colEle);

int checkVector(const int v1[], const int v2[], int dim) {
    for(int i=0; i < dim; i++)
        if ( v1[i] != v2[i])
            return 0;
    return 1;
}

int main(void) {
    int m[][MAXCOL] = { {1, 2, 3, 4, 5},
                        {6, 2, 8, 9, 10},
                        {3, 5, 8, 2, 1},
                        {8, 7, 3, 6, 7}};

    int m2[][MAXCOL] = { {1, 2, 3, 4, 5},
                         {6, 2, 8, 9, 10},
                         {3, 5, 8, 2, 1},
                         {8, 7, 3, 6, 7}};

    // La matriz no cambia
    ordenaFilas(m, 4, 5, 2);

    for(int i=0; i < 4; i++)
        assert(checkVector(m[i], m2[i], 5));

    ordenaFilas(m, 4, 5, 1);
    assert(checkVector(m[0], m2[0], 5));
    assert(checkVector(m[1], m2[2], 5));
    assert(checkVector(m[2], m2[1], 5));
    assert(checkVector(m[3], m2[3], 5));

    ordenaFilas(m, 4, 5, 3);
    assert(checkVector(m[0], m2[0], 5) || checkVector(m[0], m2[3], 5));
    assert(checkVector(m[1], m2[0], 5) || checkVector(m[1], m2[3], 5));
    assert(checkVector(m[2], m2[1], 5) || checkVector(m[2], m2[2], 5));
    assert(checkVector(m[3], m2[1], 5) || checkVector(m[3], m2[2], 5));

    printf("OK!\n");
    return 0;
}

void swap(int v1[], int v2[], int dim){
    for (int i = 0; i < dim; ++i) {
        int aux = v1[i];
        v1[i] = v2[i];
        v2[i] = aux;
    }
    return;
}

void ordenaFilas(int mat[][MAXCOL], int dimF, int dimCol, int colEle) {
    colEle--;
    for (int i = 0; i < dimF; ++i) {
        for (int j = i+1; j < dimF; ++j) {
            if (mat[i][colEle] > mat[j][colEle]){
                swap(mat[i], mat[j], dimCol);
            }else;
        }
    }
}


/*int main(void) {
    int matriz[][MAXCOL] = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {3, 5, 8, 2, 1},
            {8, 1, 3, 6, 7}};
    int dimFilas = sizeof(matriz) / sizeof(matriz[0]);
    int dimColumnas = sizeof(matriz[0]) / sizeof(matriz[0][0]);
    printf("%d cantidad de filas y %d cantidad de columnas\n", dimFilas, dimColumnas);
    for (int i = 0; i < dimFilas; ++i) {
        for (int j = 0; j < dimColumnas; ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("ordena\n");

    ordenaFilas(matriz, dimFilas, dimColumnas, 1);
    for (int i = 0; i < dimFilas; ++i) {
        for (int j = 0; j < dimColumnas; ++j) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }


    return 0;
}*/
