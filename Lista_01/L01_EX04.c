/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX04 - Faça um programa que pergunte ao usuário qual a posição da série de Fibonacci, e
depois imprima o número correspondente da série. Evite a entrada de posições
inválidas (menores que 0). Para calcular o valor da série crie uma função específica
para isto, que receba a posição na série e retorne o valor calculado. A série de
Fibonacci tem o primeiro termo 0 igual a 0, o termo 1 igual a 1, e a partir do terceiro
termo cada termo é a soma dos dois termos anteriores.
​Série de Fibonacci​: ​0, 1, 1, 2, 3, 5, 8, 13, …
*/
#include <stdio.h>
int fibonacci(int pos);
int main(){
    int position;

    do{
        printf("Informe a posicao da serie fibonacci: ");
        scanf("%d", &position);
    }while(position <= 0);
    printf("\n%d\n", fibonacci(position));
    return 0;
}

int fibonacci(int pos){
    int i, num1 = 0, num2 = 1, total;
    if(pos == 1){
        return num1;
    } else
        if (pos == 2){
            return num2;
        } else {
            for(i = 2; i < pos; i++){
                total = num1 + num2;
                num1 = num2;
                num2 = total;
            }
        }
    return total;
}
