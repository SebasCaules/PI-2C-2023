#include <stdio.h>

int main(void){
    int s1, s2, s3;
    for(s1=3; s1<=23; s1+=5){
        printf("%d ", s1);
    }
    printf("\n");

    for(s2=20; s2>=-10; s2-=6){
        printf("%d ", s2);
    }
    printf("\n");

    for(s3=19; s3<=51; s3+=8){
        printf("%d ", s3);
    }
    printf("\n");
}