#include <stdio.h>
#include <assert.h>
#include <ctype.h>

int bienformado(char *s);

int main(void) {
    char *zero[] = {"abcd4a10bb2", "", "0000", "a1", "abc3", "0a1"};

    char *not_zero[] = {"a", "1", "a2", "abc2", "abc4", "abc33", "0123", "2aa", "$1", "@@2", "abcd22", "@@"};

    for (int i = 0; i < sizeof(zero) / sizeof(zero[0]); i++) {
        printf("%s\t", zero[i]);
        printf("%d\n", bienformado(zero[i]));
//        assert(bienformado(zero[i])==0);
    }
    printf("\n");

    for (int i = 0; i < sizeof(not_zero) / sizeof(not_zero[0]); i++) {
        printf("%s\t", not_zero[i]);
        printf("%d\n", bienformado(not_zero[i]));
//        assert(bienformado(not_zero[i]) !=0);
    }

//   puts("OK!");
    return 0;
}

int bienformado(char *s) {
    if (*s == '\0')
        return 0;
    int sum = bienformado(++s);
    if (isalpha(*s))
        return 1 + sum;
    if(isdigit(*s) && isalpha(*(s-1)) && *s != 0)
        return sum - *s;
    if(*s == 0 && !isalpha(*(s-1)))
        return 0+sum;
    return 0+sum;
}