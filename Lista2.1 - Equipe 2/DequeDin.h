  #ifndef DEQUEDIN_H
  #define DEQUEDIN_H

 typedef struct deque Deque;

 Deque *DequeCriar( );
 int DeqLiberar(Deque *dq);
 int DeqTamanho(Deque *dq);
 int DeqVazio(Deque *dq);
 int DeqCheio(Deque *dq);
 int DeqConsultaInicio(Deque *dq, char *caracter);
 int DeqConsultaFinal(Deque *dq, char *caracter);
 int InsereInicio(Deque *dq, char caracter);
 int InsereFinal(Deque *dq, char caracter);
 int DeqRemoveInicio(Deque *dq);
 int DeqRemoveFinal(Deque *dq);
 //Funções do trabalho
 void DequeImprimeInicio(Deque *dq);
 void DequeImprimeFinal(Deque *dq);
 int Palindromo(Deque *dq);
#endif