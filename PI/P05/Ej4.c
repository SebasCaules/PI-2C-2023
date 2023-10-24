#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"
#include <time.h>

int main(void) {
    int num1 = getint("Ingrese su valor izquierdo: ");
    int num2 = getint("Ingrese su valor derecho: ");
    int right, left;
    if (num2 > num1) {
        right = num2;
        left = num1;
    } else {
        right = num1;
        left = num2;
    }
    printf("%d r ", right);
    printf("%d l ", left);



    int randNum;
    randNum = (rand() % ((right - left + 1) + left));

    printf("%d", randNum);
}

