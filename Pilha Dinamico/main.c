// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
// bibliotecas do projeto
#include "PilhaDin.h"
// funcao principal
int main(void) {
  Pilha *pi = NULL;
  Aluno  al;
  int opcao, ok;
  char continua;
   // menu de opções para execuções de 
   //  operações sobre a Pilha
  do
  {
    printf("\nPilha Dinamica");

    printf("\n\nMenu de opcoes: ");
    printf("\n  - Alocacao da Pilha:");
    printf("\n\t1 - Criar");
    printf("\n\t2 - Liberar");

    printf("\n  - Manipulacao da Pilha:");
    printf("\n\t3 - Empilhar");
    printf("\n\t4 - Desempilhar");
    printf("\n\t5 - Consultar Topo");

    printf("\n  - Detalhes da Pilha:");
    printf("\n\t6 - Checar se vazia");
    printf("\n\t7 - Checar se cheia");
    printf("\n\t8 - Tamanho da Fila");

     printf("\n9 - Sair");
     printf("\n\nOpcao: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
        // criar Pilha
        pi = PilhaCriar();
        if( pi != NULL) 
            printf("\n Pilha criada com sucesso!");
        else
            printf("\n Pilha nao criada!");
      break;

       case 2:
          // liberar Pilha
          ok = PilhaLiberar( pi );
          if(ok == 0)
            printf("\n Pilha Nao Criada");
          else
             printf("\n Pilha Liberada");
      break;

      case 3:
          //  Empilhar PUSH
          if( pi == NULL )
            printf("\n Pilha Nao Criada");
          else {
            // inserir elemento no topo
            printf("Entre com o aluno a ser colocado na Pilha: ");
            printf("\nEntre com a Matricula: ");
            scanf("%d", &al.matricula);
            while(getchar() != '\n');
            printf("\nEntre com o Nome: ");
            scanf("%[^\n]",al.nome);
            printf("\nEntre com a Nota1: ");
            scanf("%f", &al.n1);
            printf("\nEntre com a Nota2: ");
            scanf("%f", &al.n2);
            printf("\nEntre com a Nota3: ");
            scanf("%f", &al.n3);
            ok = PilhaInsereTopo( pi, al );
            if(ok == 1)
              printf("\n Insercao realizada com sucesso!");
            else
              printf("\n Falha na insercao!");
          }
      break;

      case 4:
      //Desempilhar POP
      // retirar elemento do topo
      ok = PilhaRemoveTopo ( pi );
      if( ok == -1 ) printf("\n Pilha Nao Criada");
      else
          if(ok == 0) 
              printf("\n Pilha Vazia");
          else
              printf("\n Desempilhado com sucesso! ");

   break;

   case 5:
        // Ver topo da Pilha:
        ok = PilhaConsultaTopo( pi , &al );
        if( ok == -1 )
            printf("\n Pilha Nao Criada!");
        else
         if(ok == 0)
            printf("\n Pilha Vazia!");
         else {
           printf( "\nElemento do Topo"  );
           printf( "\n Matricula: %d", al.matricula);
           printf( "\n Nome: %s", al.nome);
           printf( "\n N1: %.2f", al.n1);
           printf( "\n N2: %.2f", al.n2);
           printf( "\n N3: %.2f", al.n3);  }
     break;

     case 6:
        // Checar se Pilha vazia
        ok = PilhaVazia( pi );
        if(ok == -1)
             printf("\n Pilha Nao Criada!");
        else 
           if(ok == 1)
              printf("\n Pilha Vazia!");
           else 
                printf("\n Pilha nao Vazia!");
     break;

     case 7:
        //Checar se Pilha cheia
        ok = PilhaCheia( pi );
        if(ok == -1)
            printf("\n Pilha Nao Criada!");
        else
            if(ok == 0)
                 printf("\n Pilha Nao Cheia!");
     break;

     case 8:
        // Mostrar tamanho da Pilha
        ok = PilhaTamanho ( pi );
        if( ok == -1 )
            printf("\n Pilha Nao Criada!");
        else
             printf("\n Tamanho da Pilha: %5d", ok);
     break;

      case 9:
        //SAIR
         if( pi != NULL )
            // libera memória e finaliza programa
            ok = PilhaLiberar(pi);
         printf("\nFinalizando...");
     break; 
    
    default:
        printf("\nOpção invalida!");
    break;
  }

   while (getchar() != '\n');
 printf("\n\nTecle enter para continuar: ");
 scanf("%c",&continua);
 system("cls");
 }while(opcao != 9);
 return 1;
  }