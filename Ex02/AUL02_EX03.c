/*crie um que receba 10 números, armazene eles em um vetor e diga qual
elemento é o maior, qual é o menor, e seus valores;
*/

#include <stdio.h>

int main(){
    float num[10], larger = 0, smaller = 0;
    int i;

    for(i = 0; i < 10; i++){
        printf("Informe o %do numero: ", i+1);
        scanf("%f", &num[i]);
        if(i == 0){
            larger = num[i];
            smaller = num[i];
        }
        if(larger < num[i]){
            larger = num[i];
        } else
            if(smaller > num[i]){
                smaller = num[i];
            }
    }
    printf("\nO maior valor informado e %f e o menor e %f\n", larger, smaller);

    return 0;
}
