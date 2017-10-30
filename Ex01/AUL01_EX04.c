#include <stdio.h>

int main(){
    float num1, num2;
    int op = -1;

    do{
        printf("\nInforme o primeiro numero: ");
        scanf("%f", &num1);
        printf("Informe o segundo numero: ");
        scanf("%f", &num2);
        printf("\nInforme a operacao desejada: \n1 - SOMA\n2 - SUBTRACAO\n3 - MULTIPLICACAO\n4 - DIVISAO\n0 - SAIR\n\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("A soma sera: %f\n", num1 + num2);
                break;
            case 2:
                printf("A subtracao sera: %f\n", num1 - num2);
                break;
            case 3:
                printf("A multiplicacao sera: %f\n", num1 * num2);
                break;
            case 4:
                printf("A divisao sera: %f\n", num1 / num2);
                break;
            case 0:
                break;
        }
    } while(op != 0);
    return 0;
}
