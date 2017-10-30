#include <stdio.h>

int main(){
    float num, sum = 0;
    int i = 0;

    printf("Digite um numero: ");
    scanf("%d", &num);

    while (i < 10){
        sum = sum + num;
        i++;
    }
    printf("%d\n", sum);
    return 0;
}
