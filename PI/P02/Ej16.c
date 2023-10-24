#include <stdio.h>

int main(void){
    printf("Ingrese sus caracteres: ");
    int char1 = getchar();
    int char2 = getchar();
    int comp = (char1==char2) ? printf("El caracter %c es igual al caracter %c", char1, char2):((char1>char2) ? printf("El caracter %c es mas grande que el caracter %c", char1, char2): printf("El caracter %c es menor al caracter %c.", char1, char2));
    printf("%c", comp);
}
