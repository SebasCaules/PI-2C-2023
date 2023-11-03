
#ifndef P11_EJ5_H
#define P11_EJ5_H

#include <stdio.h>
#include <stdlib.h>

typedef struct complejoCDT * complejoADT;

complejoADT nuevoComp(double real, double img);

void liberaComp(complejoADT num);

double parteRealComp(complejoADT num);

double parteImagComp(complejoADT num);

complejoADT sumaComp(complejoADT num1, complejoADT num2);

complejoADT restaComp(complejoADT num1, complejoADT num2);

complejoADT multiplicaComp(complejoADT num1, complejoADT num2);

complejoADT divideComp(complejoADT num1, complejoADT num2);

complejoADT conjugadoComp(complejoADT num);

#endif //P11_EJ5_H
