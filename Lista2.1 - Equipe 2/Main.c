// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// bibliotecas do projeto
#include "DequeDin.h"
// funcao principal
int main(void) {
  Deque *dq = NULL;
  char caracter;
  int opcao, ok;
  char continua;
  do
  {
    printf("\nDeque Dinamico");

    printf("\n\nMenu de opcoes: ");
    printf("\n  - Alocacao do Deque:");
    printf("\n\t1 - Criar");
    printf("\n\t2 - Liberar");

     printf("\n  - Manipulacao do Deque:");
    printf("\n\t3 - Inserir no Inicio");
    printf("\n\t4 - Inserir Final");
    printf("\n\t5 - Retirar Inicio");
    printf("\n\t6 - Retirar Final");
    printf("\n\t7 - Ver Inicio do Deque");
    printf("\n\t8 - Ver Final do Deque");

    printf("\n  - Detalhes do Deque:");
    printf("\n\t9 - Checar se vazio");
    printf("\n\t10 - Checar se cheio");
    printf("\n\t11 - Checar Tamanho");

    printf("\n  -  Funcoes do trabalho");
    printf("\n\t12 - Imprimir do inicio");
    printf("\n\t13 - Imprimir do final");
    printf("\n\t14 - Verificar palindromo");
    
    printf("\n15 - Sair");
    printf("\n\nOpcao: ");
    scanf("%d", &opcao);
  
    switch(opcao){
        case 1:
        // F01 criar Deque
        dq = DequeCriar();
        if(dq != NULL) 
            printf("\n Deque criada com sucesso!");
        else 
            printf("\n Deque nao criado!");
      break;
      
      case 2:
          // F02 liberar Deque
          ok = DeqLiberar(dq);
          if(ok == 1)
               printf("\n Deque Liberado");
          else
               printf("\n Deque Nao Liberado");
      break;

      case 3:
          // Inserir Elemento no Inicio
         if(dq == NULL )
            printf("\n Deque Nao Criado");
         else{
           // inserir elemento no Inicio
           printf("Entre com o caracter a ser colocado no Deque: ");
           scanf(" %c", &caracter);
           ok = InsereInicio(dq, caracter);
           if(ok == -1)printf("\n Deque Nao Criado");
           if(ok ==  1)printf("\n Insercao realizada com sucesso!");
           if(ok ==  0)printf("\n Falha na insercao!"); 
         }
      break;

      case 4:
          // Inserir Elemento no Final
         if(dq == NULL )
            printf("\n Deque Nao Criado");
         else{
           // inserir elemento no Final
           printf("Entre com o caracter a ser colocado no Deque: ");
           scanf(" %c", &caracter);
           ok = InsereFinal(dq, caracter);
           if(ok == -1)printf("\n Deque Nao Criado");
           if(ok ==  1)printf("\n Insercao realizada com sucesso!");
           if(ok ==  0)printf("\n Falha na insercao!"); 
         }
      break;

      case 5:
      // Retirar elemento do inicio
      ok = DeqRemoveInicio(dq);
      if(ok == -1) printf("\n Deque Nao Criado");
      else
       if(ok == 1) printf("\n Retirado do Inicio com sucesso!");
       else
        printf("\n Deque Vazio");
    
   break;
   
   case 6:
        // Retirar Elemento do Fim
        ok = DeqRemoveFinal(dq);
        if(ok == -1)printf("\n Deque Não Criado!");
        else
           if(ok == 1) 
               printf("\n Retirado do Final do Deque!");
           else
               printf("\n Deque Vazio");
     break;

     case 7:
        // Ver Inicio
        ok = DeqConsultaInicio(dq, &caracter);
        if(ok == -1)printf("\n Deque Nao Criado!");
        else
           if(ok == 0)printf("\n Deque Vazio!");
           else
             printf("\n %c",caracter);
     break;

      case 8:
        // Ver FIM
        ok = DeqConsultaFinal(dq, &caracter);
        if(ok == -1)printf("\n Deque Nao Criado!");
        else
           if(ok == 0)printf("\n Deque Vazio!");
           else{
            // printf("\n Elemento do Final: %d", getPosFinal(dq));
             printf("\n %c",caracter);
     break;

     case 9:
        // Checar se Vazio
        ok = DeqVazio(dq);
        if(ok == -1)
            printf("\n Deque Nao Criado!");
        else 
           if(ok) 
                printf("\n Deque Vazio!");
           else 
                printf("\n Deque nao Vazio!");

 

     break;

      case 10:
        //Checar se Cheio
        ok = DeqCheio(dq);
        if(ok == -1)
              printf("\n Deque Nao Criado!");
        else
             if(ok)
                   printf("\n Deque Cheio!");
             else
                   printf("\n Deque nao Cheio!");
     break;

      case 11:
        //Checar tamanho do Deque
        ok = DeqTamanho(dq);
        if(ok == -1)
               printf("\n Deque Nao Criado!");
        else
               printf("\n Tamanho do Deque: %5d",ok);
     break;

      case 12:
        //Imprimir do inicio
        DequeImprimeInicio(dq);
          
      break;

      case 13:
        //Imprimir do final
        DequeImprimeFinal(dq);

      break;

      case 14:
      //Verificar palindromo
      ok = Palindromo(dq);
      if(ok != 0)
        printf("\nO deque nao forma palindromo!");
      else 
        printf("\nO deque forma palindromo!");

      break;

      case 15:
        //SAIR
         if(dq != NULL)
              // libera memória e finaliza programa
              ok = DeqLiberar(dq);
         printf("\nFinalizando...");
     break; 

      
    default:
        printf("\nOpcao invalida!");
    break;

    while (getchar() != '\n'){
 printf("\n\nTecle enter para continuar: ");
 scanf("%c",&continua);
 system("cls");
 }
    }
    }
}while(opcao != 15);
 return 1;
}