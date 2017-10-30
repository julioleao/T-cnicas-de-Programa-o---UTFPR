/*faça um programa que use uma função em que receba 2 números e retorne o
maior valor;*/

#include <stdio.h>

int greater(int num1, int num2);
int main(){
    int num1, num2;

    printf("Digite um numero: ");
    scanf("%d", &num1);
    printf("Digite outro numero: ");
    scanf("%d", &num2);
    printf("\n");
    greater(num1, num2);

    return 0;
}

int greater(int num1, int num2){
    if (num1 < num2){
        printf("O maior numero e %d\n", num2);
    } else {
        printf("O maior numero e %d\n", num1);
    }
}
