/*crie um que peça um número inicial ao usuário, uma razão e calcule os termos
de uma P.A (Progressão Aritmética), armazenando esses valores em um vetor
de tamanho 10;*/

#include <stdio.h>

int main(){
    int num, rate, i;
    int pa[10];

    printf("Digite um numero: ");
    scanf("%d", &num);
    printf("Digite uma razao: ");
    scanf("%d", &rate);
    printf("\n");
    for(i = 0; i < 10; i++){
        num = num + rate;
        pa[i] = num;
        printf("%d ", pa[i]);
    }
    printf("\n");
    return 0;
}
