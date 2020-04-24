#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main()
{
    TipoLista *le = LCria();
    if(LVazia(le))
        printf("Lista le vazia\n\n");
    printf("inserindo no inicio da lista le\n\n");
    LInsereInicio(le, 3);
    LImprime(le);
    LInsereInicio(le, 7);
    LImprime(le);
    LInsereInicio(le, 1);
    LImprime(le);
    LInsereInicio(le, 5);
    LImprime(le);
    printf("imprimindo a lista l recursivamente\n");
    LImprime_rec(le);
    LRemoveElemento_rec(le,5);
    printf("imprimindo a lista l recursivamente\n");
    LImprime_rec(le);
    printf("Mostrando inicio da lista le\n");
    NoDisplay(LRetornaInicio(le));
    printf("\n\nTamanho  da lista le: ");
    printf("%d \n\n", LTamanho(le));
    printf("\n\nSoma dos valores da lista le: ");
    printf("%d \n\n", LSoma(LRetornaInicio(le)));
    printf("imprimindo a lista l recursivamente\n");
    LImprime_rec(le);
    printf("\n\nEsvaziando a lista le\n\n");
    FLVazia_rec(le);
    printf("Mostrando inicio da lista le\n");
    NoDisplay(LRetornaInicio(le));
    printf("\n");
    LImprime(le);
    printf("\n\nSoma dos valores da lista le: ");
    printf("%d \n\n", LSoma(LRetornaInicio(le)));

    return (EXIT_SUCCESS);
}
