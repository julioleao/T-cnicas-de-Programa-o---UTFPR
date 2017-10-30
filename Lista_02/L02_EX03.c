/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX03. Faça um programa que crie uma estrutura de dados (struct) chamada Aluno. Esta
estrutura deve conter um campo chamado nome, do tipo vetor de char, e quatro
campos do tipo int: Nota1, Nota2, Nota3 e Nota4. Defina um vetor de 10 posições do
tipo da estrutura Aluno. Faça a entrada de todos os dados para as 10 posições e
depois imprima na tela estas informações em formato de colunas.
*/

#include <stdio.h>
#define TAM 10
int i = 0, j = 0;

typedef struct aluno{
    char nome[50];
    int nota[4];
}aluno;

void printGrade(aluno al[]);
void insertGrade(aluno al[]);

int main(){
    aluno al[TAM];

    insertGrade(al);
    return 0;
}

void insertGrade(aluno al[]){
    for(i = 0; i < TAM; i++){
        fflush(stdin);
        printf("Informe o nome do aluno %d: ", i+1);
        gets(al[i].nome);
        printf("\n");
        for(j = 0; j < 4; j++){
           printf("Informe a nota %d: ", j+1);
           scanf("%d", &al[i].nota[j]);
        }
        printf("\n");
    }
    printf("\n---------------------------------------------------\n");
    printGrade(al);
}

void printGrade(aluno al[]){
    for(i = 0; i < TAM; i++){
        fflush(stdin);
        printf("Aluno %d: %s\n", i+1, al[i].nome);
        printf("\n");
        for(j = 0; j < 4; j++){
           printf("Nota %d: %d\n", j+1, al[i].nota[j]);
        }
        printf("\n");
    }
}
