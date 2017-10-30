#include <stdio.h>
/*faça um programa que cria um vetor com 5 elementos inteiros, lê 5 números
do teclado, armazena os números no vetor e imprime o vetor na ordem
inversa;
*/

int main() {
    int num[5], i = 0;

    for (i = 0; i < 5; i++){
        printf("Digite o %do numero: ", i+1);
        scanf("%d", &num[i]);
    }
    printf("\n");
    for (i = 4; i >= 0; i--){
        printf("%do numero: %d\n", i+1, num[i]);
    }
    return 0;
}
