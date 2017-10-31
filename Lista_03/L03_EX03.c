/* CABEÇALHO DO EXERCÍCIO
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: Engenharia de Software - ES21

3. Faça um programa que calcule ​recursivamente a soma dos números no intervalo
de ​1 a ​N ​, ou seja ​(1 + 2 + 3 + 4...+ N) ​. O Valor ​N deve ser inteiro e digitado pelo
usuário.
*/


#include <stdio.h>

int soma(int n);

int main(){
    int n;
    do{
        printf("Digite um numero inteiro acima de 0: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("\nO resultado da soma de 1 ate %d e de %d\n", n, soma(n));
    return 0;
}

int soma(int n){
    int p = n, sum = 1;

    if(n == 1){
        return p;
    } else {
        p = p + soma(n - 1);
        return p;
    }
}
