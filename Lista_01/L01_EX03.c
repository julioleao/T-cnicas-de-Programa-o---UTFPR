/*
Nome: Julio Cesario de Paiva Le�o
RA: 1916033
Turma: ES21

EX03 - Fa�a a leitura dos seguintes dados no formato real: Velocidade, Tempo e Litros
Gastos. Depois chame uma fun��o para calcular e retornar o deslocamento do
ve�culo passando como par�metros Velocidade e Tempo. Chame outra fun��o
para calcular e retornar o consumo de combust�vel, passando como par�metros
Velocidade, Tempo e Litros Gastos. Esta segunda fun��o dever� utilizar a fun��o
anterior para chegar ao consumo m�dio do veiculo. Imprima os resultados
achados na fun��o principal. As fun��es criadas dever�o estar em um arquivo
diferente do arquivo da fun��o principal, este arquivo externo dever� chamar-se
veiculo.c
*/

#include <stdio.h>
#include "C:\Users\julio\Google Drive\Faculdade\Periodo_2\T�cnicas de programa��o\Lista_01\veiculo.c"

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
