/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX07 - Faça um programa que defina uma função chamada ​sumFour ​que receberá por
referência ​uma variável inteira, e adicionará quatro ao valor dela. Na função
principal (main) crie uma variável local inteira, leia com o usuário um valor para ela,
e chame a função somaQuatro passando-a. Depois imprima na tela o novo valor da7
variável;
*/
#include <stdio.h>

int sumFour(int *num);

int main(){
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);
    sumFour(&num);

    printf("\nO resultado sera %d. \n", num);

    return 0;
}

int sumFour(int *num){
    *num = *num + 4;
    return *num;
}
