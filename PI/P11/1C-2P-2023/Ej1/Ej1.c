#include "Ej1.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL 5
#define MAT_MAX 20

typedef struct plane {
    char registration[MAT_MAX];
    struct plane *next;
} plane;

typedef struct runway {
    char state;
    plane *first;
    size_t planeCount;
} runway;


typedef struct airportCDT {
    runway *runways;
    size_t runwayCount;
    size_t limit;
} airportCDT;


/* Crea un sistema de administración de pistas y despegues de aviones
** de un aeropuerto.
** El sistema inicia sin pistas.
*/
airportADT newAirport(void) {
    airportADT aux = malloc(sizeof(airportCDT));
    aux->runwayCount = 0;
    aux->runways = calloc(INITIAL + 1, sizeof(runway));
    aux->limit = INITIAL;
    return aux;
}

/* Agrega una pista de despegue con el identificador runwayId.
** La pista inicia sin aviones.
** Retorna la cantidad actual de pistas en el sistema o -1 si falla.
** Falla si existe una pista con el identificador runwayId.
*/
int addRunway(airportADT airportAdt, size_t runwayId) {
    if (runwayId > airportAdt->limit) {
        airportAdt->runways = realloc(airportAdt->runways, runwayId + 1);
        airportAdt->limit = runwayId;
    }
    if (runwayId == 0 || airportAdt->runways[runwayId].state)
        return -1;
    airportAdt->runways[runwayId].state = 1;
    airportAdt->runwayCount++;
    return airportAdt->runwayCount;
}


/* Agrega al final de la pista de despegue con el identificador
** runwayId al avión de matrícula registration
** y retorna la cantidad actual de aviones en la pista o -1 si falla.
** Falla si la pista no existe.
*/
int addPlaneToRunway(airportADT airportAdt, size_t runwayId, const char *registration) {
    if (runwayId > airportAdt->limit || airportAdt->runways[runwayId].state == 0)
        return -1;
    plane *aux = malloc(sizeof(*aux));
    strcpy(aux->registration, registration);
    aux->next = airportAdt->runways[runwayId].first;
    airportAdt->runways->first = aux;
    airportAdt->runways[runwayId].planeCount++;
    return airportAdt->runways[runwayId].planeCount;
}

static plane *takeOffRec(plane *list, char *ans) {
    if (list->next == NULL) {
        strcpy(ans, list->registration);
        free(list);
        return NULL;
    }
    list->next = takeOffRec(list->next, ans);
    return list;
}


/* Elimina al avión que se encuentra al principio de la pista de
** despegue con el identificador runwayId
** y retorna la matrícula del avión eliminado o NULL si falla.
** Falla si la pista no existe.
** Falla si no hay aviones en la pista.
*/
char *takeOff(airportADT airportAdt, size_t runwayId) {
    if (!airportAdt->runways[runwayId].planeCount || !airportAdt->runways[runwayId].state)
        return NULL;
    char ans[MAT_MAX + 1];
    airportAdt->runways[runwayId].first = takeOffRec(airportAdt->runways[runwayId].first, ans);
    airportAdt->runways[runwayId].planeCount--;
    return ans;
}


/* Retorna un arreglo con las matrículas de los aviones que se
** encuentran en la pista de despegue con el identificador
** runwayId en orden inverso al orden de despegue (el último elemento
** del arreglo debe coincidir con el valor de retorno de una
** invocación a la función takeOff sobre esa pista).
** El arreglo debe ** contar con una cadena vacía "" como marca de fin.
** Si la pista no existe retorna NULL.
*/
char **pendingFlights(airportADT airportAdt, size_t runwayId) {
    if (runwayId > airportAdt->limit || airportAdt->runways[runwayId].state == 0)
        return NULL;

    char **ans = malloc((airportAdt->runways[runwayId].planeCount + 1) * sizeof(char *));
    plane *aux = airportAdt->runways[runwayId].first;
    int i = 0;
    while (aux != NULL) {
        ans[i] = malloc(MAT_MAX + 1);
        strcpy(ans[i++], aux->registration);
        aux = aux->next;
    }
    ans[i] = "";
    return ans;
}


static void freeAirportRec(plane *list) {
    if (list == NULL)
        return;
    freeAirportRec(list->next);
    free(list);
}

/* Libera los recursos utilizados por el sistema de administración de
** pistas y despegues de aviones de un aeropuerto.
*/
void freeAirport(airportADT airportAdt) {
    for (int i = 0, j = 0; i < airportAdt->limit && j < airportAdt->runwayCount; ++i) {
        if (airportAdt->runways[i].state) {
            freeAirportRec(airportAdt->runways[i].first);
            j++;
        }
    }
    free(airportAdt->runways);
    free(airportAdt);
}
