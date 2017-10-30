/* CABEÇALHO DO EXERCÍCIO
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: Engenharia de Software - ES21

1. Crie ​um ​programa ​com ​o ​seguinte ​menu ​de ​opções:
<1> Cadastrar Cliente
<2> Consultar Nome
<3> Listar Todos
<4> Salvar Como Arquivo Texto
<5> Recuperar Arquivo Texto
<6> Salvar Como Arquivo Binário
<7> Recuperar Arquivo Binário
<8> Sair
Cada uma destas opções, com exceção de sair, chama uma função que executará
o que ela indica. Este programa irá cadastrar os seguintes dados do cliente: Nome,
Idade, Rua. Bairro, Cidade, CEP e Telefone, todos estes campos devem fazer parte
de uma struct que será utilizada para resolver o problema. O número máximo de
4
clientes que podem ser cadastrados no sistema será perguntado no início da
execução do programa. Caso este limite seja alcançado, no momento de um novo
cadastro, deverá ser impresso na tela uma mensagem de erro. Deve-se utilizar
alocação dinâmica para armazenar os elementos em um vetor de registros. Na
opção <2> deverá ser consultado um nome de cliente, caso seja localizado, sua
ficha e impressa na tela. Na opção <3> é impresso o nome, idade, e telefone de
todos os clientes cadastrados. Deve-se utilizar manipulação de arquivos para
realizar as operações respectivas dos itens <4>, <5>, <6> e <7>. Deve-se utilizar os
nomes de arquivos: cliente.txt e cliente.bin para armazenar e recuperar os dados.
Você poderá escolher a forma como irá percorrer os arquivos para realizar as
operações ​de ​leitura ​e ​escrita
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Hack para limpar a tela
 */

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

// Variáveis globais
int i;

// Registro de cliente
typedef struct cliente{
    char nome[50], rua[50], bairro[50], city[50], tel[12];
    int age, cep;
}cliente;

// Funções
int menu(int *op); // Menu
void cadastro(cliente *cl, int qtd, int cont); // Cadastrar cliente
void consulta(cliente *cl, int cont); // Consultar cliente
void listar(cliente *cl, int cont); // Listar todos os clientes

// Função principal
int main(){
    int op, qtd, cont = 0;
    cliente *cl;

    printf("\n\tINFORME A QUANTIDADE DE CADASTROS: ");
    scanf("%d", &qtd);

    cl = (cliente*) malloc(qtd * sizeof(cliente));

    while(menu(&op) != 8){
        switch(op){
            case 1:
                if(cont == qtd){
                    printf("\n\t\aErro! Memoria cheia!\n");
                    getch();
                } else {
                    cadastro(cl, qtd, cont);
                    cont++;
                }
                break;
            case 2:
                consulta(cl, cont);
                break;
            case 3:
                listar(cl, cont);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            default:
                printf("\n\t\aOPCAO INVALIDA!\n");
                getch();
                break;
        }
    }
    return 0;
}

// Função Menu
int menu(int *op){
    system(CLEAR);
    printf("\t<1> Cadastrar Cliente\n");
    printf("\t<2> Consultar Nome\n");
    printf("\t<3> Listar Todos\n");
    printf("\t<4> Salvar Como Arquivo Texto\n");
    printf("\t<5> Recuperar Arquivo Texto\n");
    printf("\t<6> Salvar Como Arquivo Binario\n");
    printf("\t<7> Recuperar Arquivo Binario\n");
    printf("\t<8> Sair\n");
    printf("\n\tDigite a opcao desejada: ");
    scanf("%d", &*op);
    system(CLEAR);

    return *op;
}

// Função cadastro de cliente
void cadastro(cliente *cl, int qtd, int cont){
    for(i = cont; i < qtd; i++){
        printf("Cadastro No %d\n\n", cont+1);
        fflush(stdin);
        printf("Informe o Nome: ");
        fgets(cl[i].nome, 50, stdin);
        printf("Informe a Idade: ");
        scanf("%d", &cl[i].age);
        fflush(stdin);
        printf("Informe a Rua: ");
        fgets(cl[i].rua, 50, stdin);
        printf("Informe o Bairro: ");
        fgets(cl[i].bairro, 50, stdin);
        printf("Informe a Cidade: ");
        fgets(cl[i].city, 50, stdin);
        printf("Informe o CEP: ");
        scanf("%d", &cl[i].cep);
        fflush(stdin);
        printf("Informe o Telefone: ");
        fgets(cl[i].tel, 12, stdin);
        break;
    }
}

// Função para consulta
void consulta(cliente *cl, int cont){
    char nome[50];
    fflush(stdin);

    if(cont == 0){
        printf("\n\t\aNAO HA REGISTROS!\n");
    } else {
        printf("Digite um nome para busca: ");
        fgets(nome, 50, stdin);
        system(CLEAR);
        for(i = 0; i < cont; i++){
            if(strcmp(cl[i].nome, nome) == 0){
                printf("Nome: %s", cl[i].nome);
                printf("Idade: %d\n", cl[i].age);
                printf("Rua: %s", cl[i].rua);
                printf("Bairro: %s", cl[i].bairro);
                printf("Cidade: %s", cl[i].city);
                printf("CEP: %d\n", cl[i].cep);
                printf("Telefone: %s\n", cl[i].tel);
            }
        }
    }
    getch();
}

// Função para listar todos cadastros
void listar(cliente *cl, int cont){

    if(cont == 0){
        printf("\n\t\aNAO HA REGISTROS!\n");
    } else {
        for(i = 0; i < cont; i++){
            printf("Nome: %s", cl[i].nome);
            printf("Idade: %d\n", cl[i].age);
            printf("Rua: %s", cl[i].rua);
            printf("Bairro: %s", cl[i].bairro);
            printf("Cidade: %s", cl[i].city);
            printf("CEP: %d\n", cl[i].cep);
            printf("Telefone: %s\n\n", cl[i].tel);
        }
    }
    getch();
}
