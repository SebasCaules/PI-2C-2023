#ifndef TALLER_DICCIOADT_H
#define MAXWIDTH 25
#define MAXSIGNIFICADO 255

typedef struct diccioCDT * diccioADT;

diccioADT creaDiccionario(void);

void liberaDiccionario(diccioADT dic);

int agregaPalabra(diccioADT dic, const char * palabra, const char * significado);

void imprimeDiccionario(diccioADT dic);

#define TALLER_DICCIOADT_H

#endif //TALLER_DICCIOADT_H
