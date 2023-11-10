#include "diccioADT.h"

int
main(void) {
    diccioADT diccionario = creaDiccionario();

    agregaPalabra(diccionario, "auto", "Aparato que se mueve");
    agregaPalabra(diccionario, "armario", "Mueble para guardar cosas");
    agregaPalabra(diccionario, "auto", "Otra definición"); // No se actualiza la definición
    agregaPalabra(diccionario, "unapalabrasumamentelarganoentra", "Quizás si"); ; // No se agrega
    agregaPalabra(diccionario, "gato", "Animal de cuatro patas enemigo del perro");
    agregaPalabra(diccionario, "aceituna", "Fruto del olivo");
    agregaPalabra(diccionario, "Auto", "Otra vez lo mismooo"); // No se actualiza la definición
    agregaPalabra(diccionario, "zanahoria", "Planta herbácea");

    /**
     * Debe imprimir:
     *
     * auto: Aparato que se mueve
     * armario: Mueble para guardar cosas
     * aceituna: Fruto del olivo
     * gato: Animal de cuatro patas enemigo del perro
     * zanahoria: Planta herbácea
     *
     */
    imprimeDiccionario(diccionario);

    liberaDiccionario(diccionario);

    return 0;
}