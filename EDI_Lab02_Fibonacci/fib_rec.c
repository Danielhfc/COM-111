#include <stdio.h>
// Função :  Calcule e escreva N primeiros termos
//           da serie de Fibonacci (Recursivo)
// Autor :
// Data : 19/8/2019
// Seção de Declarações
int Fib(int);
int main(){
  int N;
  do {
     printf("Entre com números de termos 3 ou mais: " );
     scanf("%d",&N);
  } while (N < 3);

  printf("Serie de Fibonacci com %d  termos:\n\n", N);
  for (int i=1; i <= N; i++)
     printf("%d,  ", Fib(i));
  printf("...\n\n");
  return 0;

}
int Fib(int n){
      if(n == 1 || n == 2)return 1;
      else return Fib(n-2) + Fib(n-1);
}
