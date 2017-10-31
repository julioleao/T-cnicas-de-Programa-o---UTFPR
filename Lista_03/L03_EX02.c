#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;
int quant;

void qtd(int *media);
void idade(int *media);
float mediaId(int *media);
void listas(int *media);

int main(){
    int *media;

    qtd(media);

    free(media);

    return 0;
}

void qtd(int *media){
    printf("Informe a quantidade de pessoas: ");
    scanf("%d", &quant);
    system("cls");
    media = (int*) malloc(quant * sizeof(int));
    if (media == NULL){
        printf("\n\t\aErro %d: %s\n", errno, strerror(errno));
        exit(1);
    }
    idade(media);
    listas(media);
    printf("\n\t\aA media de idade de todas as pessoas cadastradas e de %.2f ano(s).\n", mediaId(media));
}

void idade(int *media){
    for(i = 0; i < quant; i++){
        printf("Informe a idade da pessoa %d: ", i+1);
        scanf("%d", &media[i]);
        system("cls");
    }
}

float mediaId(int *media){
    float result, soma = 0;
    for(i = 0; i < quant; i++){
        soma = soma + media[i];
    }

    result = soma / quant;
    return result;
}

void listas(int *media){
    for(i = 0; i < quant; i++){
        printf("Idade da pessoa %d: %2.d ano(s).\n", i+1, media[i]);
    }
}
