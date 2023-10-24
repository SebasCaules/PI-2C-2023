#include <stdio.h>
#include <string.h>

#define COLS 5
#define FILS 6

int wordle(char *palabra, char m[FILS][COLS], int intentos, int mRes[FILS][COLS]);

int letraEnPalabra(char *letra, char *palabra, int pos[]);

void palabraUsuario(char *palabra);

void rellenaMat(char m[FILS][COLS],int posFila,const char *palabra);

void intento(char m[FILS][COLS], int posFila);

int main(void){
    char palabra[] = "HHHHJ";
    int pos[COLS];
    int cant = letraEnPalabra("H", palabra, pos);
    for (int i = 0; i < cant; ++i) {
        printf("%d \n", pos[i]);
    }
    printf("cant %d \n", cant);

    /*char palabraIntento[COLS];
    palabraUsuario(palabraIntento);
    printf("%s\n", palabraIntento);
*/
    char m[FILS][COLS];
    char palabraDelDia [] = "FAROL";
    int posFila = 0;
    rellenaMat(m, posFila, palabraDelDia);

    printf("Primera mat\n");
    for (int i = 0; i < FILS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }

    intento(m, posFila);

    printf("Segunda mat\n");
    for (int i = 0; i < FILS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }

}



int letraEnPalabra(char *letra, char *palabra, int pos[]) {
    int cont = 0;
    for (int i = 0; palabra[i] != '\0'; ++i) {
        if (*letra == palabra[i]) {
            pos[cont++] = i;
        }
    }
    return cont;
}

void palabraUsuario(char *palabra){
    printf("Ingrese una Palabra: \n");
    int c, i = 0;
    while ((c = getchar()) != '\n'){
        palabra[i++] = (char)c;
    }
    palabra[i] = 0;

}

void rellenaMat(char m[FILS][COLS],int posFila,const char *palabra){
    for (int i = 0; i < COLS; ++i) {
        m[posFila][i] = palabra[i];
    }
    posFila++;
}

void intento(char m[FILS][COLS], int posFila){
    char palabraIntento[FILS];
    palabraUsuario(palabraIntento);
    printf("%s \n", palabraIntento);
    rellenaMat(m, posFila, palabraIntento);
}

int wordle(char *palabra, char m[FILS][COLS], int intentos, int mRes[FILS][COLS]) {
    int posFila = 0;
    rellenaMat(m, posFila, palabra);
    intento(m, posFila);


}