#include<stdio.h>
#include<locale.h>
int fib(int n){
if(n<=2)
    return 1;

else
    return fib(n-1)+fib(n-2);

}

int main(){
    int n, fibo,i;
setlocale(LC_ALL,"");
printf("Digite um a quantidade de termos de fibonnaci: ");
scanf("%d",&n);

for(i=1;i<n+1;i++)
    printf("%d ",fib(i));

}
