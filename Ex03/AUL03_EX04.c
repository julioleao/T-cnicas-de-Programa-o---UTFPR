/*faça um programa que utilize funções para preencher e imprimir um vetor. Ela deve receber um vetor e
seu tamanho. Deve tratar as instruções de preenchimento e retornar o vetor preenchido, depois deve
invocar outra função que passe o vetor e o imprima na tela do usuário;
*/

#include <stdio.h>
void vector(int size);
void result(char str[]);
int main(){
    int size;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &size);
    vector(size);
    return 0;
}

void vector(int size){
    char str[size];

    fflush(stdin);
    printf("Preencha o vetor de tamanho %d: ", size);
    gets(str);
    result(str);
}

void result(char str[]){
    printf("\n%s\n", str);
}
