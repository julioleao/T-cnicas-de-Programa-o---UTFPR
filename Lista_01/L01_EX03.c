/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX03 - Faça a leitura dos seguintes dados no formato real: Velocidade, Tempo e Litros
Gastos. Depois chame uma função para calcular e retornar o deslocamento do
veículo passando como parâmetros Velocidade e Tempo. Chame outra função
para calcular e retornar o consumo de combustível, passando como parâmetros
Velocidade, Tempo e Litros Gastos. Esta segunda função deverá utilizar a função
anterior para chegar ao consumo médio do veiculo. Imprima os resultados
achados na função principal. As funções criadas deverão estar em um arquivo
diferente do arquivo da função principal, este arquivo externo deverá chamar-se
veiculo.c
*/

#include <stdio.h>
#include "C:\Users\julio\Google Drive\Faculdade\Periodo_2\Técnicas de programação\Lista_01\veiculo.c"

int main(){
    float velocity, time, liters, result;

    printf("Informe a velocidade(KM): ");
    scanf("%f", &velocity);
    printf("Informe o tempo(H): ");
    scanf("%f", &time);
    printf("Informe a quantidade de combustivel em (L): ");
    scanf("%f", &liters);
    distance(velocity, time);
    result = consume(velocity, time, liters);

    printf("O consumo medio do veiculo e: %.2f km/l\n", result);

    return 0;
}
