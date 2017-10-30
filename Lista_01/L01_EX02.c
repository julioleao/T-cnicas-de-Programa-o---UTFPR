/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX02 - Faça a leitura de dois números na função principal, depois chame uma função para
verificar qual deles é maior, case o primeiro número seja maior, a função retorna o
valor “1”, caso seja o segundo, a função retorna “2” e caso os dois números sejam
iguais deve retornar “3”. Na função principal você deverá imprimir uma mensagem
do tipo “o primeiro número é maior” ou “o segundo número é maior” ou ainda “os
dois números são iguais” de acordo com o retorno da função de verificação. A
função de verificação deve estar localizada abaixo da função main() no arquivo5
fonte.
*/
#include <stdio.h>

int equal(int n1, int n2);

int main(){
    int num1, num2, result;

    printf("Digite dois numeros inteiros: \n");
    scanf("%d", &num1);
    scanf("%d", &num2);
    result = equal(num1,num2);

    if(result == 1){
        printf("\nO primeiro numero e maior\n");
    } else
        if(result == 2){
            printf("\nO segundo numero e maior\n");
        } else {
            printf("\nOs dois numeros sao iguais\n");
        }
    return 0;
}

int equal(int n1, int n2){
    if (n1 > n2){
        return 1;
    } else
        if (n2 > n1){
            return 2;
        } else {
            return 3;
        }
}
