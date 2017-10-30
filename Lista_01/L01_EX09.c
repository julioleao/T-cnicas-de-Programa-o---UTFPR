/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX09 - Faça um programa que leia o preço de 10 produtos e armazene em um vetor, e
depois imprima a média de preços e o valor do produto mais caro. Deverá ser
criada uma função para a leitura dos dados, uma que retorne a média de preços, e
uma que retorne o produto mais caro. Todas estas funções devem receber o vetor
como parâmetro. A função main deverá apenas declarar o vetor e chamar estas
funções. Utilize constante para controlar o tamanho do vetor;
*/
#include <stdio.h>
#define TAM 10

void readData(float prod[]);
float mean(float prod[]);
float highestValue(float prod[]);

int main(){
    float product[TAM];
    readData(product);
    return 0;
}

void readData(float prod[]){
    int i;

    for(i = 0; i < TAM; i++){
        printf("Informe o preco do produto %d: ", i+1);
        scanf("%f", &prod[i]);
    }
    printf("\nA media de precos sera: R$ %.2f.\n", mean(prod));
    printf("O maior valor informado foi R$ %.2f.\n", highestValue(prod));
}

float mean(float prod[]){
    int i;
    float sum = 0;

    for(i = 0; i < TAM; i++){
        sum += prod[i];
    }
    sum = sum / TAM;
    return sum;
}

float highestValue(float prod[]){
    int i;
    float highest = 0;
    for(i = 0; i < TAM; i++){
        if(i == 0){
            highest = prod[i];
        } else
            if(prod[i] > highest){
                highest = prod[i];
            }
    }
    return highest;
}
