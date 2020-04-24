#include <stdio.h>
#include <stdlib.h>
#include "Cilindro.h"

int main()
{
    // Criação das variáveis
    float raio, altura, retorno_r, retorno_alt,volume;
    Cilindro *c1;

    // O usuário digitará os valores para criar o cubo
    printf("Digite o raio do cilindro: ");
    scanf("%f",&raio);
    printf("Digite a altura do cilindro: ");
    scanf("%f",&altura);

    // Chama a função para criar o cubo
    c1 = cilindro_cria(raio,altura);

    // Retorna o valor do raio
    retorno_r = cilindro_acessa_r(c1);
    printf("O raio do cilindro e: %f\n",retorno_r);

    // Retorna o valor do raio
    retorno_alt = cilindro_acessa_h(c1);
    printf("A altura do cilindro e: %f\n",retorno_alt);

    // Retorna o valor do raio
    volume = cilindro_volume(c1);
    printf("O volume do cilindro e: %f\n",volume);
}
