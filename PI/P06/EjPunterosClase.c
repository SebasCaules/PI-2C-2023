#include <stdio.h>

int conversion(int seg, int *h, int *m, int *s) {
    *h = seg / 3600;
    seg %= 3600;
    *m = seg/60;
    seg %= 60;
    *s = seg;
    return 0;
}

int main(void){
    int h, m, s;
    int seg = 3661;
    conversion(seg, &h, &m, &s);
    printf("%d segundos son %d horas con %d minutos y %d segundos.", seg, h, m, s);
}