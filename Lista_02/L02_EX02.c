/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX02. Crie uma estrutura (struct) chamada Contato, com os campos: nome do tipo vetor
de char de 40 posições e telefone do tipo vetor de char de 12 posições. Crie duas
variáveis chamadas contato1 e contato2 do tipo Contato. Faça a leitura dos dados
da variável contato1 e depois copie o conteúdo de contato1 para contato2, logo
após isto imprima na tela as informações de contato2.
*/

#include <stdio.h>
#include <string.h>

typedef struct Contato{
    char name[40];
    char tel[12];
}Contato;

int main(){
    Contato contato1, contato2;

    printf("Informe o nome: ");
    gets(contato1.name);
    printf("Informe o telefone: ");
    gets(contato1.tel);
    strcpy(contato2.name,contato1.name);
    strcpy(contato2.tel,contato1.tel);

    printf("\n    Nome: %s\nTelefone: \%s\n", contato2.name, contato2.tel);
    return 0;
}
