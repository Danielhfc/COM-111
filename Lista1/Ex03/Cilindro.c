#include <stdlib.h>
#include "Cilindro.h"

//Definição TAD
struct cilindro{
    float r, h;
};

//Cria o cilindro
Cilindro *cilindro_cria(float r, float h){
    Cilindro *c = (Cilindro*) malloc(sizeof(Cilindro));
        if(c!=NULL){
            c->r = r;
            c->h = h;
        }
return c;
}

//Libera o cilindro
void cilindro_libera(Cilindro *c){
    free(c);
}

// Coloca valores para o raio e a altura do cubo
void cilindro_atribui(Cilindro *c,float r,float h){
    c->r = r;
    c->h = h;
}

// retorna o valor do raio
float cilindro_acessa_r(Cilindro *c){
    return c->r;
}

// retorna o valor da altura
float cilindro_acessa_h(Cilindro *c){
    return c->h;
}

// retorna o valor do volume
float cilindro_volume(Cilindro *c){
    return 3.14 * c->r * c->r * c->h;
}
