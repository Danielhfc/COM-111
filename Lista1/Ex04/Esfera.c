#include <stdlib.h>
#include "Esfera.h" //incluindo a biblioteca .h

struct esfera{
    float raio;
};

//cria a esfera
esfera *esfera_cria(float raio){
    esfera *r = (esfera*) malloc(sizeof(esfera));
    if(r != NULL){
        r->raio = raio;
    }
    return r;
}

//liberar cubo
void esfera_libera(esfera *r){
    free(r);
}

//acessa o valor "raio" de esfera
float esfera_acessa(esfera *r){
    return r->raio;
}

//atribui o valor "raio" de uma esfera
void esfera_atribui(esfera *r, float raio){
    r->raio = raio;
}

//calcula a area da esfera
float esfera_area(esfera *r){
    float area = 4 * 3.14 * r->raio * r->raio;
    return area;
}

//calcula o volume de uma esfera
float esfera_volume(esfera *r){
    float volume = 4/3 * 3.14 * r->raio * r->raio * r->raio;
    return volume;
}
