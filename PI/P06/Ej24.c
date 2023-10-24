#include <stdio.h>
#include <assert.h>
#include <string.h>

#define L 60

void
eliminaBlancos(char cadena[]);

int main(void) {
    char s[60] = "   "; // cant impar de blancos
    eliminaBlancos(s);
    assert(strcmp(s, " ") == 0);

    eliminaBlancos(s);
    assert(strcmp(s, " ") == 0);

    strcpy(s, "  ");
    eliminaBlancos(s);
    assert(strcmp(s, " ") == 0);

    strcpy(s, " . . .  ");
    eliminaBlancos(s);
    assert(strcmp(s, " . . . ") == 0);

    strcpy(s, "");
    eliminaBlancos(s);
    assert(strcmp(s, "") == 0);

    strcpy(s, "sinblancos");
    eliminaBlancos(s);
    assert(strcmp(s, "sinblancos") == 0);


    printf("OK!\n");
    return 0;
}

void eliminaBlancos(char cadena[]) {
    unsigned int i, j;
    for (i = j = 0; cadena[i] != '\0'; ++i) {
        if (i == 0 || !(cadena[i] == 32 && cadena[i - 1] == 32))
            cadena[j++] = cadena[i];
    }
    cadena[j] = 0;
}