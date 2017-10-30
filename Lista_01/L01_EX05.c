/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX05 - Faça um programa que apresente o seguinte menu para o usuário.
Manipulação de Números
======================
<1> - Verificar se um número é par ou ímpar
<2> - Verificar se um número é primo
<3> - Calcular o fatorial de um número
<4> - Calcular a raiz quadrada de um número
<5> - Sair
======================
Qual opção escolhida?
Nas opções de 1 a 4 deve-se primeiro ler o número que será usado e depois chamar
uma função específica para fazer cada ação pedida. Uma função para calcular
fatorial, se o número é primo, e se é par ou ímpar. Para o cálculo da raiz quadrada
utilize a função sqrt da biblioteca math.h. Caso o usuário escolha a opção 5 use a
função exit(int) para encerrar o programa. Caso o usuário entre com uma opção6
inválida apresente uma mensagem de erro e retorne ao menu. Utilize a estrutura
switch ​com ​break​, e a ​do/while​ para fazer o menu.
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int includeNumber();
void pairOdd();
void primeNumber();
void factorial();
void squareRoot();

int main(){
    int op;

    do{
        printf("\nManipulacao de Numeros\n");
        printf("=================================================\n");
        printf("<1> - Verificar se um numero e par ou impar\n");
        printf("<2> - Verificar se um numero e primo\n");
        printf("<3> - Calcular o fatorial de um numero\n");
        printf("<4> - Calcular a raiz quadrada de um numero\n");
        printf("<5> - Sair\n");
        printf("=================================================\n");
        printf("Qual opcao escolhida?\n");
        scanf("%d", &op);

        switch (op){
            case 1:
                pairOdd();
                break;
            case 2:
                primeNumber();
                break;
            case 3:
                factorial();
                break;
            case 4:
                squareRoot();
                break;
            case 5:
                exit(0);
            default:
                printf ("Opcao invalida digite ENTER para continuar\n");
                getche();
                break;
        }


    }while(op != 5);

    return 0;
}

int includeNumber(){
    int num;

    printf("\nDigite um numero: ");
    scanf("%d", &num);
    return num;
}

void pairOdd(){
    if(includeNumber() % 2 == 0){
        printf("O numero e par\n");
        getche();
    } else {
        printf("O numero e impar\n");
        getche();
    }
}

void primeNumber(){
    int cont = 0, i, num;
    num = includeNumber();
    for(i = 1; i <= num; i++){
        if(num % i == 0){
            cont++;
        }
    }

    if (cont == 2){
        printf("O numero e primo!\n");
        getche();
    } else {
        printf("O numero NAO e primo!\n");
        getche();
    }
}

void factorial(){
    int i, result, num;

    num = includeNumber();
    result = num;

    for (i = 1; i < result; i++){
        num *= i;
    }
    printf("O fatorial de %d e %d\n", result, num);
    getche();
}

void squareRoot(){
    float num;

    printf("\nDigite um numero: ");
    scanf("%f", &num);

    if (num < 0){
        printf("Nao existe raiz valida\n");
    } else {
        printf("A raiz quadrada de %.2f e %.2f\n", num, sqrt(num));
    }

}
