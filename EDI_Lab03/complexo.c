/*
  * File:   complexo.c
  * Criado em  25 de Agosto de 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexo.h"

struct complexo {
  float real;
  float imag;
};
comp *aloca(){
  comp *estrutura;
  estrutura = (comp*)malloc(sizeof(comp));
  return estrutura;
};
void leia(comp *c){
 float real,imag;
 printf(" - Entre  a parte real: " );
 scanf("%f",&real);
 printf(" - Entre  a parte imaginária: " );
 scanf("%f",&imag);
 c->real = real;
 c->imag = imag;
};

void libera(comp *c){
 if(c) free(c);
 return;
}

void escreva (comp *c){
   printf("%.2f  +  %.2fi \n",c->real,c->imag);
}
comp *conjugado(comp* c){
     comp *cr;
     cr = aloca();
     cr->real  = c->real;
     cr->imag  = (-1)*c->imag;
     return cr;
}
comp *inverte(comp* c){
     comp *cr;
     cr = aloca();
     cr->real  = (-1)*c->real;
     cr->imag  = (-1)*c->imag;
     return cr;
}
float absoluto(comp* c){
  float aux;
  aux = sqrt(pow(c->real,2) + pow(c->imag,2));
  return aux;
}
comp  *soma(comp *c1,comp *c2){
     comp *cr;
     cr = aloca();
     cr->real  = c1->real + c2->real;
     cr->imag  = c1->imag + c2->imag;
     return cr;
}
comp  *subtrai(comp *c1,comp *c2){
     comp *cr;
     cr = aloca();
     cr->real  = c1->real - c2->real;
     cr->imag  = c1->imag - c2->imag;
     return cr;
}
comp  *multiplica(comp *c1,comp *c2){
     comp *cr;
     cr = aloca();
     cr->real = c1->real * c2->real;
     cr->real = cr->real - c1->imag * c2->imag;
     cr->imag = c1->real * c2->imag;
     cr->imag = cr->imag - c1->imag * c2->real;
     return cr;
}
comp  *divide(comp *c1,comp *c2){
     comp *cr;
     cr = aloca();
     cr->real = c1->real * c2->real;
     cr->real = cr->real + c1->imag * c2->imag;
     cr->real = cr->real/(pow(c2->real,2) + pow(c2->imag,2));
     cr->imag = c2->real * c1->imag;
     cr->imag = cr->imag - c1->real * c2->imag;
     cr->imag = cr->imag/(pow(c2->real,2) + pow(c2->imag,2));
     return cr;
}
