#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DequeDin.h"

struct elemento {
       struct elemento *ant;
       char caracter;
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

   int DeqConsultaInicio(Deque *dq, char *caracter){
       if(dq == NULL) return -1;
       if(dq->inicio == NULL) return 0;
       *caracter = dq->inicio->caracter;
       return 1;

   }

   int DeqConsultaFinal(Deque *dq, char *caracter){
       if(dq == NULL) return -1;
       if(dq->final == NULL) return 0;
       *caracter = dq->final->caracter;
       return 1;
   }

   int InsereInicio(Deque *dq, char caracter){
       if(dq == NULL) return -1;
       Elem *no = (Elem*)malloc (sizeof(Elem));
       if(no == NULL) return 0;
       no->caracter = caracter;
       no->ant = NULL;
       if(dq->inicio == NULL){
            no->prox = NULL;
            dq->final = no;
       }
       else{
           no->prox = dq->inicio;
           dq->inicio->ant = no;
       }
       dq->inicio = no;
       dq->qtd++;
       return 1;
   }

   int InsereFinal(Deque *dq, char caracter){
       if(dq == NULL) return -1;
       Elem *no = (Elem*)malloc (sizeof(Elem));
       if(no == NULL) return 0;
       no->caracter = caracter;
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
//---------------------------------------------------------------------------------
//Funções do trabalho
//01
   void DequeImprimeInicio(Deque *dq){
       if(dq == NULL)
            printf("\nA lista nao foi criada");

        else if (dq->inicio == NULL)
            printf("\nA lista esta vazia");


        else
        {

        Elem *no = (Elem*)malloc (sizeof(Elem));
        no = dq->inicio;

       printf("\n%c",no->caracter);

       while (no->prox != NULL){
           no = no->prox;
           printf("\n%c",no->caracter);
       }
   }
   }

//02
  void DequeImprimeFinal(Deque *dq){
       if(dq == NULL)
            printf("\nA lista nao foi criada");

        else if (dq->inicio == NULL)
            printf("\nA lista esta vazia");


        else
        {

        Elem *no = (Elem*)malloc (sizeof(Elem));
        no = dq->final;

       printf("\n%c",no->caracter);

       while (no->ant != NULL){
           no = no->ant;
           printf("\n%c",no->caracter);
       }
   }
   }
//03
int Palindromo(Deque *dq){
    if(dq == NULL) return -1;

        else if (dq->inicio == NULL) return 1;

    else{

    char *vetA, *vetB;
    int i = 0;
    vetA = (char*)malloc((dq->qtd)*sizeof(char));
    vetB = (char*)malloc((dq->qtd)*sizeof(char));

    Elem *noA = (Elem*)malloc (sizeof(Elem));
        noA = dq->inicio;

       vetA[0] = noA->caracter;

       while (noA->prox != NULL){
           noA = noA->prox;
           i++;
           vetA[i] = noA->caracter;
       }
        i = 0;
    Elem *noB = (Elem*)malloc (sizeof(Elem));
        noB = dq->final;

       vetB[0] = noB->caracter;
       while (noB->ant != NULL){
           noB = noB->ant;
           i++;
           vetB[i] = noB->caracter;
       }
       return strcmp(vetA,vetB);
}
}
