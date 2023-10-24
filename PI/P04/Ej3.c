#include <stdio.h>
#define pi 3.14
#define volumenEsfera(radio) (((4)*(pi)*((radio)*(radio)*(radio)))/3)


int main(void){
    int radio;
    for(radio=1; radio <= 10; radio++){
        printf("El volumen de la esfera de radio %d es %f \n", radio, volumenEsfera(radio));
    }
}