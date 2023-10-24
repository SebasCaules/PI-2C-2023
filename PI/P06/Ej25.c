#include <stdio.h>
#include <assert.h>
#include <string.h>

unsigned int
copiaSubVector(const char *arregloIn, char *arregloOut, unsigned int desde, unsigned int hasta, unsigned int dimMax);

int main(void) {
    char s[100];
    assert(copiaSubVector("un texto", s, 0, 0, 1) == 0);
    printf("%s str 1\n", s);
    printf("%d\n", strcmp(s, ""));
    assert(strcmp(s, "") == 0);
    assert(copiaSubVector("un texto", s, 0, 0, 10) == 1);
    printf("%s str2\n", s);
    assert(strcmp(s, "u") == 0);
    assert(copiaSubVector("un texto", s, 0, 10, 1) == 0);
    assert(strcmp(s, "") == 0);

    assert(copiaSubVector("un texto", s, 45, 130, 1) == 0);


    assert(copiaSubVector("un texto", s, 0, 130, 2) == 1);
    assert(strcmp(s, "u") == 0);

    assert(copiaSubVector("un texto", s, 0, 130, 202) == 8);
    assert(strcmp(s, "un texto") == 0);

    assert(copiaSubVector("un texto", s, 0, 7, 202) == 8);
    assert(strcmp(s, "un texto") == 0);

    assert(copiaSubVector("un texto", s, 0, 7, 9) == 8);
    assert(strcmp(s, "un texto") == 0);

    assert(copiaSubVector("un texto", s, 2, 5, 8) == 4);
    assert(strcmp(s, " tex") == 0);

    assert(copiaSubVector("un texto", s, 45000, 130000, 10) == 0);

    printf("OK!\n");
    return 0;
}


unsigned int
copiaSubVector(const char *arregloIn, char *arregloOut, unsigned int desde, unsigned int hasta, unsigned int dimMax) {

    if ((hasta - desde) > dimMax)
        hasta = dimMax - 1;

    if (desde > dimMax || hasta > dimMax || hasta == 0)
        return 0;
    //if (hasta  == 0)
      //  arregloOut ="";

    unsigned int i, j;
    for (i = desde, j = 0; i <= hasta && j <= dimMax; ++i) {
        arregloOut[j++] = arregloIn[i];
    }
    arregloOut[j++] = 0;
    j--;
    return j;


}
