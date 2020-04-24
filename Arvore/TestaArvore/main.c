// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
// bibliotecas do projeto
#include "ArvoreBin.h"
// funcao principal
int main(void) {
  ArvBin *raiz;
  int opcao, ok, valor;
  char continua;
  // menu de op��es para execu��es de
 //  opera��es sobre a ArvoreBinaria
  do
  {
    printf("\nArvoreBinaria Dinamica");
    printf("\n\nMenu de opcoes: ");
    printf("\n  - Alocacao da Arvore:");
    printf("\n\t1 - Criar");
    printf("\n\t2 - Liberar");
    printf("\n  - Manipulacao da Arvore:");
    printf("\n\t3 - Inserir");
    printf("\n\t4 - Remover");
    printf("\n\t5 - Consultar");
    printf("\n  - Detalhes da Arvore:");
    printf("\n\t6 - Checar se vazia");
    printf("\n\t7 - Altura da Arvore");
    printf("\n\t8 - Total de Nos");
    printf("\n  - Percorrer  a Arvore:");
    printf("\n\t9 - Pre Ordem");
    printf("\n\t10 - Em Ordem");
    printf("\n\t11 - Pos Ordem");
    printf("\n  - Funcoes da Prova:");
    printf("\n\t12 - Total de Folhas");
    printf("\n\t13 - Nos Com Apenas Um Filho");
    printf("\n\t14 - Estritamente Binaria");
    printf("\n15 - Sair");
    printf("\n\nOpcao: ");
    scanf("%d", &opcao);
    switch(opcao){

        case 1:
        // criar �rvore
        raiz = ArvBinCriar();
        if( raiz != NULL){
          printf("\n Arvore criada com sucesso!");
         }else{
          printf("\n Arvore nao criada!");
        }
      break;

      case 2:
          // liberar �rvore
          ok = ArvBinLiberar( raiz );
          if(ok == 0)printf("\n Arvore Nao Criada");
          else
            printf("\n Arvore Liberada");
      break;

      case 3:
          //  Inserir
          if( raiz == NULL )
            printf("\n Arvore Nao Criada");
          else {
            // inserir elemento na �rvore
            printf("Entre com o Valor a ser inserido: ");
            scanf("%d", &valor);
            ok = ArvBinInsere( raiz, valor );
            if(ok == 1)
                printf("\n Insercao realizada com sucesso!");
            else  printf("\n Falha na insercao!");
          }
      break;

      case 4:
          //Remover elemento da �rvore
          printf("Entre com o Valor a ser removido: ");
          scanf("%d", &valor);
          ok = ArvBinRemove( raiz, valor );
          if( ok == -1 ) printf("\n Arvore Nao Criada");
          else{
              if(ok == 0)
                  printf("\n Elemento Nao Encontrado");
              else
                  printf("\n Removido com sucesso!" );
          }
      break;

      case 5:
          // Consultar Elemento na �rvore:
          printf("Entre com o Valor a ser consultado: ");
          scanf("%d", &valor);
          ok = ArvBinConsulta( raiz , valor );
          if( ok == -1 )printf("\n Arvore Nao Criada!");
          else
              if(ok == 0)
                    printf("\n  Elemento Nao Encontrado");
              else
                   printf( "\nElemento Encontrado"  );
      break;

      case 6:
          // Checar se �rvore vazia
          ok = ArvBinVazia(raiz);
          if(ok == -1)
              printf("\n Arvore Nao Criada!");
          else
             if(ok == 1)
                 printf("\n Arvore Vazia!");
             else
                printf("\n Arvore nao Vazia!");
      break;

       case 7:
         //Mostrar Altura da �rvore
         ok = ArvBinAltura( raiz );
         if(ok == -1)printf("\n Arvore Nao Criada!");
         else
            if(ok == 0)
                 printf("\n Arvore Vazia!");
            else
                 printf("\n Altura de Arvore: %5d", ok);
      break;

      case 8:
         // Mostrar Total de N�s da �rvore
         ok = ArvBinTotalNO( raiz );
         if( ok == -1 )printf("\n Arvore Nao Criada!");
         else
            if(ok == 0)
                 printf("\n Arvore Vazia!");
            else
                 printf("\n Total de Nos da Arvore: %5d", ok);
      break;

      case 9:
         // Percorrer N�s da �rvore  Pre Ordem
         printf("\n Percorrer Pre Ordem\n   ");
         ok = ArvBinPreOrdem ( raiz );
         if( ok == -1 )
            printf("\n Arvore Nao criada");
         else
            if(ok == 0)
                 printf("\n Arvore Vazia!");
            else
                if(ok == 1)
                    printf("\n Fim Pre Ordem");
      break;

      case 10:
         // Percorrer N�s da �rvore EM Ordem
         printf("\n Percorrer Em Ordem\n   ");
         ok = ArvBinEmOrdem( raiz );
         if( ok == -1 )printf("\n Arvore Nao Criada!");
         else
            if(ok == 0)
                 printf("\n Arvore Vazia!");
            else
                if(ok == 1)
                    printf("\n Fim Em Ordem");
      break;

      case 11:
         // Percorrer N�s da �rvore POS Ordem
         printf("\n Percorrer Pos Ordem\n   ");
         ok = ArvBinPosOrdem( raiz );
         if( ok == -1 )printf("\n Arvore Nao Criada!");
         else
            if(ok == 0)
                 printf("\n Arvore Vazia!");
            else
                if(ok == 1)
                    printf("\n Fim Pos Ordem");
      break;

        case 12:
            ok = ArvBinTotalFolhas(raiz);
                if(ok == -1)
                    printf("\n Arvore Nao Criada");
                else if(ok == -2)
                    printf("\n Lista Vazia");
                else
                    printf("\n Numero de folhas: %d",ok);

        break;

        case 13:
            ok = ArvBinNoUmFilho(raiz);
                if(ok == -1)
                    printf("\n Arvore Nao Criada");
                else if(ok == -2)
                    printf("\n Lista Vazia");
                else
                    printf("\n Numero de Nos Com Apenas Um Filho: %d",ok);


        break;


        case 14:
            ok = ArvBinEstritaBin(raiz);
                if(ok == -1)
                    printf("\n Arvore Nao Criada");
                else if(ok == -2)
                    printf("\n Lista Vazia");
                else
                    printf("\n Arvore Estritamente Binaria",ok);


        break;

      case 15:
         //SAIR
         if( raiz != NULL )
              // libera mem�ria e finaliza programa
             ok = ArvBinLiberar(raiz);
         printf("\nFinalizando...");
     break;

     default:
        printf("\nOpcao invalida!");
     break;
    }

     while (getchar() != '\n');
 printf("\n\nTecle enter para continuar: ");
 scanf("%c",&continua);
 system("cls");
 } while(opcao != 15);
 return 1;
  }
