#ifndef PILHADIN_H
#define PILHADIN_H

struct aluno {
    int matricula;
    char nome[80];
    float n1, n2, n3;
 };
 typedef struct aluno Aluno;
 typedef struct elemento* Pilha;

 Pilha* PilhaCriar();
 int PilhaLiberar(Pilha* pi);
 int PilhaTamanho(Pilha* pi);
 int PilhaVazia(Pilha* pi);
 int PilhaCheia(Pilha* pi);
 int PilhaConsultaTopo(Pilha* pi, Aluno *al);
 int PilhaInsereTopo(Pilha* pi, Aluno al);
 int PilhaRemoveTopo(Pilha* pi);

#endif