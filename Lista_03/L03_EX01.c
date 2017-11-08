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

// Registro de cliente
typedef struct cliente{
    char nome[50], rua[50], bairro[50], city[50], tel[12];
    int age, cep;
}cliente;

// Variáveis globais
int i;
FILE *file;
int cont = 0;
int j = 0;
cliente *cl;

// Funções
int menu(int *op); // Menu
void cadastro(int qtd); // Cadastrar cliente
void consulta(); // Consultar cliente
void listar(); // Listar todos os clientes
FILE* openTxt(char caminho[30], char modo); // Criar arquivo TXT
FILE* openBin(char caminho[30], char modo); // Criar arquivo BIN
int saveTxt(); // Salvar arquivo TXT
int saveBin(); // Salvar arquivo BIN
void abrirTxt(int qtd); // Abrir TXT
void abrirBin(int qtd); // Abrir BIN
int tamanho(); // Calcular quantidade de registros em BIN/TXT

// Função principal
int main(){
    int op, qtd;


    printf("\n\tINFORME A QUANTIDADE DE CADASTROS: ");
    scanf("%d", &qtd);

    cl = (cliente*) malloc(qtd * sizeof(cliente));

    while(menu(&op) != 8){
        switch(op){
            case 1:
                if(cont >= qtd){
                    printf("\n\t\aErro! Memoria cheia!\n");
                    getch();
                } else {
                    cadastro(qtd);
                    cont++;
                }
                break;
            case 2:
                consulta();
                break;
            case 3:
                listar();
                break;
            case 4:
                saveTxt();
                break;
            case 5:
                abrirTxt(qtd);
                break;
            case 6:
                saveBin();
                break;
            case 7:
                abrirBin(qtd);
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
    if(*op == 8){
        printf("\n\t\aATE MAIS JOVEM PADAWAN!\n");
        free(cl);
    }
    return *op;
}

// Função cadastro de cliente
void cadastro(int qtd){
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
void consulta(){
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
void listar(){

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

// Função para salvar em arquivo TXT
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

// Função para abrir arquivo TXT e gravar na memória
void abrirTxt(int qtd){
    if(openTxt("cliente.txt", 'r') == NULL){
        printf("\n\t\aNAO HA REGISTROS!\n");
    } else {
        file = openTxt("cliente.txt", 'r');
        cl = (cliente*) realloc(cl, tamanho(cl) * sizeof(cliente)); // Realloc não está rodando
        rewind(file);

        while(!feof(file)){
            fscanf(file, "%s %d %s %s %s %d %s\n", cl[j].nome, &cl[j].age, cl[j].rua, cl[j].bairro, cl[j].city, &cl[j].cep, cl[j].tel);
            j++;
        }
        fclose(file);
        printf("\n\t\aARQUIVO TXT ABERTO COM SUCESSO!\n");
    }
    getch();
}

// Função para salvar em arquivo BIN
int saveBin(){
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

// Função para abrir arquivo BIN e gravar na memória
void abrirBin(int qtd){
    if(openBin("cliente.bin", 'r') == NULL){
        printf("\n\t\aNAO HA REGISTROS!\n");
    } else {
        file = openBin("cliente.bin", 'r');
        cl = (cliente*) realloc(cl, tamanho(cl) * sizeof(cliente));
        rewind(file);

        while(!feof(file)){
            fscanf(file, "%s %d %s %s %s %d %s\n", cl[j].nome, &cl[j].age, cl[j].rua, cl[j].bairro, cl[j].city, &cl[j].cep, cl[j].tel);
            j++;
        }
        fclose(file);
        printf("\n\t\aARQUIVO BIN ABERTO COM SUCESSO!\n");
    }
    getch();
}

// Função para abrir arquivo TXT
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

// Função para abrir arquivo BIN
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

// Função para contar os registro nos arquivo BIN/TXT
int tamanho(){
    int tam = 0;
    file = openTxt("cliente.txt", 'r');
    while(fgets(cl->nome, 50, file) != NULL){
        tam++;
        cont++;
    }
    return tam;
}
