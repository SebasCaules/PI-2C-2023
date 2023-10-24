#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

/* Para definir “alumnos” como matriz de caracteres */
#define MAX_ALUMNOS 6
#define MAX_NOMBRE 15
#define BLOCK 10
#define NOTA_MINIMA 4

typedef char TAlumnos[MAX_ALUMNOS][MAX_NOMBRE];

/* Para definir “alumnos” como vector de punteros a char */
/* typedef char * Talumnos[]; */

// En esta versión validamos los malloc y realloc, como ejemplo.
// No es necesario que hagan estas validaciones en los parciales (sí en el final)


int main(void){

    TAlumnos alumnos = {"Juan", "Pedro", "Martin", ""};
    int notas[] = {1, 4, 10, 2, 10, 11};

    char ** apr = aprobados(alumnos, notas);
    if(apr == NULL){
        printf("No hay suficiente memoria!\n");
        return 1;
    }
    assert(!strcmp(alumnos[1], apr[0]) && !strcmp(alumnos[2], apr[1]) && !strcmp(alumnos[3], apr[2]));

    puts("OK!");
    // En este programa no liberamos la memoria que utilizamos. Que ocurre si compilamos con "-fsanitize=address"?
    return 0;
}

char **
aprobados(Talumnos alumnos, int notas[])
{
    int cantAprob = 0;
    char **alumAprob=NULL, **alumAux;

    errno = 0;
    for (int i = 0; alumnos[i][0] != '\0'; i++) {
        if (notas[i] >= NOTA_MINIMA)
        {
            /* Si no hay lugar en el vector, agrandarlo */
            if (cantAprob % BLOCK == 0)
            {
                alumAux = realloc(alumAprob, (cantAprob + BLOCK) * sizeof(char *));

                /* Si no hay memoria no hay nada que se pueda hacer */
                if (alumAux == NULL || errno == ENOMEM)
                {
                    if ( cantAprob > 0) { // Por si el que falla es el primer realloc, y alumAprob sigue en NULL
                        /* Hay que liberar todo, tambien los strings */
                        alumAprob[cantAprob] = "";
                        liberaAprobados(alumAprob);
                    }
                    return NULL;

                }
                alumAprob = alumAux;
            }
            /* Copiar el string */
            alumAprob[cantAprob] = malloc(strlen(alumnos[i]) + 1);
            if (alumAprob[cantAprob] == NULL  || errno == ENOMEM)
            {
                alumAprob[cantAprob] = "";
                liberaAprobados(alumAprob);
                return NULL;
            }
            strcpy(alumAprob[cantAprob++], alumnos[i]);
        }
    }

    /* Copiar el string vacio al final, y liberar lo que sobra del bloque final */
    alumAprob = realloc(alumAprob, (cantAprob+1) * sizeof(char *));
    alumAprob[cantAprob] = "";

    return alumAprob;
}

void liberaAprobados(char **alumnos)
{
    /* Liberar los strings excepto el string vacio (ya que era constante) */
    for (int i = 0; *alumnos[i]; i++)
        free(alumnos[i]);

    free(alumnos);
}