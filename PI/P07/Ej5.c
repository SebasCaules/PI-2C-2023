#include <assert.h>
#include <stdio.h>
#include <string.h>
#define MAX_ALUMNOS 40

#define MAX_ALUMNOS 40

typedef char *TAlumnos[MAX_ALUMNOS];
typedef char TCurso[];
// Cambiar de acuerdo al tipo elegido
// Si usan "matriz" de chars debe quedar
// typedef char TAlumnos[MAX_ALUMNOS][MAX_LARGO];

// Si usan vector de punteros a char debe quedar
// typedef char * TAlumnos[MAX_ALUMNOS];

void separaCursos(TAlumnos, TCurso, TAlumnos cursoG, TAlumnos cursoH);

int main(void){

    TAlumnos alumnos={"Juan", "Pedro", "Martin", ""}, cursoG, cursoH;
    TCurso curso={'H', 'G', 'H', 0};
    separaCursos(alumnos, curso, cursoG, cursoH);
    printf("%s \n", alumnos[0]);
    printf("%c \n", curso[0]);
    printf("%s \n", cursoH[0]);
    printf("%s \n", cursoG[0]);

    assert(!strcmp(cursoG[0], alumnos[1]));
    assert(!strcmp(cursoH[0], alumnos[0]));
    assert(!strcmp(cursoH[1], alumnos[2]));
    assert(!strcmp(cursoG[1], alumnos[3]) && !strcmp(cursoH[2], alumnos[3]));   // Terminan con ""

    alumnos[0]=""; curso[0]=0;  // Depende del tipo de alumnos, esta linea puede ser: "alumnos[0][0]=0; curso[0]=0;"
    separaCursos(alumnos, curso, cursoG, cursoH);
    assert(!strcmp(cursoG[0], alumnos[0]) && !strcmp(cursoH[0], alumnos[0]));

    puts("OK!");
    return 0;
}

void separaCursos(TAlumnos alumnos, TCurso cursos, TAlumnos cursoG, TAlumnos cursoH)
{
    int i = 0;
    int indG = 0, indH = 0; /* indices de cursoG y cursoH */

    while (alumnos[i][0] != 0)
    {
        if (cursos[i] == 'G')
            cursoG[indG++] = alumnos[i];
        else
            cursoH[indH++] = alumnos[i];
        i++;
    }
    cursoG[indG] = alumnos[i]; /* Ambas opciones son correctas ya que */
    cursoH[indH] = "";         /* representan el string nulo */
}