/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX05. Retorno de dados em funções. Na função main crie três variáveis inteiras chamadas
Raiz, A e Num, e um ponteiro do tipo inteiro chamado Exp inicializado com NULL.
Faça Exp receber o endereço de A. Pergunte ao usuário um número e armazene
em Num, depois chame uma função chamada Contas passando a variável Raiz por
referencia, o ponteiro Exp e a variável Num por Valor. Esta função deve calcular a
Raiz do valor armazenado em Num e armazenar em Raiz, calcular o valor de Num
elevado a 2 e armazenar no endereço apontado por Exp. Depois na função
principal imprima o valor da variável Raiz e o valor apontado por Exp.
*/

#include <stdio.h>
#include <math.h>

void contas(int *raiz, int **exp, int num);
int main(){
    int raiz,a, num;
    int *exp = NULL;

    exp = &a;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    contas(&raiz, &exp, num);

    printf("Raiz = %d\nQuadrado = %d\n", raiz, *exp);

    return 0;
}

void contas(int *raiz, int **exp, int num){
    *raiz = sqrt(num);
    **exp = num * num;
}
