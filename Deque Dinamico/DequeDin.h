  #ifndef DEQUEDIN_H
  #define DEQUEDIN_H

  struct aluno {
    int matricula;
    char nome[80];
    float n1, n2, n3;
 };
 typedef struct aluno Aluno;
 typedef struct deque Deque;

 Deque *DequeCriar( );
 int DeqLiberar(Deque *dq);
 int DeqTamanho(Deque *dq);
 int DeqVazio(Deque *dq);
 int DeqCheio(Deque *dq);
 int DeqConsultaInicio(Deque *dq, Aluno *al);
 int DeqConsultaFinal(Deque *dq, Aluno *al);
 int InsereInicio(Deque *dq, Aluno al);
 int InsereFinal(Deque *dq, Aluno al);
 int DeqRemoveInicio(Deque *dq);
 int DeqRemoveFinal(Deque *dq);
#endif