#include <stdio.h>
#include<locale.h>
// Função :  Calcule e escreva N primeiros termos
//           da serie de Fibonacci
// Autor :
// Data : 19/8/2019
// Seção de Declarações
int main(){
  int N,  ant1, ant2, prox, i;
  ant1 = 1;
  ant2 = 1;
setlocale(LC_ALL,"");
  do {
     printf("Entre com números de termos 3 ou mais: " );
     scanf("%d",&N);
  } while (N < 3);

  printf("Serie de Fibonacci com %d  termos:\n\n", N);
  printf("%d, ",ant1);
  printf("%d, ",ant2);
  for (i=3;i <= N;i++){
      prox = ant1 + ant2;
      printf("%d,  ",prox);
      ant1 = ant2;
      ant2 = prox;
  }
  printf("...\n\n");
  return 0;
}
