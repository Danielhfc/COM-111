// TAD para Lista Dinâmica Encadeada Circular
//  para Produtos
#ifndef _LISTA_DEC
#define _LISTA_DEC

typedef struct produto Produto;
typedef struct elemento Elemento;
typedef Elemento* Lista;

// função para criar produto
int criar_produto(Produto **produto);//F01

// funções para alocar e desalocar memória
Lista* criar_lista();//F02
int liberar_lista(Lista *li);//F03

// funções para obter informações da lista
int tamanho_lista(Lista *li);//F04
int lista_vazia(Lista *li);//F05

// funções para inserção de elementos da lista
int inserir_lista_inicio(Lista *li, Produto *produto);//F06
int inserir_lista_final(Lista *li, Produto *produto);//F07
int inserir_lista_ordenada(Lista *li, Produto *produto);//F08

// funções para remoção de elementos da lista
int remover_lista_inicio(Lista *li);//F09
int remover_lista_final(Lista *li);//F10
int remover_lista_meio(Lista *li, int codigo);//F11

// funções para buscar elementos na lista
Produto *buscar_lista_posicao(Lista *li, int pos);//F12
Produto *buscar_lista_dado(Lista *li, int codigo);//F13

void imprimir_lista(Lista *li);//F14
int imprimir_produto(Produto *produto);//F15

#endif
