#include <stdio.h>

#define N 3


int verifica(int m[N][N]);

int main(void) {
    int m1[][N] = {
            {1, 3, 2},
            {9, 8, 6},
            {4, 7, 15}
    };

    int flag1 = verifica(m1);
    printf("%d\n", flag1);

    /*int m2[][N] = {
            {10,3,2,3,8,7},
            {12,8,6,6,2,4},
            {4,7,5,5,12,10},
            {2,12,6,10,4,5},
            {5,10,3,7,2,9},
            {8,4,7,3,6,11}
    };

    int flag2 = verifica(m2);
    printf("%d\n", flag2);*/

}

int sumaSubMat(int m[N][N], int subMat) {
    int tope = (N / 3) * subMat;
    int suma = 0;
    for (int i = subMat - 1; i < tope; ++i) {
        for (int j = subMat - 1; j < tope; ++j) {
            if ((m[i][i] % 3) != 0 || m[i][j] < 1)
                return 0;
            suma += m[i][j];
        }
    }
    return suma;
}

int verifica(int m[N][N]) {
    int n = N / 3;
    int iSubMat = 1;
    int suma = sumaSubMat(m, 1);
    for (int i = iSubMat+1; i <= N; ++i) {
        if(suma != sumaSubMat(m,i))
            return 0;
    }
    return 1;
}
