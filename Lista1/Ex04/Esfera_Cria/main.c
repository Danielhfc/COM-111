#include <stdio.h>
#include <stdlib.h>
#include "Esfera.h"

int main(){
    float area, volume, raio;
    esfera *r1;

    r1 = esfera_cria(2.0);
    raio = esfera_acessa(r1);
    printf("Raio da esfera eh: %.2f\n", raio);
    area = esfera_area(r1);
    printf("A area da esfera eh: %.2f\n", area);
    volume = esfera_volume(r1);
    printf("O volume da esfera eh: %.2f\n", volume);


}
