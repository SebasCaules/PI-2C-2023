#include "Ej5.h"

struct complejoCDT{
    double real;
    double img;
};

complejoADT nuevoComp(double real, double img){
    complejoADT aux = malloc(sizeof(struct complejoCDT));
    aux->real = real;
    aux->img = img;
    return aux;
}

void liberaComp(complejoADT num){
    free(num);
}

double parteRealComp(complejoADT num){
    return num->real;
}

double parteImagComp(complejoADT num){
    return num->img;
}

complejoADT sumaComp(complejoADT num1, complejoADT num2){
    complejoADT aux = malloc(sizeof (struct complejoCDT));
    aux->real = num1->real + num2->real;
    aux->img = num1->img + num2->img;
    return aux;
}

complejoADT restaComp(complejoADT num1, complejoADT num2){
    complejoADT aux = malloc(sizeof (struct complejoCDT));
    aux->real = num1->real - num2->real;
    aux->img = num1->img - num2->img;
    return aux;
}

complejoADT multiplicaComp(complejoADT num1, complejoADT num2){
    complejoADT aux = malloc(sizeof (struct complejoCDT));
    aux->real = num1->real * num2->real;
    aux->img = num1->img * num2->img;
    return aux;
}

complejoADT divideComp(complejoADT num1, complejoADT num2){
    complejoADT aux = malloc(sizeof (struct complejoCDT));
    if(num2->real != 0 && num2->img != 0){
        aux->real = num1->real - num2->real;
        aux->img = num1->img - num2->img;
        return aux;
    }
}

complejoADT conjugadoComp(complejoADT num){

}
