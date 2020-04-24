#include <stdio.h>
#include <math.h>
// Função :  Números complexos sem TDA
// Autor :
// Data : 26/8/2019
// Seção de Declarações
typedef struct {
  float real;
  float imag;
 } complexo;

void leia(complexo*);
void escreva (complexo);
complexo soma(complexo,complexo);
complexo subtrai(complexo,complexo);
complexo multiplica(complexo,complexo);
complexo divide(complexo,complexo);
complexo conjugado(complexo);
complexo inverte(complexo comp);
float absoluto(complexo);

int  main(){
 // Aloca Memória para  complexo 1:
    complexo comp1;

 // Lê  complexo 1:
    printf("Forneça o Complexo1:  \n" );
    leia(&comp1);

 // Escreve  complexo 1:
    printf("Complexo1:  " );
    escreva (comp1);

 // Aloca Memória para  complexo 2:
    complexo comp2;

 // Lê  complexo 2:
    printf("Forneça o Complexo2:  \n" );
    leia(&comp2);

 // Escreve  complexo 2:
    printf("Complexo2:  " );
    escreva (comp2);

 // Escreve  soma: complexo 1 + complexo 2:
    printf("Complexo1 + complexo2:  " );
    escreva (soma(comp1,comp2));

 // Escreve  subtração: complexo 1 - complexo 2
    printf("Complexo1 - complexo2:  " );
    escreva (subtrai(comp1,comp2));

 // Conjugado  do complexo 1 :
    printf("Conjugado do Complexo1:  " );
    escreva (conjugado(comp1));

 // Conjugado  do complexo 2 :
    printf("Conjugado do Complexo2:  " );
    escreva (conjugado(comp2));

 // Valor absoluto  do complexo 1 :
    printf("Absoluto do Complexo1:  " );
    printf("%.2f \n\n",absoluto(comp1));

 // Valor Absoluto  do complexo 2 :
    printf("Absoluto do Complexo2:  " );
    printf("%.2f \n\n",absoluto(comp2));

 // Inversão  do complexo 1 :
    printf("Inversão do Complexo1:  " );
    escreva (inverte(comp1));

 // Inversão  do complexo 2 :
    printf("Inversão do Complexo2:  " );
    escreva (inverte(comp2));

 // Escreve  Multiplicação: complexo 1 * complexo 2
    printf("Complexo1 * complexo2:  " );
    escreva (multiplica(comp1,comp2));

 // Escreve  Divisão: complexo 1 - complexo 2
    printf("Complexo1 : complexo2:  " );
    escreva (divide(comp1,comp2));

  return 0;
 }
   void leia(complexo *comp){
      float real,imag;
      printf(" -Entre  a parte real: " );
      scanf("%f",&real);
      printf(" -Entre  a parte imaginária: " );
      scanf("%f",&imag);
      comp->real = real;
      comp->imag = imag;
  }
  void escreva (complexo comp){
      printf("%.2f  +  %.2fi \n\n",comp.real,comp.imag);
  }
  complexo soma(complexo comp1,complexo comp2){
    complexo comp;
    comp.real = comp1.real + comp2.real;
    comp.imag = comp1.imag + comp2.imag;
    return comp;
  }
  complexo subtrai(complexo comp1,complexo comp2){
    complexo comp;
    comp.real = comp1.real - comp2.real;
    comp.imag = comp1.imag - comp2.imag;
    return comp;
  }
  complexo multiplica(complexo comp1,complexo comp2){
    complexo comp;
    comp.real = comp1.real * comp2.real - comp1.imag * comp2.imag;
    comp.imag = comp1.real * comp2.imag - comp1.imag * comp2.real;
    return comp;
  }
  complexo divide(complexo comp1,complexo comp2){
    complexo comp;
    comp.real = (comp1.real * comp2.real + comp1.imag * comp2.imag)/(pow(comp2.real,2) + pow(comp2.imag,2));
    comp.imag = (comp2.real * comp1.imag - comp1.real * comp2.imag)/(pow(comp2.real,2)  + pow(comp2.imag,2));
    return comp;
  }
  complexo conjugado(complexo comp){
    complexo aux;
    aux.real = comp.real;
    aux.imag = (-1)*comp.imag;
    return aux;
  }
  complexo inverte(complexo comp){
    complexo aux;
    aux.real = (-1)*comp.real;
    aux.imag = (-1)*comp.imag;
    return aux;
  }
  float absoluto(complexo comp){
    float aux;
    aux = sqrt(pow(comp.real,2) + pow(comp.imag,2));
    return aux;
  }

