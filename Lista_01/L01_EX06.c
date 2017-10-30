/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX06 - Faça um programa que apresente o seguinte menu para o usuário:
Controle de Produtos
====================
<1> - Adicionar dados de um produto
<2> - Remover um produto
<3> - Listar todos os produtos
<4> - Listas apenas produtos com estoque zerado
<5> - Valor total em estoque
<6> - Sair
======================
Qual opção escolhida?
O usuário poderá entrar no máximo com 30 produtos. Para cada produto
armazene o código (int), a quantidade em estoque (int), e o valor unitário (float).
Para isto utilize três vetores. Na opção 1 o usuário entrará com os dados de apenas
um produto. Caso o usuário tente executar as opções 2, 3, 4, ou 5 e não exista
nenhum produto cadastrado mostre uma mensagem de alerta. Caso o usuário
tente cadastrar os dados de um novo produto e não exista mais espaço nos vetores
de uma mensagem de erro. Na opção 2 o usuário deverá entrar com o código do
produto que será removido, caso o produto não seja encontrado de uma
mensagem de alerta, e caso o produto seja apagado corretamente de uma
mensagem de sucesso. Na opção 5 deverá ser impresso o valor total em estoque, o
valor em estoque de cada produto é o eu valor unitário vezes a quantidade que
existe daquele produto em estoque. O valor total em estoque é a soma dos valores
em estoque de todos os produtos. Caso o usuário escolha a opção 6 use a função
exit(int) para encerrar o programa. Caso escolha uma opção inválida de uma
mensagem de erro e retorne ao menu. As opções de 1 a 5 devem chamar funções
especificas para realizar as atividades propostas. Utilize a estrutura switch com
break, e a do/while para fazer o menu.
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM 30

int cont;
char opCh;

typedef struct product{
    int cod;
    int qtd;
    float value;
    int cad;
}product;

void menu(product prod[]);
void listProd(product prod[], int cont);
void listProdZero(product prod[], int cont);
void totalValue(product prod[], int cont);

int main(){
    product prod[TAM];
    menu(prod);

    return 0;
}

void menu(product prod[]){
    int op;
    do{
        printf("Controle de Produtos\n");
        printf("======================\n");
        printf("<1> - Adicionar dados de um produto\n");
        printf("<2> - Remover um produto\n");
        printf("<3> - Listar todos os produtos\n");
        printf("<4> - Listas apenas produtos com estoque zerado\n");
        printf("<5> - Valor total em estoque\n");
        printf("<6> - Sair\n");
        printf("======================\n");
        printf("Qual opcao escolhida? ");
        scanf("%d", &op);
        switch (op){
            case 1:
                do{
                    readData(prod, cont);
                    cont++;
                    printf("\nDeseja cadastrar outro produto (s/n)? ");
                    opCh = getch();
                    printf("\n");
                } while(opCh != 'n' && opCh != 'N');
                break;
            case 2:
                if(prodDelete(prod, cont) == 0){
                    printf("\nProduto deletado com Sucesso!\n");
                    cont--;
                } else {
                    printf("\nCodigo invalido!\n");
                }
                fflush(stdin);
                printf("\nDigite alguma tecla para voltar\n");
                opCh = getch();
                printf("\n");
                break;
            case 3:
                listProd(prod, cont);
                break;
            case 4:
                listProdZero(prod, cont);
                break;
            case 5:
                totalValue(prod, cont);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nOPCAO INVALIDA!\n\n");
        }
    } while (op != 6);
}

int readData(product prod[], int cont){
    int i, j;
    char op;
    if(cont < TAM){
        for(i = cont; i < TAM; i++){
            printf("\nPara o produto n. %d\nINFORME\n\n", i+1);
            printf("Codigo: ");
            scanf("%d", &prod[i].cod);
            printf("Quantidade: ");
            scanf("%d", &prod[i].qtd);
            printf("Valor: R$ ");
            scanf("%f", &prod[i].value);
            return 0;
        }
    }else{
        printf("\nCadastros atingiram o limite\n");
    }
}

int prodDelete(product prod[], int cont){
    int i, j;
    int cod;

    if(cont == 0){
        printf("\nNenhum cadastro encontrado!\nPressione alguma tecla para continuar\n");
        opCh = getch();
    } else{
        printf("\nCod\t|Qtd\t|Valor\t\n");
        for(i = 0; i < cont; i++){
            printf("%d\t|%d\t|R$%.2f\t\n", prod[i].cod, prod[i].qtd, prod[i].value);
        }
    }
    printf("\nDigite o codigo do produto que deseja excluir: ");
    scanf("%d", &cod);
    for(i = 0; i < cont; i++){
        if(cod == prod[i].cod){
            for(j = i; j < cont; j++){
                prod[j].cod = prod[j+1].cod;
                prod[j].qtd = prod[j+1].qtd;
                prod[j].value = prod[j+1].value;
                return 0;
            }
        }
    }
}

void listProd(product prod[], int cont){
    int i;

    if(cont == 0){
        printf("\nNenhum cadastro encontrado!\nPressione alguma tecla para continuar\n");
        opCh = getch();
    } else{
        printf("\nCod\t|Qtd\t|Valor\t\n");
        for(i = 0; i < cont; i++){
            printf("%d\t|%d\t|R$%.2f\t\n", prod[i].cod, prod[i].qtd, prod[i].value);
        }
    }
    printf("\nDigite alguma tecla para voltar\n");
    opCh = getch();
    printf("\n");
}

void listProdZero(product prod[], int cont){
    int i;

    if(cont == 0){
        printf("\nNenhum cadastro encontrado!\nPressione alguma tecla para continuar\n");
        opCh = getch();
    } else{
        printf("\nCod\t|Qtd\t|Valor\t\n");
        for(i = 0; i < cont; i++){
            if(prod[i].qtd <= 0){
                printf("%d\t|%d\t|R$%.2f\t\n", prod[i].cod, prod[i].qtd, prod[i].value);
            }
        }
    }
    printf("\nDigite alguma tecla para voltar\n");
    opCh = getch();
    printf("\n");
}

void totalValue(product prod[], int cont){
    int i;
    float sum = 0;

    if(cont == 0){
        printf("\nNenhum cadastro encontrado!\nPressione alguma tecla para continuar\n");
        opCh = getch();
    } else{
        for(i = 0; i < cont; i++){
            sum += (prod[i].qtd * prod[i].value);
        }
    }
    printf("\nO valor total em estoque R$ %.2f\n", sum);
    printf("\nDigite alguma tecla para voltar\n");
    opCh = getch();
    printf("\n");
}
