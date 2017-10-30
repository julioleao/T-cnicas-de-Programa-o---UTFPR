/*
Nome: Julio Cesario de Paiva Le�o
RA: 1916033
Turma: ES21

EX01. Defina uma estrutura (struct) chamada FichaCliente com os seguintes campos:
nome e rua do tipo vetor de char de 50 posi��es, n�mero do tipo int, cidade e
estado do tipo vetor de char de 30 posi��es e CEP do tipo vetor de char de 9
posi��es. Crie uma vari�vel chamada cliente do tipo estrutura FichaCliente e fa�a a
entrada dos dados, imprimindo depois na tela a entrada feita pelo usu�rio.
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
