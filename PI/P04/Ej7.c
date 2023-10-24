#include <stdio.h>
#define isdigit(char) (char>47 && char<58)


int main(void){
    printf("Ingrese su caracter: ");
    int c = getchar();
    printf("%s es numero entero", isdigit(c)==0 ? "No":"");
}