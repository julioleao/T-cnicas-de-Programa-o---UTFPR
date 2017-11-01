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
FILE *file;
int cont = 0;
 int j = 0;

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
FILE* openTxt(char caminho[30], char modo); // Criar arquivo TXT
FILE* openBin(char caminho[30], char modo); // Criar arquivo BIN
int saveTxt(cliente *cl, int cont);
int saveBin(cliente *cl, int cont);
void abrirTxt(cliente *cl, int cont, int qtd);


// Função principal
int main(){
    int op, qtd;
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
                saveTxt(cl, cont);
                break;
            case 5:
                abrirTxt(cl, cont, qtd);
                break;
            case 6:
                saveBin(cl, cont);
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
        scanf("%[^\n]s", cl[i].nome);
        printf("Informe a Idade: ");
        scanf(" %d", &cl[i].age);
        fflush(stdin);
        printf("Informe a Rua: ");
        scanf("%[^\n]s", cl[i].rua);
        fflush(stdin);
        printf("Informe o Bairro: ");
        scanf("%[^\n]s", cl[i].bairro);
        fflush(stdin);
        printf("Informe a Cidade: ");
        scanf("%[^\n]s", cl[i].city);
        fflush(stdin);
        printf("Informe o CEP: ");
        scanf("%d", &cl[i].cep);
        fflush(stdin);
        printf("Informe o Telefone: ");
        scanf("%[^\n]s", cl[i].tel);
        break;
    }
}

// Função para consulta
void consulta(cliente *cl, int cont){
    char nome[50];
    fflush(stdin);

    if(cont == 0 && j == 0){
        printf("\n\t\aNAO HA REGISTROS!\n");
    } else {
        printf("Digite um nome para busca: ");
        scanf("%[^\n]s", nome);
        system(CLEAR);
        if(j > 0){
            for(i = 0; i < j; i++){
                if(strcmp(cl[i].nome, nome) == 0){
                    printf("Nome: %s\n", cl[i].nome);
                    printf("Idade: %d\n", cl[i].age);
                    printf("Rua: %s\n", cl[i].rua);
                    printf("Bairro: %s\n", cl[i].bairro);
                    printf("Cidade: %s\n", cl[i].city);
                    printf("CEP: %d\n", cl[i].cep);
                    printf("Telefone: %s\n", cl[i].tel);
                }
            }
        } else {
            for(i = 0; i < cont; i++){
                if(strcmp(cl[i].nome, nome) == 0){
                    printf("Nome: %s\n", cl[i].nome);
                    printf("Idade: %d\n", cl[i].age);
                    printf("Rua: %s\n", cl[i].rua);
                    printf("Bairro: %s\n", cl[i].bairro);
                    printf("Cidade: %s\n", cl[i].city);
                    printf("CEP: %d\n", cl[i].cep);
                    printf("Telefone: %s\n", cl[i].tel);
                }
            }
        }
    }
    getch();
}

// Função para listar todos cadastros
void listar(cliente *cl, int cont){

    if(j == 0 && cont == 0){
        printf("\n\t\aNAO HA REGISTROS!\n");
    } else
        if(j > 0){
            for(i = 0; i < j; i++){
                printf("Nome: %s\n", cl[i].nome);
                printf("Idade: %d\n", cl[i].age);
                printf("Rua: %s\n", cl[i].rua);
                printf("Bairro: %s\n", cl[i].bairro);
                printf("Cidade: %s\n", cl[i].city);
                printf("CEP: %d\n", cl[i].cep);
                printf("Telefone: %s\n\n", cl[i].tel);
            }
        } else {
            for(i = 0; i < cont; i++){
                printf("Nome: %s\n", cl[i].nome);
                printf("Idade: %d\n", cl[i].age);
                printf("Rua: %s\n", cl[i].rua);
                printf("Bairro: %s\n", cl[i].bairro);
                printf("Cidade: %s\n", cl[i].city);
                printf("CEP: %d\n", cl[i].cep);
                printf("Telefone: %s\n\n", cl[i].tel);
            }
        }
    getch();
}

int saveTxt(cliente *cl, int cont){
    if(cont == 0){
        printf("\n\t\aNAO HA REGISTROS!\n");
    } else {
        file = openTxt("cliente.txt", 'a');
        for(i = 0; i < cont; i++){
            fprintf(file, "%s %d %s %s %s %d %s\n", cl[i].nome, cl[i].age, cl[i].rua, cl[i].bairro, cl[i].city, cl[i].cep, cl[i].tel);
        }
        fclose(file);
        printf("\n\t\aARQUIVO TXT SALVO COM SUCESSO!\n");
    }
    getch();
}

void abrirTxt(cliente *cl, int cont, int qtd){
   ;
    char op;
    if(cont > 0){
        printf("\n\t\aHA REGISTRO(S) NAO SALVO(S)!\n\tDESEJA SALVA-LO(S) AGORA?\n\n\tS / N: ");
        op = getche();
        if(op == 's' || op == 'S'){
            saveTxt(cl, cont);
        }
    }
    if(openTxt("cliente.txt", 'r') == NULL){
        printf("\n\t\aNAO HA REGISTROS!\n");
    } else {
        file = openTxt("cliente.txt", 'r');
        fseek(file, 0, SEEK_END);
        cl = (cliente*) realloc(cl, (ftell(file)) * sizeof(ftell(file)));
        rewind(file);
        while((fscanf(file, "%s %d %s %s %s %d %s\n", cl[j].nome, &cl[j].age, cl[j].rua, cl[j].bairro, cl[j].city, &cl[j].cep, cl[j].tel)) != EOF){
            printf("Nome: %s\n", cl[j].nome);
            printf("Idade: %d\n", cl[j].age);
            printf("Rua: %s\n", cl[j].rua);
            printf("Bairro: %s\n", cl[j].bairro);
            printf("Cidade: %s\n", cl[j].city);
            printf("CEP: %d\n", cl[j].cep);
            printf("Telefone: %s\n\n", cl[j].tel);
            j++;
        }
        printf("\n\t\aARQUIVO TXT ABERTO COM SUCESSO!\n");
    }
    getch();
}

int saveBin(cliente *cl, int cont){
    if(cont == 0){
        printf("\n\t\aNAO HA REGISTROS!\n");
    } else {
        file = openBin("cliente.bin", 'a');
        fwrite (cl, sizeof(cliente), cont, file);
        fclose(file);
        printf("\n\t\aARQUIVO BIN SALVO COM SUCESSO!\n");
    }
    getch();
}

FILE* openTxt(char caminho[30], char modo){
    switch(modo){
        case 'w':
            file = fopen(caminho, "w");
            break;
        case 'r':
            file = fopen(caminho, "r");
            break;
        case 'a':
            file = fopen(caminho, "a");
            break;
    }
    if(file == NULL){
        printf("\n\t\aErro %d - %s\n", errno, strerror(errno));
        return 0;
    }
    return file;
}

FILE* openBin(char caminho[30], char modo){
    switch(modo){
        case 'w':
            file = fopen(caminho, "wb");
            break;
        case 'r':
            file = fopen(caminho, "rb");
            break;
        case 'a':
            file = fopen(caminho, "ab");
            break;
    }
    if(file == NULL){
        printf("\n\t\aErro %d - %s\n", errno, strerror(errno));
        return 0;
    }
    return file;
}
