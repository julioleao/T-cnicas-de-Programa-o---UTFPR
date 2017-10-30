/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX01. Defina uma estrutura (struct) chamada FichaCliente com os seguintes campos:
nome e rua do tipo vetor de char de 50 posições, número do tipo int, cidade e
estado do tipo vetor de char de 30 posições e CEP do tipo vetor de char de 9
posições. Crie uma variável chamada cliente do tipo estrutura FichaCliente e faça a
entrada dos dados, imprimindo depois na tela a entrada feita pelo usuário.
*/


#include <stdio.h>

typedef struct FichaCliente{
    char name[50];
    char street[50];
    int num;
    char city[30];
    char state[30];
}FichaCliente;

int main() {
    FichaCliente cliente;

    printf("Informe o nome do cliente: ");
    gets(cliente.name);
    printf("Informe o nome da rua: ");
    gets(cliente.street);
    printf("Informe o numero da rua: ");
    scanf("%d", &cliente.num);
    fflush(stdin);
    printf("Informe o nome da cidade: ");
    gets(cliente.city);
    printf("Informe o nome do estado (UF): ");
    gets(cliente.state);
    printf("\n%s\n%s\n%d\n%s\n%s\n", cliente.name, cliente.street, cliente.num, cliente.city, cliente.state);
    return 0;
}
