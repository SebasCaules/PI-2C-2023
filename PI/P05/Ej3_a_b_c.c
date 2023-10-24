#include <stdio.h>
#include "getnum.h"
#include <math.h>
#include <stdlib.h>


int lugar(int num, int pos);

int largo(int num);

int readNum(int num, int pos);


int main(void) {
    int boleto, esCapicua = 1;
    int j, i, l;

    boleto = getint("Ingrese un numero de 5 digitos: ");
    while (largo(boleto) != 5) {
        boleto = getint("Reingrese el numero: ");
    }

    for (i = 1; i <= largo(boleto); i++) {
        int x = readNum(boleto, i);
        printf("%d \n", x);
    }

    for (j = 1; j <= 2; j++)
        if (lugar(boleto, j) != lugar(boleto, 5 - j + 1)) {
            esCapicua = 0;
            break;
        }
    printf("El boleto %ses capicua", (esCapicua) ? "" : "no ");
    return 0;

}


int lugar(int num, int pos) {
    return (num / (int) pow(10, pos - 1)) % 10;
}

int largo(int num) {
    int count;
    for (count = 0; num > 0; count++) {
        num /= 10;
    }
    return count;
}

int readNum(int num, int pos) {
    int potencia = pow(10, ((largo(num)) - pos));
    return ((num / potencia) % 10);
}


