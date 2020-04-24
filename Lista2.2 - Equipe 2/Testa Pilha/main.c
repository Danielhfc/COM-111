// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
// bibliotecas do projeto
#include "PilhaDin.h"
// funcao principal
int main(void) {
  Pilha *pi = NULL;
  Pilha *p0 = NULL;
  Pilha *p1 = NULL;
  Pilha *p2 = NULL;
  float  media;
  int opcao, ok, num, *conj, n, i;
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
    printf("\n\t8 - Tamanho da Pilha");

    printf("\n  - Funcoes do Trabalho");
    printf("\n\t9 - Retirar os Impares");
    printf("\n\t10 - Media dos Pares");
    printf("\n\t11 - Imprimir a pilha");
    printf("\n\t12 - Colocar conjunto de inteiros em P0");
    printf("\n\t13 - Retirar os impares de P0");
    printf("\n\t14 - Media dos pares de P0");
    printf("\n\t15 - Colocar inteiros em P1 e P2 e depois concatenar");

     printf("\n16 - Sair");
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
            printf("Entre com o numero a ser colocado na Pilha: ");
            scanf("%d", &num);
            ok = PilhaInsereTopo( pi, num );
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
        ok = PilhaConsultaTopo( pi , &num );
        if( ok == -1 )
            printf("\n Pilha Nao Criada!");
        else
         if(ok == 0)
            printf("\n Pilha Vazia!");
         else {
           printf( "\nElemento do Topo"  );
           printf( "\n Numero: %d", num);
         }
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
//---------------------------------------------------------------
//Funcoes do Trabalho
      case 9:
      //Retirar Impares
      ok = retiraImpares(pi);
        if( ok == -1 )
            printf("\n Pilha Nao Criada!");
        else if (ok == 1)
              printf("\n Pilha Vazia!");
        else
        {
          printf("\n Impares removidos com sucesso!");
        }

      break;

      case 10:
      //Media Pares
      media = mediapares(pi);
        if( media == -1 )
            printf("\n Pilha Nao Criada!");
        else if (media == -2)
              printf("\n Pilha Vazia!");
        else
        {
          printf("\n Media dos numeros pares: %f",media);
        }

      break;

      case 11:
      //Imprimir a pilha
        ok = imprimePilha (pi);
        if( ok == -1 )
            printf("\n Pilha Nao Criada!");

      break;

      case 12:
      //Criar p0 com conjunto de inteiros
        p0 = PilhaCriar();
        if( p0 != NULL)
            printf("\n Pilha criada com sucesso!");
        else
            printf("\n Pilha nao criada!");

        printf("\nDigite a quantidade de numeros a serem inseridos na P0: ");
        scanf("%d", &n);
        conj = (int*)malloc(n*sizeof(int));

        for(i=0;i<n;i++){
          printf("\nDigite um valor: ");
          scanf("%d", &conj[i]);
        }

        for(i=0;i<n;i++){
          PilhaInsereTopo(p0, conj[i]);
        }

        imprimePilha(p0);

      break;

      case 13:
      //Retirar impares de p0
        ok = retiraImpares(p0);
        if( ok == -1 )
            printf("\n Pilha Nao Criada!");
        else if (ok == 1)
              printf("\n Pilha Vazia!");
        else
        {
          imprimePilha(p0);
        }


      break;

      case 14:
      //Media dos pares de p0
        media = mediapares(p0);
        if( media == -1 )
            printf("\n Pilha Nao Criada!");
        else if (media == -2)
              printf("\n Pilha Vazia!");
        else
        {
          printf("\n Media dos numeros pares: %f",media);
          imprimePilha(p0);
        }

      break;

      case 15:
      //Colocar inteiros em p1 e p2, depois concatenar
      //Criar p1
        p1 = PilhaCriar();
        if( p1 != NULL)
            printf("\n P1 criada com sucesso!");
        else
            printf("\n P1 nao criada!");

        printf("\nDigite a quantidade de numeros a serem inseridos na P1: ");
        scanf("%d", &n);
        conj = (int*)malloc(n*sizeof(int));

        for(i=0;i<n;i++){
          printf("\nDigite um valor: ");
          scanf("%d", &conj[i]);
        }

        for(i=0;i<n;i++){
          PilhaInsereTopo(p1, conj[i]);
        }

        imprimePilha(p1);
      //Criar p2
      p2 = PilhaCriar();
        if( p2 != NULL)
            printf("\n P2 criada com sucesso!");
        else
            printf("\n P2 nao criada!");

        printf("\nDigite a quantidade de numeros a serem inseridos P2: ");
        scanf("%d", &n);
        conj = (int*)malloc(n*sizeof(int));

        for(i=0;i<n;i++){
          printf("\nDigite um valor: ");
          scanf("%d", &conj[i]);
        }

        for(i=0;i<n;i++){
          PilhaInsereTopo(p2, conj[i]);
        }

        imprimePilha(p2);

        //Concatenar
        concatenaPilhas(p1 , p2);
        imprimePilha(p1);
      break;

      case 16:
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
 }while(opcao != 16);
 return 1;
  }
