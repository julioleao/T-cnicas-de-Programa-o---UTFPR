/*
Nome: Julio Cesario de Paiva Le�o
RA: 1916033
Turma: ES21

EX01 - Fa�a a leitura de dois n�meros reais na fun��o principal, chame uma fun��o para
calcular e retornar a m�dia entre eles, e depois imprima este resultado na fun��o
principal com duas casas de precis�o
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
