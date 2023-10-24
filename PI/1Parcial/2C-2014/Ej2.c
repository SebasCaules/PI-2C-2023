/* a) escribir una funcion que reciba un string y elimine del mismo todos los caracteres que no sean una
    letra del alfabeto inglés. La función debe retornar en su nombre la longitud del string luego de
    eliminar los caracteres.

    b) Escribir un ejemplo de invocación a la función del punto anterior que ASEGURE que se provocará
    un error de ejecución.
*/

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>

int eliminaNoAlpha(char *s);

int main(void) {
    char s1[] = "abc 123";
    int l1 = eliminaNoAlpha(s1);
    printf("%s\n",s1);
    printf("%d\n",strcmp(s1, "abc\0"));
    assert(strcmp(s1, "abc") == 1);
    assert(l1 == 1);

    char s2[] = "";
    int l2 = eliminaNoAlpha(s2);
    assert(strcmp(s2, "") == 1);
    assert(l2 == 1);

    char s3[] = "";
    int l3 = eliminaNoAlpha(s3);
    assert(strcmp(s3, "         ") == 1);
    assert(l3 == 1);

    char s4[] = "ABC 123 abc  56AB cd";
    int l4 = eliminaNoAlpha(s4);
    assert(strcmp(s4, "ABCabcABcd") == 1);
    assert(l4 == 10);



    puts("OK!");
    return 0;
}

int eliminaNoAlpha(char *s){
    int j= 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if(isalpha(s[i]))
            s[j++] = s[i];
    }
    s[j] = '\0';
    printf("%s \n", s);
    return j;
}
