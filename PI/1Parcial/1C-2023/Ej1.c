#include <stdio.h>
#include <assert.h>
#include <string.h>


void elimina(char *s1,const char *s2,const char *s3);

int main(void) {
    char s[] = "abc";
    elimina(s, "123", "cab");
    assert(strcmp(s, "abc") == 0); // No se eliminan caracteres

    printf("assert 2\n");
    elimina(s, "axc", "xbc");
    // Se elimina la a porque está en s2 en la misma posición
    // se elimina la b porque está en s3 en la misma posición
    // Se elimina la c porque está en s2 o en s3 en la misma posición
    assert(strcmp(s, "") == 0);

    char t[] = "abc 123";
    elimina(t, "b", "1");
    assert(strcmp(t, "abc 123") == 0);  // No se eliminan caracteres

    elimina(t, "aaaaaaaaaaaaaaaaaaaaaa", "2222222222222222222");
    assert(strcmp(t, "bc 13") == 0);

    elimina(t, "", "");  // No se eliminan caracteres
    assert(strcmp(t, "bc 13") == 0);

    puts("OK!");
    return 0;
}


/* s1 = [H, O, L, A]
 * s2 = [H, A, L, O]
 * s3 = [A, O, L, H]
 *
 * --> s1 = [L, A]
 *
 * */

int chequeaString(const char *s1, const char *s2){
    return (*s1 == *s2);
}

void eliminaPos(char * s1, const char * s2){
    int j = 0;
    for (int i = 0; s1[i] != '\0'; ++i) {
        if(s1[i] != s2[i])
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

void elimina(char *s1,const char *s2,const char *s3){
    eliminaPos(s1, s2);
    eliminaPos(s1,s3);

    printf("%s\n", s1);

}