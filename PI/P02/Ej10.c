#include <stdio.h>
#include "getnum.h"

int main(void) {
    int segundos = getint("ingrese los segundos: ");
    printf("%d segundo son %d horas %d minutos y %d segundos", segundos, segundos/3600, (segundos/60)-((segundos/3600)*60), segundos-(((segundos/3600)*3600)+(((segundos/60)-((segundos/3600)*60)))*60));
}
