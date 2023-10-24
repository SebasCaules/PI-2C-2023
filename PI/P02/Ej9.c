#include <stdio.h>
#include "getnum.h"

int main() {
    int num = getint("Ingrese su Numero: ");
    printf("%d", num>>1);
}