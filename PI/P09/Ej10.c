#include <stdio.h>
#include <assert.h>
#include <string.h>

void invierte(char *sEntrada, char *sSalida);

int main(void) {
    char s[20] = {0};

    invierte("1234567890", s);
    assert(strcmp(s, "0987654321")==0);

    memset(s, 0, 20);
    invierte("", s);
    assert(strcmp(s, "")==0);

    memset(s, 0, 20);
    invierte("a", s);
    assert(strcmp(s, "a")==0);

    memset(s, 0, 20);
    invierte("ab", s);
    assert(strcmp(s, "ba")==0);

    memset(s, 0, 20);
    invierte("abc", s);
    assert(strcmp(s, "cba")==0);

    printf ("OK!\n");
    return 0;
}


void invierte(char *sEntrada, char *sSalida){
    printf("%s\n", sEntrada);
    if(*sEntrada == '\0'){
        *sSalida = *(sEntrada-2);
        printf("%s salida\n", sSalida);
        sSalida++;
        invierte(sEntrada, sSalida);
    }

    sEntrada++;
    invierte(sEntrada, sSalida);
    printf("%s\n", sEntrada);
}