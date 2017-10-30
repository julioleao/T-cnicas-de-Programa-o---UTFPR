/*
Nome: Julio Cesario de Paiva Le�o
RA: 1916033
Turma: ES21

EX04. Passagem de dados por refer�ncia. Crie um programa que leia dois valores inteiros
na fun��o principal, depois chame uma fun��o chamada Troca passando as duas
vari�veis inteiras lidas como par�metros por refer�ncia. Esta fun��o ir� inverter o
valor das duas vari�veis. Depois na fun��o principal imprima na tela os novos
valores das duas vari�veis
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
