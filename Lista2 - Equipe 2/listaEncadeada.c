/*
 * File:   listaEncadeada.h
 * Equipe 2:
Daniel Henrique Ferreira Carvalho - 2019005426
Hugo Nunes Machado - 2019005678
Luiz Gustavo Piazza Honório - 2019016303
Márcio Gonçalves Pereira Filho  -  2019010355

Trabalho começa na linha 308
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listaEncadeada.h"

struct no
{
    int valor;
    struct no *prox;
};


struct lista
{
    struct no *inicio;
    int tamanho;
};

TipoLista *LCria()
{//F01
    TipoLista *le = (TipoLista*)malloc(sizeof(TipoLista));
    if (!le)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    le->inicio = NULL;
    le->tamanho = 0;
    return le;
}

void LInsereInicio(TipoLista *le, int valor)
{//F02
    Tipono *novoNo;

    //Aloca o nó
    novoNo = (Tipono*)malloc(sizeof(Tipono));
    if (!novoNo)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    //Inicializa
    novoNo->valor = valor;
    //Insere no início da lista
    novoNo->prox = le->inicio;
    le->inicio = novoNo;

    //atualiza o tamanho da lista
    le->tamanho++;

    return;
}

void LInsereFinal(TipoLista *le, int valor)
{//f03
    Tipono *novoNo;
    Tipono *aux;

    //Aloca o nó
    novoNo = (Tipono*)malloc(sizeof(Tipono));
    if (!novoNo)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    //Inicializa
    novoNo->valor = valor;
    novoNo->prox = NULL;
    //Procura seu local correto
    aux = le->inicio;
    //novoNo é o primeiro elemento da lista
    if (aux == NULL)
    {
        le->inicio = novoNo;
        le->tamanho++;
        return;
    }
    while (aux->prox != NULL)
    {
        aux = aux->prox;
    }
    novoNo->prox = aux->prox;
    aux->prox = novoNo;
    le->tamanho++;
    return;
}

void LInsereOrdenado(TipoLista *le, int valor)
{//f04
    Tipono *novoNo;
    Tipono *aux;

    //Aloca o nó
    novoNo = (Tipono*)malloc(sizeof(Tipono));
    if (!novoNo)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    //Inicializa
    novoNo->valor = valor;
    novoNo->prox = NULL;
    //Procura seu local correto
    aux = le->inicio;
    //novoNo é o primeiro elemento da lista
    if (aux == NULL || aux->valor > valor)
    {
        le->inicio = novoNo;
        novoNo->prox = aux;
        le->tamanho++;
        return;
    }
    while ((aux->prox != NULL) && (aux->prox->valor < valor))
    {
        aux = aux->prox;
    }
    novoNo->prox = aux->prox;
    aux->prox = novoNo;
    le->tamanho++;
    return;
}

int LConsultaElemento(TipoLista *le, int valor)
{//f05
    Tipono *aux = le->inicio;
    if (aux == NULL)
    {
        printf("\nLista Vazia\n");
        return 0;
    }
    while (aux !=NULL && aux->valor < valor)
    {
        aux = aux->prox;
    }
    if ((aux == NULL) || (aux->valor != valor))
        return 0;//Não Encontrado
    else
        return 1;// Encontrado
}
void LRemoveElemento(TipoLista *le, int valor)
{//F06
    Tipono *aux = le->inicio;
    Tipono *removido;
    if (aux == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }
    //elemento a ser removido é o primeiro da lista
    if (aux->valor == valor)
    {
        le->inicio = aux->prox;
        free(aux);
        return;
    }
    while ((aux->prox != NULL) && (aux->prox->valor < valor))
    {
        aux = aux->prox;
    }
    if (aux->prox == NULL || (aux->prox->valor) > valor)
    {
        printf("\nElemento nao encontrado na lista\n");
    }
    else
    {
        removido = aux->prox;
        aux->prox = aux->prox->prox;
        le->tamanho--;
        free(removido);
    }
    return;
}
static Tipono* retiranos_rec(Tipono *no, int valor)
{//F07aux
    Tipono *removido;
    if (no != NULL)
    {
      if(no->valor == valor){
          removido = no;
          no = no->prox;
          free(removido);
      }
      else {
         /* retira de sub-lista */
         no->prox = retiranos_rec(no->prox,valor);}
    }
    return no;
}
void LRemoveElemento_rec(TipoLista *le, int valor)
{//F07
   le->inicio = retiranos_rec(le->inicio,valor);
}
void FLVazia(TipoLista *le)
{//F08
    Tipono *aux = le->inicio;
    Tipono *removido;
    if (aux == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }

    while(aux != NULL)
    {
        //printf("\nremove %d \n",aux->valor);
        removido = aux;
        aux = aux->prox;
        le->tamanho--;
        free(removido);
    }
    le->inicio = NULL;
    return;
}
static void liberanos_rec(Tipono *no)
{//F09aux
    if(no != NULL){
        liberanos_rec(no->prox);
        free(no);
    }
}
void FLVazia_rec(TipoLista *le)
{//F09
    liberanos_rec(le->inicio);
    le->inicio = NULL;
    return;
}
int LVazia( TipoLista* le)
{//F10
    if (le->inicio == NULL)
       return true; // lista vazia
    else
       return false; // lista não vazia
}

void LImprime(TipoLista *le)
{//F11
    Tipono *aux = le->inicio;
    if (aux == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }
    while(aux != NULL)
    {
        printf("%d\t", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    return;
}
static void imprimenos_rec(Tipono *no)
{//F12aux
    if (no != NULL)
    {
        printf("%d\t", no->valor);
        imprimenos_rec(no->prox);
    }
    printf("\n");
    return;
}
void LImprime_rec(TipoLista *le)
{//F12
     if (le->inicio == NULL)
        printf("\nLista Vazia\n");
     else
        imprimenos_rec(le->inicio);
}

int LTamanho(TipoLista* le)
{//F13
      return le->tamanho;
}

int LSoma(Tipono *no)
{//F14
    if (no == NULL)
        return 0;
    return no->valor + LSoma(no->prox);
}

Tipono *LRetornaInicio(TipoLista *l)
{//F15
    return l->inicio;
}

void NoDisplay(Tipono *no)
{//F16
    if (no == NULL){
       printf("NULL");
      return;
    }
    printf("%d ", no->valor);
}
/*-----------------------------------------------------------------------------------------------------------------------------
        Trabalho para casa 02 */

//Cria uma lista idêntica àquela passada por parâmetro
TipoLista *LDuplica(TipoLista *le){
    int i;
    TipoLista *le2 = LCria();
    Tipono *aux = le->inicio;

        for(i=0;i<le->tamanho;i++){
            LInsereFinal(le2, aux->valor);
            aux = aux->prox;
        }
        return le2;
}

//Coloca os elementos da lista 2 no final da lista 1
TipoLista *LEConcatena(TipoLista *le1 ,TipoLista *le2){
int i;
Tipono *aux = le2->inicio;
    for(i=0;i<le2->tamanho;i++){
            LInsereFinal(le1, aux->valor);
            aux = aux->prox;
        }
        return le1;
}

//Cria uma lista nova com base no vetor dado
TipoLista *LCriaVetor(int N, int *vetor){
int i;
TipoLista *le3 = LCria();
    if(N!=0)
        for(i=N-1;i>=0;i--)
            LInsereInicio(le3, vetor[i]);
return le3;
}

// Encontra o número dado na lista e cria uma nova a partir do elemento seguinte
TipoLista *LEDivide(int n, TipoLista *le){
int i=0;
TipoLista *le4 = LCria();
Tipono *aux = le->inicio;

    for(i=0;i<le->tamanho;i++){
        if(aux->valor!=n)
            aux = aux->prox;
        else break;
    }

    while(i < le->tamanho - 1){
        i++;
        aux = aux->prox;
        LInsereFinal(le4, aux->valor);

    }

return le4;
}

// Inverte a ordem dos valores da lista utilizando um vetor como auxiliar.
void LInverte(TipoLista *le){
int i, tamanho, *vetor;
Tipono *aux = le->inicio;
tamanho = le->tamanho;
vetor = (int *) malloc(tamanho * sizeof(int));

    for(i=0;i < tamanho ; i++){
        vetor[i] = aux->valor;
        aux = aux->prox;
    }

    FLVazia(le);

    for(i=0;i < tamanho ; i++){
        LInsereInicio(le, vetor[i]);
    }
}
