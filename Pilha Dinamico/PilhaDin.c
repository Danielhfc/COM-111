#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
 
      struct elemento {
       struct aluno dados;
       struct elemento *prox;
   };
    typedef struct elemento Elem;

    Pilha* PilhaCriar(){
        Pilha *pi;
        pi = (Pilha*)malloc(sizeof(Pilha));
       
        if(pi != NULL)
            *pi = NULL;
        
        return pi;
    }

    int PilhaLiberar(Pilha* pi){
        if(pi == NULL) return 0;
        else{
            Elem* no;
                while((*pi) != NULL){
                    no = *pi;
                    *pi = (*pi)->prox;
                    free(no);
                }
                free (pi);
                return 1;
        }
    }

    int PilhaTamanho(Pilha* pi){
        if(pi == NULL) return -1;
        else{
            int cont = 0;
            Elem* no = *pi;
            while(no != NULL){
                cont++;
                no = no->prox;
            }
            return cont;
        }
    }

    int PilhaVazia(Pilha* pi){
        if(pi == NULL) return -1;
        if((*pi) == NULL) return 1;
        else return 0;

    }

    int PilhaCheia(Pilha* pi){
        if(pi == NULL) return -1;
        return 0;
    }

    int PilhaConsultaTopo(Pilha* pi, Aluno *al){
        if(pi == NULL) return -1;
        if((*pi) == NULL) return 0;
        *al = (*pi)->dados;
        return 1;
    }

    int PilhaInsereTopo(Pilha* pi, Aluno al){
        if(pi == NULL) return -1;
        Elem* no = (Elem*)malloc(sizeof(Elem));
        if(no == NULL) return 0;
        no->dados = al;
        no->prox = (*pi);
        (*pi) = no;
        return 1;
    }

    int PilhaRemoveTopo(Pilha* pi){
        if(pi == NULL) return -1;
        if((*pi) == NULL) return 0;
        Elem* no = *pi;
        *pi = no->prox;
        free(no);

        return 1;
    }