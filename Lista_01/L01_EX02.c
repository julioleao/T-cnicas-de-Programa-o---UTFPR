/*
Nome: Julio Cesario de Paiva Le�o
RA: 1916033
Turma: ES21

EX02 - Fa�a a leitura de dois n�meros na fun��o principal, depois chame uma fun��o para
verificar qual deles � maior, case o primeiro n�mero seja maior, a fun��o retorna o
valor �1�, caso seja o segundo, a fun��o retorna �2� e caso os dois n�meros sejam
iguais deve retornar �3�. Na fun��o principal voc� dever� imprimir uma mensagem
do tipo �o primeiro n�mero � maior� ou �o segundo n�mero � maior� ou ainda �os
dois n�meros s�o iguais� de acordo com o retorno da fun��o de verifica��o. A
fun��o de verifica��o deve estar localizada abaixo da fun��o main() no arquivo5
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
