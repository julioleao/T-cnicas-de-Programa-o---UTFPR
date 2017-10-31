/* CABEÇALHO DO EXERCÍCIO
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: Engenharia de Software - ES21

4. Implemente um programa que dados dois números inteiros ​X e ​N ​, calcule
recursivamente​ ​o​ ​valor​ ​de​ ​​X ​​ ​elevado​ ​a​ ​​N ​.
*/

#include <stdio.h>

int pot(int x, int n);

int main(){
    int n, x;
    do{
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &x);
        printf("Digite outro numero inteiro positivo: ");
        scanf("%d", &n);
        system("cls");
    } while (n < 0 || x < 0);

    printf("\nO resultado de %d elevado a %d e de %d\n", x, n, pot(x, n));
    return 0;
}

int pot(int x, int n){
    int p = x;

    if(n == 1){
        return p;
    } else {
        p = x * pot(x, n-1);
        return p;
    }
}
