/*
Nome: Julio Cesario de Paiva Le�o
RA: 1916033
Turma: ES21

EX05. Retorno de dados em fun��es. Na fun��o main crie tr�s vari�veis inteiras chamadas
Raiz, A e Num, e um ponteiro do tipo inteiro chamado Exp inicializado com NULL.
Fa�a Exp receber o endere�o de A. Pergunte ao usu�rio um n�mero e armazene
em Num, depois chame uma fun��o chamada Contas passando a vari�vel Raiz por
referencia, o ponteiro Exp e a vari�vel Num por Valor. Esta fun��o deve calcular a
Raiz do valor armazenado em Num e armazenar em Raiz, calcular o valor de Num
elevado a 2 e armazenar no endere�o apontado por Exp. Depois na fun��o
principal imprima o valor da vari�vel Raiz e o valor apontado por Exp.
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
