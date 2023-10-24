#include <stdio.h>
#include <assert.h>

#define DIM 9

int sudokuSolver(char m[][DIM]);

void divideMat(const char m[][DIM], char v[]);

int checkCol(const char m[][DIM], int fila);

int checkFil(const char m[][DIM], int col);

int checkSubMat(char v[], int subMat);


int main(void) {

    // Una matriz vacía no es solución
    char sudoku[DIM][DIM] = {{0}};

    assert(sudokuSolver(sudoku) == 0);

    char sudoku2[DIM][DIM] = {
            {3, 8, 1, 9, 7, 6, 5, 4, 2},
            {2, 4, 7, 5, 3, 8, 1, 9, 6},
            {5, 6, 9, 2, 1, 4, 8, 7, 3},
            {6, 7, 4, 8, 5, 2, 3, 1, 9},
            {1, 3, 5, 7, 4, 9, 6, 2, 8},
            {9, 2, 8, 1, 6, 3, 7, 5, 4},
            {4, 1, 2, 6, 8, 5, 9, 3, 7},
            {7, 9, 6, 3, 2, 1, 4, 8, 5},
            {8, 5, 3, 4, 9, 7, 2, 6, 1}
    };

    /*char v[DIM * DIM];
    divideMat(sudoku2, v);
    for (int i = 0; i < DIM * DIM; ++i) {
        //printf("%d pos %d ", v[i], i);
    }
    printf("\n");

    for (int i = 0; i < DIM; ++i) {
        int sub = checkSubMat(v, i);
        printf("%d\n", sub);
    }



    int col = checkCol(sudoku2, 1);
    int fil = checkFil(sudoku2, 1);
    printf("%d col %d fila\n", col, fil);


    char v1[DIM*DIM];
    for (int i = 0; i < DIM; ++i) {
        int sub =checkSubMat(sudoku2, v1, 1);
        printf("%d sub mat\n", sub);
    }*/


    assert(sudokuSolver(sudoku2) == 1);

    char sudoku3[DIM][DIM] = {
            {2, 8, 1, 9, 7, 6, 5, 4, 2},
            {3, 4, 7, 5, 3, 8, 1, 9, 6},
            {5, 6, 9, 2, 1, 4, 8, 7, 3},
            {6, 7, 4, 8, 5, 2, 3, 1, 9},
            {1, 3, 5, 7, 4, 9, 6, 2, 8},
            {9, 2, 8, 1, 6, 3, 7, 5, 4},
            {4, 1, 2, 6, 8, 5, 9, 3, 7},
            {7, 9, 6, 3, 2, 1, 4, 8, 5},
            {8, 5, 3, 4, 9, 7, 2, 6, 1}
    };

    assert(sudokuSolver(sudoku3) == 0);

    // Cuando se tomó este ejercicio en un parcial, en una de las respuestas
    // sólo chequeaban que la suma de cada fila, columna y cuadrado fuera 45
    char sudoku4[DIM][DIM] = {
            {5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5},
            {5, 5, 5, 5, 5, 5, 5, 5, 5}
    };

    assert(sudokuSolver(sudoku4) == 0);

    char sudoku5[DIM][DIM] = {
            {3, 8, 1, 9, 7, 6, 5, 4, 12},
            {2, 4, 7, 5, 3, 8, 1, 9, 6},
            {5, 6, 9, 2, 1, 4, 8, 7, 3},
            {6, 7, 4, 8, 5, 2, 3, 1, 9},
            {1, 3, 5, 7, 4, 9, 6, 2, 8},
            {9, 2, 8, 1, 6, 3, 7, 5, 4},
            {4, 1, 2, 6, 8, 5, 9, 3, 7},
            {7, 9, 6, 3, 2, 1, 4, 8, 5},
            {8, 5, 3, 4, 9, 7, 2, 6, 1}
    };

    assert(sudokuSolver(sudoku5) == 0);
    puts("OK");
    return 0;
}

void divideMat(const char m[][DIM], char v[]) {
    int dimV = 0;
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            v[dimV++] = m[i][j];
        }
    }
}

int checkSubMat(char v[], int subMat) {
    //Chequeo que la sub matriz a analizar este entre el 0 y el 9
    if (subMat < 0 || subMat > 9)
        return 0;
    subMat *= 9;

    for (int i = 0; i < DIM-1; ++i) {
        if (v[i + subMat] == v[i + subMat + 1])
            return 0;
        if(v[i+ subMat +1] >= 10)
            return 0;
    }
    return 1;
}

int checkFil(const char m[][DIM], int fila) {
    for (int i = 0; i < DIM - 1; ++i) {
        char anterior  = m[fila][i];
        for (int j = i+1; j < DIM - 1; ++j) {
            char actual = m[fila][j];
            if(anterior == actual)
                return 0;
        }
    }
    return 1;
}

int checkCol(const char m[][DIM], int col) {
    for (int i = 0; i < DIM - 1; ++i) {
        char anterior  = m[i][col];
        for (int j = i+1; j < DIM - 1; ++j) {
            char actual = m[j][col];
            if(anterior == actual)
                return 0;
        }
    }
    return 1;
}


int sudokuSolver(char m[][DIM]) {
    char v[DIM*DIM];
    divideMat(m, v);

    //Chequeo todas las filas
    for (int i = 0; i < DIM; ++i) {
        int flagInt = checkFil(m, i);
        if (!flagInt)
            return 0;
    }

    //Chequeo todas las Columnas
    for (int j = 0; j < DIM; ++j) {
        int flagInt = checkCol(m, j);
        if (!flagInt)
            return 0;
    }

    //Chequeo todas las Sub Matrices
    for (int k = 0; k < DIM; ++k) {
        int flagInt = checkSubMat(v, k);
        if (!flagInt)
            return 0;
    }

    return 1;
}
