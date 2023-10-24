#include  <string.h>
#include <stdio.h>

#define MAX 50

typedef struct
{
    int codigo;
    char descripcion[MAX];
} Articulo;

void  cambia(Articulo * art) {
    art->codigo = 10;
    strcpy(art->descripcion,"Copia");
}

int
main(void) {
    Articulo *  art = { 1, "Original"};
    cambia(art);

    printf("%d %s\n", art->codigo, art->descripcion);

    return 0;
}
