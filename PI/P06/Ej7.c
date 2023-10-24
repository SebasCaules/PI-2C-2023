#include <stdio.h>
#include <assert.h>

void unirArreglos ( const int v1[], const int v2[], int unirArr[]);

void check(const int v1[], const int v2[]) {
    int i;
    for(i=0; v1[i] != -1; i++)
        assert(v1[i]==v2[i]);
    assert(v1[i]==-1);
    assert(v2[i]==-1);
}

int main(void) {
    int v1[] = { 1, 5, 15, 30, 35, 45, 55, -1};
    int v2[] = {-1};
    int v3[] = { 1, -1};
    int v4[] = { 2, 3, 15, 16, 33, 35, 45, 65, -1};
    int dimRes;
    int res[30];
    int v100[] = {1,2,3,-1};
    int v200[] = {1,2,3,4,-1};
    int unirArr[1];
    unirArreglos(v100,v200, unirArr);

/*
    unirArreglos(v1, v2, res);
    check(v1, res);

    unirArreglos(v2, v2, res);
    check(v2, res);

    unirArreglos(v1, v1, res);
    check(v1, res);

    unirArreglos(v1, v3, res);
    check(v1, res);

    int expected[] = {1, 2, 3, 5, 15, 16, 30, 33, 35, 45, 55, 65, -1};
    unirArreglos(v1, v4, res);
    check(expected, res);

    printf("OK!\n");
    return 0;*/
}

void unirArreglos(const int v1[], const int v2[], int unionArr[]) {
    int dimU = 0;
    for (int i = 0; v1[i] != -1 || v2[i] != -1; i++) {
        if (v1[i] != -1){
            printf("if");
            if( v1[i] < v2[i]){
                unionArr[dimU++] = v1[i];
            }else{
                unionArr[dimU++] = v2[i];
            }
        } else if(v2[i] != -1){
            printf("else if");
            unionArr[dimU++] = v2[i];
        }else{
            ;
        }
    }
    unionArr[dimU++] = -1;

    for(int c =0; c<dimU; c++){
        printf("%d ", unionArr[c]);
    }
}
