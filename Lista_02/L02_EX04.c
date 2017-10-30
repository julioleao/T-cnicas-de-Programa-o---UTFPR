/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX04. Passagem de dados por referência. Crie um programa que leia dois valores inteiros
na função principal, depois chame uma função chamada Troca passando as duas
variáveis inteiras lidas como parâmetros por referência. Esta função irá inverter o
valor das duas variáveis. Depois na função principal imprima na tela os novos
valores das duas variáveis
*/

#include <stdio.h>

void troca(int *num1, int *num2);

int main(){
    int num1, num2;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num1);
    printf("Digite outro numero inteiro: ");
    scanf("%d", &num2);

    troca(&num1, &num2);

    printf("\n\nOs numeros trocados, ficaram:\n%d e %d\n", num1, num2);


    return 0;
}
void troca(int *num1, int *num2){
    int aux;

    aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}
