// bibliotecas do sistema
#include <stdio.h>
#include <stdlib.h>
// bibliotecas do projeto
#include "LecProd.h"

// funcao principal
int main(void) {

  // no início a lista está vazia, logo, o ponteiro inicio tem valor NULL
  //o ponteiro inicio conterá o endereço do primeiro elemento da lista
  Lista *li = NULL;
  Produto *produto;
  int opcao, dado, ok, pos;
  char cont;
 // menu de opções para execuções de operações sobre a lista
  do
  {
    printf("\nLista de Produtos");

    printf("\n\nMenu de opções");
    printf("\n1 - Criar lista");
    printf("\n2 - Liberar lista");
    printf("\n  - Inserir elementos:");
    printf("\n\t3 - No início");
    printf("\n\t4 - No final");
    printf("\n\t5 - Ordenado");
    printf("\n  - Remover elementos:");
    printf("\n\t6 - Do início");
    printf("\n\t7 - Do final");
    printf("\n\t8 - De qualquer posição");
    printf("\n  - Buscar elementos:");
    printf("\n\t9 - Pela posição");
    printf("\n\t10 - Pelo dado");
    printf("\n  - Detalhes da Lista:");
    printf("\n\t11 - Checar se vazia");
    printf("\n\t12 - Tamanho");
    printf("\n\t13 - Imprimir os elementos");
    printf("\n14 - Sair");
    printf("\n\nOpção: ");
    scanf("%d", &opcao);

    switch(opcao){

      case 1:

        // criar lista
        li = criar_lista();

        if(li != NULL){
          printf("\n Lista criada com sucesso!");
        }else{
          printf("\n Lista não criada!");
        }
        break;


      case 2:

        // liberar lista
        ok = liberar_lista(li);

        if(ok){
          printf("\n Lista liberada com sucesso!");
        }else{
          printf("\n Lista não liberada!");
        }
        break;

      case 3:

        // inserir elemento no início
        ok = criar_produto(&produto);
        ok = inserir_lista_inicio(li, produto);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 4:

        // inserir elemento no final
        ok = criar_produto(&produto);
        ok = inserir_lista_final(li, produto);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 5:

        // inserir elemento de forma ordenada
        ok = criar_produto(&produto);
        ok = inserir_lista_ordenada(li, produto);

        if(ok == 1){
          printf("\n Inserção realizada com sucesso!");
        }else{
          printf("\n Falha na inserção!");
        }

        break;

      case 6:

        // remover elemento do início
        ok = remover_lista_inicio(li);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 7:

        // remover elemento do final
        ok = remover_lista_final(li);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;

      case 8:

        // remover elemento do meio
        printf("\n Código do produto a ser removido: ");
        scanf("%d", &dado);

        ok = remover_lista_meio(li, dado);

        if(ok == 1){
          printf("\n Remoção realizada com sucesso!");
        }else{
          printf("\n Falha na remoção!");
        }
        break;


      case 9:

        // busca elemento pela posicao
        printf("\n Posição do elemento a ser buscado: ");
        scanf("%d", &pos);

        produto = buscar_lista_posicao(li, pos);

        if(produto != NULL){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento da %dª posição: ", pos);
          imprimir_produto(produto);
        }else{
          printf("\n Posição não existe!");
        }

        break;
      case 11:
         if(lista_vazia(li) == -1)
           printf("\n Lista inválida");
         else if(lista_vazia(li) == 1)
           printf("\n Lista vazia");
          else
          printf("\nLista contem elementos");
         break;
      case 10:

        // busca elemento pelo dado
        printf("\n Código do produto a ser buscado: ");
        scanf("%d", &dado);

        produto = buscar_lista_dado(li, dado);

        if(produto != NULL){
          printf("\n Busca realizada com sucesso!");
          printf("\n Elemento com código %d na lista: ", dado);
          imprimir_produto(produto);
        }else{
          printf("\n Elemento não encontrado!");
        }

        break;

      case 12:

        // imprime a lista
        printf("\n Tamanho da Lista: %d", tamanho_lista(li));

        break;

      case 13:

        // imprime a lista
        if(li != NULL && (*li) != NULL)
        {
          printf("\n Lista encadeada circular: ");
          imprimir_lista(li);
        }
        else{
          if(li == NULL )
            printf("\n Lista Não Criada");
          else
           if((*li) == NULL )
              printf("\n Lista Vazia");
        }
        break;

      case 14:
        if(li != NULL && (*li) != NULL)
        {
           // libera memória e finaliza programa
          liberar_lista(li);
        }
        printf("\nFinalizando...");
        break;

      default:
        printf("\nOpção inválida!");
        break;
    }
    while (getchar() != '\n');
    printf("\n\nTecle enter para continuar: ");
    scanf("%c",&cont);
    system("cls");

  }while(opcao != 14);

  return 0;
}
