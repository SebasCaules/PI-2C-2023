#include <stdio.h>
#include "getnum.h"

int main() {
    float metrosSegundos = getfloat("Ingrese la velocidad del objeto en m/s: ");
    float kilometrosHora = (metrosSegundos*3.6);
    printf("%f m/s son %f km/h", metrosSegundos, kilometrosHora);
}
