#include <stdio.h>
#include <stdlib.h>

#define BLOQUE 50


int main(void) {
    char *sVec = NULL;
    int c;
    int dim = 0;

    while ((c = getchar()) != '\n') {
        if (dim % BLOQUE == 0)
            sVec = realloc(sVec, (dim + BLOQUE) * sizeof(int));
        sVec[dim] = c;
        dim++;
    }

    for (int i = 0; i < dim; ++i) {
        printf("%c ", sVec[i]);
    }

    free(sVec);
}
