/*
 * File:   listaDuplaEncadeada.c
 * Author:
 *
 * Created
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listaDuplaEncadeada.h"

struct noDupla {
    int valor;
    struct noDupla *prox;  // ponteiro p/ à direita
    struct noDupla *ant;   // ponteiro p/ à esquerda
};

struct listaDupla {
    struct noDupla *inicio;  // ponteiro p/ primeiro
    struct noDupla *fim;     // ponteiro p/ ultimo
    int tamanho;
};

TipoLDE *LDECria()
{
   TipoLDE *lde = (TipoLDE*)malloc(sizeof(TipoLDE));
   if (!lde)
   {
      printf("Erro ao alocar memoria\n");
      exit(1);
   }
   lde->inicio = NULL;
   lde->fim    = NULL;
   lde->tamanho = 0;
   return lde;
}

void LDEInsereInicio(TipoLDE *lde, int valor)
{
    TipoNDE *novoNo;
    TipoNDE *aux;
    //Aloca o nó
    novoNo = (TipoNDE*)malloc(sizeof(TipoNDE));
    if (!novoNo)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    //Inicializa
    novoNo->valor = valor;
    aux = lde->inicio;
    //novoNo é o primeiro elemento da lista
    if (aux == NULL)
    {
        novoNo->ant = NULL;
        novoNo->prox = NULL;
        lde->inicio = novoNo;
        lde->fim = novoNo;
        lde->tamanho++;
        return;
    }
    //novoNo não é o primeiro elemento da lista
    novoNo->prox = aux;
    aux->ant = novoNo;
    lde->inicio = novoNo;

    lde->tamanho++;
    return;
}

void LDEInsereFinal(TipoLDE *lde, int valor)
{
    TipoNDE *novoNo;
    TipoNDE *aux;

    //Aloca o nó
    novoNo = (TipoNDE*)malloc(sizeof(TipoNDE));
    if (!novoNo)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    //Inicializa
    novoNo->valor = valor;
    aux = lde->fim;
    //novoNo é o primeiro elemento da lista
    if (aux == NULL)
    {
        novoNo->ant = NULL;
        novoNo->prox = NULL;
        lde->inicio = novoNo;
        lde->fim = novoNo;
        lde->tamanho++;
        return;
    }
    //novoNo Não é o primeiro elemento da lista
    novoNo->prox = NULL;
    novoNo->ant = lde->fim;
    novoNo->ant->prox = novoNo;
    lde->fim = novoNo;
    lde->tamanho++;
    return;
}

void LDEInsereOrdenado(TipoLDE *lde, int valor)
{
    TipoNDE *novoNo;
    TipoNDE *aux;

    //Aloca o nó
    novoNo = (TipoNDE*)malloc(sizeof(TipoNDE));
    if (!novoNo)
    {
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    //Inicializa
    novoNo->valor = valor;
    //novoNo->ant = NULL;
    //novoNo->prox = NULL;
    //Procura seu local correto
    aux = lde->inicio;
    //novoNo é o primeiro elemento da lista
    if (aux == NULL || aux->valor > valor)
    {
        lde->inicio  = novoNo;
        novoNo->prox = aux;
        if (aux != NULL)
            aux->ant = novoNo;
        else
            lde->fim = novoNo;
        lde->tamanho++;
        return;
    }
    //novoNo Não é o primeiro elemento da lista
    while ((aux->prox != NULL) && (aux->prox->valor < valor))
    {
        aux = aux->prox;
    }
    novoNo->prox = aux->prox;
    novoNo->ant = aux;
    aux->prox = novoNo;
    if (novoNo->prox != NULL)
        novoNo->prox->ant = novoNo;
    else
        lde->fim = novoNo;
    lde->tamanho++;
    return;
}

void LDEImprimeInicio(TipoLDE *lde)
{
    TipoNDE *aux = lde->inicio;
    //Lista vazia
    if (aux == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }
    //Lista não vazia
    while(aux != NULL)
    {
        printf("%d\t", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    return;
}

void LDEImprimeFim(TipoLDE *lde)
{
    TipoNDE *aux = lde->fim;
    if (aux == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }
    while(aux != NULL)
    {
        printf("%d\t", aux->valor);
        aux = aux->ant;
    }
    printf("\n");
    return;
}

TipoNDE *LDERetornaInicio(TipoLDE *lde)
{
    return lde->inicio;
}

TipoNDE *LDERetornaFim(TipoLDE *lde)
{
    return lde->fim;
}

int LDETamanho(TipoLDE* lde)
{
      return lde->tamanho;
}

void NDEDisplay(TipoNDE *no)
{
    if (no == NULL){
       printf("NULL");
       return;
    }
    printf("%d ", no->valor);
}

int LDEConsultaElemento(TipoLDE *lde, int valor)
{
    TipoNDE *aux = lde->inicio;
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
        return false;//Não Encontrado
    else
        return true;// Encontrado
}

void LDERemoveElemento(TipoLDE *lde, int valor)
{
    TipoNDE *aux = lde->inicio;
    TipoNDE *removido;
    if (aux == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }
    if (aux->valor == valor)
    {
        //elemento a ser removido é o primeiro da lista
        lde->inicio = aux->prox;
        if (aux->prox != NULL)
            aux->prox->ant = NULL;
        else
        {
            lde->inicio = NULL;
            lde->fim    = NULL;
        }
        lde->tamanho--;
        free(aux);
        return;
    }
    //elemento a ser removido não é o primeiro da lista
    while ((aux != NULL) && (aux->valor < valor))
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("\nElemento nao encontrado na lista\n");
    }
    else
    {
       if ((aux->valor) > valor)
            printf("\nElemento nao encontrado na lista\n");
       else
        {
            removido = aux;
            if (aux->prox != NULL)
                aux->prox->ant = aux->ant;
            else
                lde->fim = aux->ant;
            aux->ant->prox = aux->prox;
            lde->tamanho--;
            free(removido);
        }
    }
    return;
}

 void LDESubValor(TipoLDE *lde, int valori, int valorf)
 {
    TipoNDE *aux = lde->inicio;
    if (aux == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }
    if (aux->valor == valori)
    {
        //elemento a ser alterado é o primeiro da lista
        aux->valor = valorf;
        return;
    }
    //elemento a ser alterado não é o primeiro da lista
    while ((aux != NULL) && (aux->valor < valori))
    {
        aux = aux->prox;
    }
    if (aux == NULL)
    {
        printf("\nElemento nao encontrado na lista\n");
    }
    else
    {
        if ((aux->valor) > valori)
            printf("\nElemento nao encontrado na lista\n");
       else
            aux->valor = valorf;
    }
    return;
}

void FLDEVazia(TipoLDE *lde)
{
    TipoNDE *aux = lde->inicio;
    TipoNDE *removido;
    if (aux == NULL)
    {
        printf("\nLista Vazia\n");
        return;
    }

    while(aux != NULL)
    {
        printf("\nremove %d \n",aux->valor);
        removido = aux;
        aux = aux->prox;
        lde->tamanho--;
        free(removido);
    }
    lde->inicio = NULL;
    lde->fim    = NULL;
    return;
}

int LDEVazia(TipoLDE* lde)
{
    if (lde->inicio == NULL)
       return true; // lista vazia
    else
       return false; // lista não vazia
}

int LDESoma(TipoNDE *nde)
{
    if (nde == NULL)
        return 0;
    return nde->valor + LDESoma(nde->prox);
}


