#include <stdio.h>
#include <assert.h>
#include <string.h>

int apareados(const char *texto);

int main(void) {

    assert(apareados("") == 0);
    assert(apareados("()") == 0);
    assert(apareados("(())()(()())") == 0);
    assert(apareados("((((()))))") == 0);

    assert(apareados("(") != 0);
    assert(apareados(")") != 0);
    assert(apareados("(") != 0);
    assert(apareados("())") != 0);
    assert(apareados("()(") != 0);
    assert(apareados("((()))())(") != 0);

    printf("OK!\n");
    return 0;
}

int apareados(const char *texto) {
    if (*texto == '\0')
        return 0;
    int sum = apareados(texto+1);
    return ((*texto == '(' && sum >= 0) ? -1 : 0) + ((*texto == ')' && sum >= 0) ? 1 : 0) + sum;
}