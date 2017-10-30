/*
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
#include <locale.h>

/**
 * Hack para limpar a tela
 */

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

int main(){
    setlocale(LC_ALL, "Portuguese");
    int op;
    while(menu(&op) != 8){
        switch(op){
            case 1:
                break;
            case 2:
                break;
            case 3:
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
                printf("\n\t\aOpcao invalida\n");
                getch();
                break;
        }


    }

    return 0;
}

int menu(int *op){
    setlocale(LC_ALL,"Portuguese");
    printf("\t<1> Cadastrar Cliente\n");
    printf("\t<2> Consultar Nome\n");
    printf("\t<3> Listar Todos\n");
    printf("\t<4> Salvar Como Arquivo Texto\n");
    printf("\t<5> Recuperar Arquivo Texto\n");
    printf("\t<6> Salvar Como Arquivo Binário\n");
    printf("\t<7> Recuperar Arquivo Binário\n");
    printf("\t<8> Sair\n");
    printf("\n\tDigite a opcao desejada: ");
    scanf("%d", *op);

    return *op;








}