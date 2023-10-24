#include <stdio.h>

#define FILAS 5
#define COLS 5
#define EXITO 1
#define ERRORPASOS 2
#define ERRORPARAMETROS 0

int posicionFinal(int m[FILAS][COLS], int xi, int yi, int dirx, int diry, int n, int xf, int yf);
int checkFlag(int flag);

int main(void){
    int tablero[FILAS][COLS]={
            {0,0,0},
            {0,0,0},
            {0,0,0}
    };
    int xi = 2;
    int yi = 3;
    tablero[xi][yi] = 1;
    int xf, yf;
    int dirx = -1;
    int diry = -1;
    int n = 2;

    printf("Antes\n");
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }

    int flag = posicionFinal(tablero, xi, yi, dirx, diry, n, xf, yf);
    if(checkFlag(flag)){
        printf("Despues\n");
        for (int i = 0; i < FILAS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                if(tablero[i][j] >1)
                    printf("%c ", tablero[i][j]);
                else
                    printf("%d ", tablero[i][j]);

            }
            printf("\n");
        }
    }
}

int checkDir(int dir){
    switch (dir) {
        case -1: return 1;
        case 0: return 1;
        case 1: return 1;
        default: return 0;
    }
}

int posicionFinal(int m[FILAS][COLS], int xi, int yi, int dirx, int diry, int n, int xf, int yf){
    //Chequeo que las direcciones de Mov sean validas
    if((checkDir(dirx)== 0 || checkDir(diry) == 0) || (dirx == 0 && diry == 0))
        return ERRORPARAMETROS;

    xf = xi;
    yf = yi;

    while (n > 0){
        xf += dirx;
        yf += diry;
        if((xf >= FILAS || xf < 0) || (yf >= COLS || yf < 0))
            return ERRORPASOS;
        n--;
    }
    m[xi][yi] = 0;
    m[xf][yf] = 'B';
    return EXITO;

}

int checkFlag(int flag) {
    if (flag == ERRORPARAMETROS) {
        printf("ERROR DE PARAMETROS.\n");
        return 0;
    } else if (flag == ERRORPASOS) {
        printf("ERROR DE PASOS.\n");
        return 0;
    } else {
        printf("EXITO!\n");
        return 1;
    }
}