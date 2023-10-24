#include <stdio.h>

char *intento(char *palabra){
    printf("Ingrese una Palabra: \n");
    int c, i = 0;

    while ((c = getchar()) != '\n'){
        palabra[i++] = (char)c;
    }
    palabra[i] = 0;
    return palabra;
}

int main(void){

    char palabra[6];
    printf("holdsdsaa\n");
    printf("%s ", intento(palabra));
}