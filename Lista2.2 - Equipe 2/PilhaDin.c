#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
 
      struct elemento {
       int num;
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

    int PilhaConsultaTopo(Pilha* pi, int *num){
        if(pi == NULL) return -1;
        if((*pi) == NULL) return 0;
        *num = (*pi)->num;
        return 1;
    }

    int PilhaInsereTopo(Pilha* pi, int num){
        if(pi == NULL) return -1;
        Elem* no = (Elem*)malloc(sizeof(Elem));
        if(no == NULL) return 0;
        no->num = num;
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

    int retiraImpares(Pilha* pi){
        if(pi == NULL) return -1;
        if((*pi) == NULL) return 1;

        int *pares;
        int i = 0, j;
        pares = (int*)malloc((PilhaTamanho(pi))*sizeof(int));

            while((*pi) != NULL){
                if((*pi)->num % 2 != 0)
                    PilhaRemoveTopo(pi);
                else{
                    pares[i] = (*pi)->num;
                    i++;
                    PilhaRemoveTopo(pi);
                }
            }
        
            for(j=(i-1);j>=0;j--)
                PilhaInsereTopo(pi, pares[j]);

        return 0;
    }

    float mediapares(Pilha* pi){
        if(pi == NULL) return -1;
        int *pares, i=0, j;
        pares = (int*)malloc((PilhaTamanho(pi))*sizeof(int));
        float media = 0;

        retiraImpares(pi);
        while((*pi) != NULL){
                    pares[i] = (*pi)->num;
                    i++;
                    PilhaRemoveTopo(pi);

            }
            for(j=(i-1);j>=0;j--){
                PilhaInsereTopo(pi, pares[j]);
                media = pares[j] + media;
            }
        return (media/(i));
    }

    int concatenaPilhas(Pilha* p1, Pilha* p2){
        if(p1 == NULL || p2 == NULL) return -1;
        while((*p2) != NULL){
                    PilhaInsereTopo(p1,(*p2)->num);
                    PilhaRemoveTopo(p2);
            }
        return 1;
    }

    int imprimePilha(Pilha* p){
        if(p == NULL) return -1;
        printf("\nImprimindo a Pilha: ");

        int i=0, j, *numeros;
        numeros = (int*)malloc((PilhaTamanho(p))*sizeof(int));
        
        while((*p) != NULL){
                    numeros[i] = (*p)->num;
                    printf("\n%d",numeros[i]);
                    i++;
                    PilhaRemoveTopo(p);
            }
           for(j=(i-1);j>=0;j--)
                PilhaInsereTopo(p, numeros[j]);
        return 1;
    }