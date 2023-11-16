#include "Ej12.h"
#include <stdlib.h>
#define MAX 21

struct related {
    char name[MAX];             // Usamos un vector estático porque hay un límite y es pequeño.
    // También se podría usar char*, y no tener un límite.
    struct related * next;
};

struct person {
    char name[MAX];
    struct related * firstR;
    struct person * next;
    size_t sizeR;
};

typedef struct person * TPerson;
typedef struct related * TRelated;

typedef struct socialCDT {
    struct person * people;     // puntero a la primera persona
    size_t sizeP;
}socialCDT;


/* Crea un nuevo TAD vacío */
socialADT newSocial(){
    socialADT aux = calloc(1, sizeof(socialCDT));
    return aux;
}

/* Libera todos los recursos reservados por el TAD */
void freeSocial(socialADT soc){
    if(soc->people != NULL){
        if(soc->people->firstR != NULL)
            free(soc->people->firstR->next);
        free(soc->people->firstR);
        free(soc->people->next);
    }
    free(soc->people);
    free(soc);
}

/* Almacena una nueva persona. Si la persona existe, no hace nada
** Guarda una copia del nombre, no simplemente el puntero
*/
void addPerson(socialADT soc, const char * name){
    char * aux = name;


}

/* Si existe una persona con ese nombre, agrega la nueva relación
** Si la persona no existe, no hace nada
** Si related ya estaba relacionado, lo agrega repetido
** Almacena una copia de related, no simplemente el puntero
**
 */
void addRelated(socialADT soc, const char * name, const char * related){

}

/* Retorna una copia de los nombres relacionados con una persona
** en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si la persona no existe, retorna un vector que sólo tiene a NULL como
** elemento
 */
char ** related(const socialADT soc, const char * person){

}

/* Retorna una copia de los nombres de las personas en orden alfabético.
** Para marcar el final, después del último nombre se coloca NULL
** Si no hay personas, retorna un vector que sólo tiene a NULL como
** elemento
 */
char ** persons(const socialADT soc){

}
