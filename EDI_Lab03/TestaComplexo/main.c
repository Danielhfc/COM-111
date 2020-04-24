/*
  * File:   testacomplexo.c
  * Criado em  25 de Agosto de 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexo.h"

int main(){
  comp *comp1;
  comp *comp2;
  comp1 = aloca();
  printf("Entre com o complexo1 \n" );
  leia(comp1);
  printf("\nComplexo1: " );
  escreva (comp1);
  printf("\n");
  comp2 = aloca();
  printf("Entre com o complexo2 \n" );
  leia(comp2);
  printf("\nComplexo2: " );
  escreva (comp2);
  printf("\n");
  printf("Conjugado do complexo1:  " );
  escreva (conjugado(comp1));
  printf("\n");
  printf("Conjugado do complexo2:  " );
  escreva (conjugado(comp2));
  printf("\n");
  printf("Inversão do complexo1:  " );
  escreva (inverte(comp1));
  printf("\n");
  printf("Inversão do complexo2:  " );
  escreva (inverte(comp2));
  printf("\n");
  printf("Absoluto do  complexo1:  " );
  printf("%.2f \n\n", absoluto(comp1));
  printf("Absoluto do  complexo2:  " );
  printf("%.2f \n\n", absoluto(comp2));
  printf("complexo1 + complexo2:  " );
  escreva (soma(comp1,comp2));
  printf("\n");
  printf("complexo1 - complexo2:  " );
  escreva (subtrai(comp1,comp2));
  printf("\n");
  printf("complexo1 * complexo2:  " );
  escreva (multiplica(comp1,comp2));
  printf("\n");
  printf("complexo1 : complexo2:  " );
  escreva (divide(comp1,comp2));

  libera(comp1);
  libera(comp2);
  return 0;

}
