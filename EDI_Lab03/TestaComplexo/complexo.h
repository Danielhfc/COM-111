     /*
        * File:   complexo.h
        * Criado em  25 de Agosto de 2019
    */
    #ifndef COMPLEXO_H
       #define COMPLEXO_H
       typedef struct complexo comp;

       //Função Aloca e retorna um número complexo
         comp *aloca();

       //Função Lê  e retorna um número complexo
         void leia(comp *c);

       //Função libera - Libera a memória de um numero complexo
         void libera(comp *c);

       //Função escreva – Escreve o numero complexo
         void escreva(comp *c);

       //Função retorna conjugado de um número  complexo
         comp *conjugado(comp* c);

       //Função retorna inverso de um número  complexo
         comp *inverte(comp* c);

       //Função retorna absoluto de um número  complexo
         float absoluto(comp* c);

       //Função calcula e retorna a soma de dois números  complexos
         comp *soma(comp* c1,comp* c2);

       //Função calcula e retorna a subtração de dois números  complexos
         comp *subtrai(comp* c1,comp* c2);

       //Função calcula e retorna a multiplicação de dois números  complexos
         comp *multiplica(comp* c1,comp* c2);

       //Função calcula e retorna a divisão de dois números  complexos
         comp *divide(comp* c1,comp* c2);
    #endif /*COMPLEXO_H */
