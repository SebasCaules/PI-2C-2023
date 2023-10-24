#include <stdio.h>
#include "getnum.h"
#include <math.h>

#define intMax 2147483647
#define intMin -2147483648


int lugar(int num, int pos);

int largo(int num);


int main(void) {
    int boleto, esCapicua = 1;
    int i, l;

    boleto = getint("Ingrese un numero de 5 digitos: ");

    l = largo(boleto);
    for (i = 1; i <= l; i++) {
        if (lugar(boleto, i) != lugar(boleto, l - i + 1)) {
            esCapicua = 0;
            break;
        }
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
