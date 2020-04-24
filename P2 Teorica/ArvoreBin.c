#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBin.h"

struct NO {
    struct NO *esq;
    int dado;
    struct NO *dir;
};

//**************************F01***********************
ArvBin* ArvBinCriar() {

    ArvBin* raiz;
    raiz = (ArvBin *) malloc ( sizeof( ArvBin));

    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

//**************************Aux1***********************
static void LiberaNO ( struct NO* no){

    if ( no == NULL) return;
    LiberaNO(no->esq);
    LiberaNO(no->dir);
    free(no);
    no = NULL;
}

//**************************F02***********************
int ArvBinLiberar(ArvBin* raiz ) {

    if ( raiz == NULL) return 0; //Árvore Não Criada
    LiberaNO(*raiz);//Libera cada NÓ
    free( raiz ); //Libera a Raiz
    return 1; //Árvore Liberada
}

//**************************F03***********************
int ArvBinVazia(ArvBin* raiz ) {

    if ( raiz == NULL)
        return -1; //Arvore Não Criada
    else
        if ( *raiz == NULL)
            return 1 ; //Arvore Vazia
        else
            return 0 ; //Arvore Não Vazia
}

//**************************F04***********************
int ArvBinAltura( ArvBin* raiz ) {

    if ( raiz == NULL)
        return -1; //Árvore Não Criada
    if ( *raiz == NULL)
        return 0; //Árvore Vazia
    int altesq = ArvBinAltura( &((*raiz )->esq));
    int altdir = ArvBinAltura( &((*raiz )->dir));

    if(altesq > altdir) return ( altesq + 1 ) ;
    else return ( altdir + 1 ) ;
}

//**************************F05***********************
int ArvBinTotalNO(ArvBin* raiz ) {

    if (raiz == NULL)
        return -1; //Arvore Não Criada
    if ( *raiz == NULL)
        return 0; //Arvore Vazia
    int TotNoEsq = ArvBinTotalNO( &((* raiz )->esq));
    int TotNoDir = ArvBinTotalNO( &((* raiz )->dir));
    return TotNoEsq + TotNoDir + 1;
}

//**************************F06***********************
int ArvBinPreOrdem ( ArvBin* raiz ) {
    int ok;
    if ( raiz == NULL )
        return -1; // Árvore Não Criada
    if ( *raiz != NULL) {
        printf(“%d ”, ( *raiz )->dado);
        ok = ArvBinPreOrdem ( &(( *raiz )->esq) );
        ok = ArvBinPreOrdem ( &(( *raiz )->dir) );
        return 1;
    } else return 0; // Árvore Vazia
}

//**************************F07***********************
int ArvBinEmOrdem ( ArvBin* raiz ) {
    int ok;
    if ( raiz == NULL )
        return -1; // Árvore Não Criada
    if ( *raiz != NULL) {
        ok = ArvBinEmOrdem ( &(( *raiz )->esq) );
        printf(“%d ”, ( *raiz )->dado );
        ok = ArvBinEmOrdem ( &(( *raiz )->dir) );
        return 1;
    } else return 0; // Árvore Vazia
}

//**************************F08***********************
int ArvBinPosOrdem ( ArvBin* raiz ) {
    int ok;
    if ( raiz == NULL )
        return -1; // Árvore Não Criada
    if ( *raiz != NULL) {
        ok = ArvBinPosOrdem ( &(( *raiz )->esq) );
        ok = ArvBinPosOrdem ( &(( *raiz )->dir) );
        printf(“%d ”, ( *raiz )->dado );
        return 1;
    } else return 0; // Árvore Vazia
}

//**************************F09*******************************
int ArvBinInsere ( ArvBin* raiz, int valor ) {
    if ( raiz == NULL ) return -1; // Árvore Não Criada
    struct NO* novo;
    novo = ( struct NO* ) malloc (sizeof(struct NO));
    if ( novo == NULL ) return 0; // Falha na Inclusão
    novo->dado = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    // Procura onde inserir
    if ( *raiz == NULL ) // Árvore Vazia
    *raiz = novo;
    else {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while ( atual != NULL ) {
            ant = atual;
            if (valor == atual->dado) {
                free(novo);
                return 0; } // valor já existe
            if (valor > atual->dado)
                atual = atual->dir;
            else atual = atual->esq;
        }
        if ( valor > ant->dado )
            ant->dir = novo;
        else
            ant->esq = novo;
        }
    return 1;
}

//**************************Aux2*************************
static struct NO* RemoveAtual ( struct NO* atual ) {
    struct NO *no1, *no2;
    if (atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while (no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if (no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free( atual );
    return no2;
}

//**************************F10*******************************
int ArvBinRemove ( ArvBin * raiz , int valor ) {
    if ( raiz == NULL ) return -1; // Árvore Não Criada
    struct NO* atual = *raiz;
    struct NO* ant = NULL;
    while ( atual != NULL ) {
        if (valor == atual->dado) {
            if (atual == *raiz)
                *raiz = RemoveAtual(atual);
            else if (ant->dir == atual)
                    ant->dir = RemoveAtual(atual);
                else
                    ant->esq = RemoveAtual(atual);
            return 1; // Removido
        }
        ant = atual;
        if (valor > atual->dado)
            atual = atual->dir;
        else
            atual = atual->esq;
        }
        return 0; // Não Encontrado
}

//**************************F11*******************************
int ArvBinConsulta ( ArvBin * raiz, int valor ) {
    if ( raiz == NULL ) return -1; // Árvore Não Criada
    struct NO* atual = *raiz ;
    while (atual != NULL){
        if ( valor == atual->dado )
            return 1; // Encontrado
        if ( valor > atual->dado )
            atual = atual->dir;
        else atual = atual->esq;
    }
    return 0; // Não Encontrado
}
