/*
 * File:   listaEncadeada.h
 * Equipe 2:
Daniel Henrique Ferreira Carvalho - 2019005426
Hugo Nunes Machado - 2019005678
Luiz Gustavo Piazza Honório - 2019016303
Márcio Gonçalves Pereira Filho  -  2019010355
*/

#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main()
{
    //Declaração das variáveis utilizadas como valor
    int N, n, i, *vetor;

    //Declaração das variaves tipo lista.
    TipoLista *le = LCria();
    TipoLista *le2;
    TipoLista *le3;
    TipoLista *le4;

    //Conferir se a lista1 esta vazia
    if(LVazia(le))
        printf("Lista le vazia\n\n");

    //Preencher a lista número por número
    printf("inserindo no inicio da lista le\n\n");
    LInsereInicio(le, 3);
    LImprime(le);
    LInsereInicio(le, 7);
    LImprime(le);
    LInsereInicio(le, 1);
    LImprime(le);
    LInsereInicio(le, 5);
    LImprime(le);

    //Imprime-se a lista
    printf("imprimindo a lista l recursivamente\n");
    LImprime_rec(le);

/*-----------------------------------------------------------------------------------------------------------------------------
        Trabalho para casa 02 */

    //Cria uma lista2 idêntica à lista 1
    le2 = LDuplica(le);
    printf("imprimindo a lista 2 (duplicada) recursivamente\n");
    LImprime_rec(le2);

    // Coloca os elementos da lista2 no final da lista1
    le = LEConcatena(le , le2);
    printf("imprimindo a lista 1 concatenada\n");
    LImprime_rec(le);

    //O usuário fornecerá os valores do vetor para criar a lista3
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &N);
    vetor = (int*) malloc(N*sizeof(int));
        for(i=0;i<N;i++){
            printf("Digite um valor para o vetor: ");
            scanf("%d", &vetor[i]);
        }
    le3 = LCriaVetor(N, vetor);
    printf("imprimindo a lista 3 (feita com vetor) recursivamente\n");
    LImprime_rec(le3);

    //O usuário escolhe um valor para criar a lista4 a partir do próximo elemento da lista1
    printf("Qual o valor para dividir a lista?");
    scanf("%d", &n);
    le4 = LEDivide(n, le);
    printf("imprimindo a lista 4 (dividida) recursivamente\n");
    LImprime_rec(le4);

    //Inverte a ordem dos elementos da lista1
    LInverte(le);
    printf("imprimindo a lista 1 com os elementos invertidos\n");
    LImprime_rec(le);

    return (EXIT_SUCCESS);
}
