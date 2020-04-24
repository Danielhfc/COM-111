/*
 * File:   main.c
 * TestLDE

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listaDuplaEncadeada.h"

int main()
{
    TipoLDE *lde = LDECria();
    LDEInsereOrdenado(lde, 3);
    printf("\nImprimindo do inicio\n");
    LDEImprimeInicio(lde);
    LDEInsereOrdenado(lde, 7);
    printf("\nImprimindo do inicio\n");
    LDEImprimeInicio(lde);
    LDEInsereOrdenado(lde, 1);
    printf("\nImprimindo do inicio\n");
    LDEImprimeInicio(lde);
    LDEInsereOrdenado(lde, 5);
    printf("\nImprimindo do inicio\n");
    LDEImprimeInicio(lde);
    printf("\nImprimindo do fim\n");
    LDEImprimeFim(lde);
    printf("\nValor do inicio da lista ");
    NDEDisplay(LDERetornaInicio(lde));
    printf("\nValor do Fim da lista ");
    NDEDisplay(LDERetornaFim(lde));
    printf("\nTamanho da lista: %d \n",LDETamanho(lde));
    if(LDEConsultaElemento(lde, 7))
       printf("\nValor 7 encontrado na lista\n");
    else
       printf("\nValor 7 não encontrado na lista\n");
    if(LDEConsultaElemento(lde, 20))
       printf("\nValor 20 encontrado na lista\n");
    else
       printf("\nValor 20 não encontrado na lista\n");
    printf("\nRemovendo o valor 3\n");
    LDERemoveElemento(lde, 3);
    printf("\nTrocando o valor 7 por 12\n");
    LDESubValor(lde, 7, 12);
    printf("\nImprimindo do inicio\n");
    LDEImprimeInicio(lde);
    printf("\nImprimindo a soma dos Elementos: %d\n",
    LDESoma(LDERetornaInicio(lde)));
    if (LDEVazia(lde))printf("\nLista está vazia\n");
    else printf("\nLista não está vazia\n");
    FLDEVazia(lde);
    printf("\nImprimindo do inicio\n");
    LDEImprimeInicio(lde);
}
