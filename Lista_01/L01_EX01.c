/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX01 - Faça a leitura de dois números reais na função principal, chame uma função para
calcular e retornar a média entre eles, e depois imprima este resultado na função
principal com duas casas de precisão
*/

#include <stdio.h>

float grade(float n1, float n2);

int main(){
    float num1, num2, result;

    printf("Informe o primeiro numero: ");
    scanf("%f", &num1);
    printf("Informe o segundo numero: ");
    scanf("%f", &num2);

    result = grade(num1,num2);
    printf("\nA media sera: %.2f\n", result);
    return 0;
}

float grade(float n1, float n2){
    return (n1 + n2) / 2.0;
}
