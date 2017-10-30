/*faça um programa que lê uma matriz de 3 x 3 elementos usando um
comando for, multiplica cada elemento por 5 e imprime o resultado;*/

#include <stdio.h>

int main() {
    float mat[3][3];
    int i = 0, j = 0;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
           printf("Digite um numero na posicao %d x %d: ", i, j);
           scanf("%f", &mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("A valor na posicao %d x %d * 5 = %.1f\n", i, j, mat[i][j]*5);
        }
        printf("\n");
    }
    return 0;
}
