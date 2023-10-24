#include <stdio.h>
#include <assert.h>

#define COLS 4

int sonAmigas(const int (m1[])[COLS], unsigned int fils1, const int (m2[])[COLS], unsigned int fils2);
int contiene(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2);

int
main(void) {
    int m1[][COLS] = {{0, 1, 2, 3},
                      {4, 4, 5, 6},
                      {7, 8, 8, 9}};
    int m2[][COLS] = {{0,  1, 2, 3},
                      {-3, 7, 8, 9},
                      {-1, 3, 4, 7},
                      {4,  5, 6, 8}};
    int m3[][COLS] = {{2, 3, 3, 7}};

    printf("%d\n", contiene(m1[0], COLS, m2[1], COLS));
    assert(sonAmigas(m1, 3, m2, 4) == 1);
    assert(sonAmigas(m1, 1, m2, 4) == 1);
    assert(sonAmigas(m1, 2, m2, 4) == 1);
    assert(sonAmigas(m1, 2, m2, 2) == 0);
    assert(sonAmigas(m2, 4, m1, 3) == 2);
    assert(sonAmigas(m1, 3, m3, 1) == 0);
    assert(sonAmigas(m3, 1, m1, 3) == 0);
    int res = sonAmigas(m1, 3, m1, 3);
    assert(res == 1 || res == 2);

    printf("OK !\n");

    return 0;
}


int pertenece(int elem, const int v[], unsigned int dim) {
    int i;
    for (i = 0; i < dim; i++)
        if (elem == v[i])
            return 1;

    return 0;
}

int contieneAux(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2) {
    int i, encontrado;
    for (i = 0, encontrado = 1; i < dim1 && encontrado; i++)
        encontrado = pertenece(v1[i], v2, dim2);

    return encontrado;
}

int contiene(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2) {
    if (contieneAux(v1, dim1, v2, dim2))
        return 1;
    return 0;
}

int matAmigas(const int (m1[])[COLS], unsigned int fils1, const int (m2[])[COLS], unsigned int fils2) {
    int ret = 0;

    for (int i = 0; i < fils1; ++i) {
        for (int j = 0; j < fils2; ++j) {
            if (contiene(m1[i], COLS, m2[j], COLS)) {
                i++;
                j = 0;
                ret = 1;
            }
        }
    }
    printf("%d h\n", ret);
    return ret;
}

int sonAmigas(const int (m1[])[COLS], unsigned int fils1, const int (m2[])[COLS], unsigned int fils2) {
    if (matAmigas(m1, fils1, m2, fils2)) {
        return 1;
    } else if (matAmigas(m2, fils2, m1, fils1)) {
        return 2;
    } else
        return 0;
}
