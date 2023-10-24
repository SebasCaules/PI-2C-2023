#include <stdio.h>
#include <math.h>

#define EPSILON 0.000001

int factorial(int n) {
    int res = 1;
    for (; n > 0; n--) {
        res *= n;
    }
    return res;
}

int aproximacion(int x) {
    int n = 0;
    double acum = 0;
    while ((acum - x) <= EPSILON) {
        acum += ((1 / factorial(n)) * pow(x, n));
        n++;
    }
    return acum;
}

int main(void) {
    int b, c;
    b = factorial(0);
    printf("%d\n", b);

    c = aproximacion(4);
    printf("%g", c);
}