#include <stdio.h>
#include <assert.h>

#define ALTO 6
#define ANCHO 5

void suavizar(unsigned char imagen[ALTO][ANCHO], unsigned int w);

int equals(unsigned int cols, unsigned char m1[][cols], unsigned char m2[][cols], unsigned int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m1[i][j] != m2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int calculoFiltro(int w);

int main(void) {

    unsigned char bmp[ALTO][ANCHO] = {
            {10, 10, 20, 23, 24},
            {10, 12, 18, 25, 23},
            {12, 14, 18, 26, 22},
            {12, 14, 19, 20, 22},
            {13, 16, 19, 20, 22},
            {14, 14, 19, 21, 23}};


    suavizar(bmp, 3);
    unsigned char suave[ALTO][ANCHO] = {
            {10, 13, 18, 22, 23},
            {11, 13, 18, 22, 23},
            {12, 14, 18, 21, 23},
            {13, 15, 18, 20, 22},
            {13, 15, 18, 20, 21},
            {14, 15, 18, 20, 21}};

    assert(equals(ANCHO, bmp, suave, ALTO));

    // Ahora una con w=5
    unsigned char suave5[ALTO][ANCHO] = {
            {14, 16, 17, 19, 20},
            {14, 16, 17, 18, 20},
            {14, 16, 17, 18, 20},
            {15, 16, 17, 18, 20},
            {15, 16, 17, 18, 20},
            {15, 16, 17, 18, 19}};

    suavizar(bmp, 5);
    assert(equals(ANCHO, bmp, suave5, ALTO));

    puts("OK!");



    return 0;
}

//Chequea si W es par o menor a 3, si no devuelve el numero de bloques vecino a desplazarse
int calculoFiltro(int w) {
    if (w < 3 || (w % 2 == 0))
        return 0;
    else
        return ((w - 1) / 2);
}

int mediaAritmetica(const unsigned char imagen[ALTO][ANCHO], int i, int j, int filtro) {
    int cont = 0;
    int suma = 0;

    for (int k = -filtro; k <= filtro; ++k) {
        for (int t = -filtro; t <= filtro; ++t) {
            if (((i + k) >= 0 && (j + t) >= 0) && ((i + k) <= (ALTO - 1) && (j + t) <= (ANCHO - 1))) {
                suma += imagen[(i + k)][(j + t)];
                cont++;
            } else;

        }
    }
    return ((int) suma / cont);
}

void suavizar(unsigned char imagen[ALTO][ANCHO], unsigned int w) {
    int filtro = calculoFiltro(w);
    if (!filtro)
        return;

    unsigned char aux[ALTO][ANCHO];

    for (int i = 0; i < ALTO; ++i) {
        for (int j = 0; j < ANCHO; ++j) {
            aux[i][j] = mediaAritmetica(imagen, i, j, filtro);
        }
    }

    for (int i=0; i < ALTO; i++) {
        for (int j=0; j < ANCHO; j++)
            imagen[i][j] = aux[i][j];
    }
}

