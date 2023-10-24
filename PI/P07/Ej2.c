#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define BLOQUE 10


int convierte(int num);

int main(void) {
    int num = 41;
    int b = convierte(num);
    printf("%d\n",b);
}

int largoNum(int num) {
    return (int) floor(log10(abs(num))) +1;
}

int *numEnArray(int num){
    int *arrNum = NULL;
    int cont = largoNum(num);
    int i;
    for (i = 0; i < largoNum(num); ++i, --cont) {
        if(i % BLOQUE == 0)
            arrNum = realloc(arrNum, (i+BLOQUE)* sizeof(int));
        arrNum[i] = (int)((num%(int) pow(10, cont))/ pow(10, cont-1));
    }
    arrNum = realloc(arrNum, (i+1)* sizeof(int));
    return arrNum;
}

int aBase10(int baseE, int num,const int * arrNum){
    int numAux = 0;
    for (int i = 0; i < largoNum(num); ++i) {
        numAux += (int)(arrNum[i]* pow(baseE, largoNum(num)-1-i));
    }
    return numAux;
}

int aBaseX(const int baseS, int num){
    int *arrNum = NULL;
    int i = 0;
    while(num >= baseS){
        if(i % BLOQUE == 0)
            arrNum = realloc(arrNum, (i+BLOQUE)* sizeof(int));
        arrNum[i] = num%baseS;
        num /= baseS;
        i++;
    }
    arrNum = realloc(arrNum, (i+1)* sizeof(int));
    arrNum[i] = num;

    int numRet = 0;
    for (int j = i; j >= 0; --j) {
        numRet += (int)(arrNum[j]* pow(10, j));
    }
    free(arrNum);
    return numRet;
}

int convierte(int num){
    int cant;
    int baseE;
    int baseS;

    //Agarro las bases
    do{
        printf("Ingrese la base de entrada y de salida respectivamente: ");
        cant = scanf("<%d>%d", &baseE, &baseS);
        while(getchar() != '\n');
    }while(cant != 2);


    int * arrNum = numEnArray(num);
    num = aBase10(baseE, num, arrNum);
    num = aBaseX(baseS, num);

    free(arrNum);
    return num;

}
