
#include <stdio.h>

#define macroswap(t, x, y) do { t temp = x; x = y; y = temp; } while(0)

int main(void) {
    int a = 5, b = 10;
    printf("Before swap: a = %d, b = %d\n", a, b);
    macroswap(int, a, b);
    printf("After swap: a = %d, b = %d\n", a, b);

    double x = 2.5, y = 7.3;
    printf("Before swap: x = %lf, y = %lf\n", x, y);
    macroswap(double, x, y);
    printf("After swap: x = %lf, y = %lf\n", x, y);

    return 0;
}