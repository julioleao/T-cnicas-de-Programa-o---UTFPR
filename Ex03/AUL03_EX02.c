/*criar uma função que recebe 3 valores float e retorne o quadrado do 1º + a
soma dos outros dois. Deve retornar o tipo inteiro.*/

#include <stdio.h>
int operation(float num[3]);
int main(){
    float num[3];
    int i;

    for(i = 0; i < 3; i++){
        printf("Digite o %do numero: ", i+1);
        scanf("%f", &num[i]);
    }
    operation(num);
    return 0;
}

int operation(float num[3]){
    int exp, sum;
    exp = num[0] * num[0];
    sum = num[1] + num[2];
    printf("\nO quadrado do primeiro numero e %d\n", exp);
    printf("A  soma dos numero %.2f + %.2f = %d\n", num[1], num[2], sum);
}
