#include <stdio.h>
#include <stdlib.h>
#include "DequeDin.h"

struct elemento {
       struct elemento *ant;
       struct aluno dados;
       struct elemento *prox;
   };
    typedef struct elemento Elem;

      struct deque {//no descritor
       struct elemento *inicio;
       struct elemento *final;
       int qtd;
   };

   Deque *DequeCriar(){
       Deque *dq = (Deque *)malloc(sizeof(Deque));
       if(dq != NULL){
           dq->inicio = dq->final = NULL;
           dq->qtd = 0;
        }
       return dq;
   }

   int DeqLiberar(Deque *dq){
       if(dq==NULL)return -1;
       else{
           Elem *no;
            while(dq->inicio != NULL){
                no = dq->inicio;
                dq->inicio = dq->inicio->prox;
                free (no);
            }
            free(dq);
            return 1;        
       }
   }

   int DeqTamanho(Deque *dq){
       if(dq == NULL) return -1;
       else return dq->qtd;
   }

   int DeqVazio(Deque *dq){
       if(dq == NULL) return -1;
       if(dq->inicio == NULL) return 1;
       else return 0;
   }

   int DeqCheio(Deque *dq){
       return 0;
   }

   int DeqConsultaInicio(Deque *dq, Aluno *al){
       if(dq == NULL) return -1;
       if(dq->inicio == NULL) return 0;
       *al = dq->inicio->dados;
       return 1;

   }

   int DeqConsultaFinal(Deque *dq, Aluno *al){
       if(dq == NULL) return -1;
       if(dq->final == NULL) return 0;
       *al = dq->final->dados;
       return 1;
   }

   int InsereInicio(Deque *dq, Aluno al){
       if(dq == NULL) return -1;
       Elem *no = (Elem*)malloc (sizeof(Elem));
       if(no == NULL) return 0;
       no->dados = al;
       no->prox = dq->inicio;
       no->ant = NULL;
       if(dq->inicio == NULL){
            no->prox = NULL;
            dq->final = no;
       }
       dq->inicio =no;
       dq->qtd++;
       return 1;
   }

   int InsereFinal(Deque *dq, Aluno al){
       if(dq == NULL) return -1;
       Elem *no = (Elem*)malloc (sizeof(Elem));
       if(no == NULL) return 0;
       no->dados = al;
       no->prox = NULL;
       if(dq->final == NULL) {
           no->ant = NULL;
           dq->inicio = no;
       }
       else{
           no->ant = dq->final;
           dq->final->prox = no;
       }
       dq->final = no;
       dq->qtd++;
       return 1;
   }

   int DeqRemoveInicio(Deque *dq){
        if (dq == NULL) return -1;
        if (dq->inicio == NULL) return 0;
        Elem *no = (Elem*)malloc (sizeof(Elem));
             no = dq->inicio;
             if(no == dq->final){
                dq->inicio = NULL;
                dq->final = NULL;
             }
             else{
            dq->inicio = dq->inicio->prox;
            dq->inicio->ant = NULL;
             }
        free(no);
        dq->qtd--;
        return 1;
   }

   int DeqRemoveFinal(Deque *dq){
       if(dq == NULL) return -1;
       if(dq->inicio == NULL) return 0;
       Elem *no = (Elem*)malloc (sizeof(Elem));
        no = dq->final;
       if(no == dq->inicio){
           dq->inicio = NULL;
           dq->final = NULL;
       }
       else
       {
           dq->final = no->ant;
       }
       free(no);
       dq->qtd--;
       return 1;
   }