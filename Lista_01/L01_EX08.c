/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX08 - Faça um programa que defina uma função chamada ​subTwo ​que receberá por
referência uma variável inteira, e subtrairá dois do valor dela, caso o novo valor não
fique menor que zero. Se a função ​subTwo ​conseguir subtrair ela deve retornar o
valor 1 indicando sucesso, caso não seja possível, a função deverá retornar 0
indicando fracasso. Na função principal (main) crie uma variável local inteira, leia
com o usuário um valor para ela, e chame a função ​subTwo ​passando-a. Depois
caso ela tenha retirado dois imprima na tela o novo valor da variável, caso não
imprima uma mensagem de erro;
*/
#include <stdio.h>

int subTwo(int *num);

int main(){
    int num;

    printf("Informe um numero inteiro: ");
    scanf("%d", &num);

    if(subTwo(&num) == 0){
        printf("\nERRO!!\n");
    } else {
        printf("\nO resultado sera %d.\n", num);
    }

    return 0;
}

int subTwo(int *num){
    if(*num - 2 < 0){
        return 0;
    } else {
        *num = *num - 2;
        return 1;
    }
}
