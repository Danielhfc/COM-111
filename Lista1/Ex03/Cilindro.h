#ifndef Cilindro_H_INCLUDED
#define Cilindro_H_INCLUDED

typedef struct cilindro Cilindro;

Cilindro *cilindro_cria(float r, float h);

void cilindro_libera(Cilindro *c);

void cilindro_atribui(Cilindro *c,float a,float h);

float cilindro_acessa_r(Cilindro *c);

float cilindro_acessa_h(Cilindro *c);

float cilindro_volume(Cilindro *c);


#endif // Cilindro_H_INCLUDED
