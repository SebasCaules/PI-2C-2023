#include <stdio.h>
#include <stdlib.h>
#include "getnum.h"

#define TOTAL_ITEMS 2
#define MAX_LONG 10

typedef struct {
    int codigo;
    char desc[MAX_LONG];
    float precio;
} tItem;

typedef tItem tFactura[TOTAL_ITEMS];

tItem leerItem(void);

void cargar(tFactura fact, int cant);

float importe(tFactura fact, int cant);

int
main(void) {
    tFactura f;
    cargar(f, TOTAL_ITEMS);
    printf("Total Factura: %.2f", importe(f, TOTAL_ITEMS));
    return 0;
}

tItem leerItem(void) {
    tItem item;
    do {
        item.codigo = getint("Codigo: ");
    } while (item.codigo <= 0);
    do {
        item.precio = getfloat("Precio: ");
    } while (item.precio <= 0);
    do {
        printf("Descripcion: ");
    } while (fgets(item.desc, MAX_LONG, stdin) == NULL || item.desc[0] == '\n');
    return item;
}

void cargar(tFactura fact, int cant) {
    for (int i = 0; i < cant; ++i) {
        fact[i] = leerItem();
    }
}

float importe(tFactura fact, int cant) {
    float cont = 0;
    for (int i = 0; i < cant; ++i) {
        cont += fact[i].precio;
    }
    return cont;
}


