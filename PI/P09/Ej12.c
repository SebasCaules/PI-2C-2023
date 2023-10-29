#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int balance(const char *str);


int main(void) {

    assert(balance("") == 0);
    assert(balance("((()))") == 0);
    assert(balance(")(") == 0);
    assert(balance("()()") == 0);
    assert(balance(")))(((") == 0);
    assert(balance("))) ((( ))( ()() ()()(") == 0);

    assert(balance(")") != 0);
    assert(balance("(") != 0);
    assert(balance(")()") != 0);
    assert(balance(" ) ") != 0);
    assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))") != 0);
    assert(balance("))))))))))))))))))))))))))))))))))))))))))))))))))))))((((((((((((") != 0);

    printf("OK!\n");
    return 0;
}

int balance(const char *str) {
    if(*str == '\0')
        return 0;
    if (*str == '(')
        return 1 + balance(++str);
    if (*str == ')')
        return balance(++str) - 1;
    return 0 + balance(++str);
}

