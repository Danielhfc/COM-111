#ifndef PILHADIN_H
#define PILHADIN_H

 typedef struct elemento* Pilha;

 Pilha* PilhaCriar();
 int PilhaLiberar(Pilha* pi);
 int PilhaTamanho(Pilha* pi);
 int PilhaVazia(Pilha* pi);
 int PilhaCheia(Pilha* pi);
 int PilhaConsultaTopo(Pilha* pi, int *num);
 int PilhaInsereTopo(Pilha* pi, int num);
 int PilhaRemoveTopo(Pilha* pi);
 //Funcoes do trabalho
 int retiraImpares(Pilha* pi);
 float mediapares(Pilha* pi);
 int concatenaPilhas(Pilha* p1, Pilha* p2);
 int imprimePilha(Pilha* p);

#endif