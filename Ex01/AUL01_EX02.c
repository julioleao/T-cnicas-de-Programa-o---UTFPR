#include <stdio.h>

int main() {
    int a, cont = 0;
    float b;

    printf("Digite um numero para A: ");
    scanf("%d", &a);
    printf("Digite um numero para B: ");
    scanf("%f", &b);

    for (cont = 0; cont < a; cont++){
        printf("%.1f\n", b);
    }
    return 0;
}
