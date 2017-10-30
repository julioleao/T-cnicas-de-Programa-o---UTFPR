/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

EX10 - Faça um programa que apresente o seguinte menu para o usuário:
Controle de Notas
=================
<1> - Adicionar notas de um aluno
<2> - Listar todas as notas e médias
<3> - Listar a maior nota na prova 1 e na prova 2
<4> - Sair
=================
Qual opção escolhida?
O usuário poderá entrar no máximo com as notas de 30 alunos. Para isto crie uma
matriz de reais de duas colunas, onde cada uma armazenará a nota de uma prova.
Na opção 1 o usuário entrará com as duas notas de um aluno. Caso o usuário tente
executar as opções 2 ou 3 e não exista nenhuma nota cadastrada mostre uma
mensagem de alerta. Caso o usuário tente cadastrar os dados de um novo aluno e
não exista mais espaço na matriz de uma mensagem de erro. Na opção 2 liste em
formato de tabela as notas e médias de todos os alunos. Na opção 3 apresente a
maior nota da prova 1 e da prova 2 cadastradas. Caso o usuário escolha a opção 4
use a função exit(int) para encerrar o programa. Caso escolha uma opção inválida8
de uma mensagem de erro e retorne ao menu. As opções de 1 a 3 devem chamar
funções especificas para realizar as atividades propostas, passando-se a matriz com
parâmetro. Utilize a estrutura switch com break, e a do/while para fazer o menu, e
constantes para controlar os limites da matriz.
*/
#include <stdio.h>
#include <stdlib.h>
#define L 30
#define C 2

void menu(float student[L][C]);
int gradeOp1(float student[L][C], int cont);
void listGrade(float student[L][C], int cont);
void highestGrade(float student[L][C], int cont);

int cont = 0;
char opCh;

int main(){
    float student[L][C];

    menu(student);

    return 0;
}

void menu(float student[L][C]){
    int op, ind = 0, j = 0, i = 0, cont = 0;

    do{
        printf("\nControle de Notas\n");
        printf("==================\n");
        printf("<1> - Adicionar notas de um aluno\n");
        printf("<2> - Listar todas as notas e medias\n");
        printf("<3> - Listar a maior nota na prova 1 e na prova 2\n");
        printf("<4> - Sair\n");
        printf("==================\n");
        printf("Qual opcao escolhida? ");
        scanf("%d", &op);
        printf("\n");

        switch(op){
            case 1:

                gradeOp1(student, cont);

                do{
                    cont ++;
                    printf("\nDeseja continuar (s / n)?: ");
                    opCh = getche();
                    printf("\n");

                    if(opCh == 's' || opCh == 'S'){
                        gradeOp1(student, cont);
                    } else {
                        printf("\n\n");
                        break;
                    }
                }while(opCh != 'n' || opCh != 'N');
                break;
            case 2:
                listGrade(student, cont);
                break;
            case 3:
                highestGrade(student, cont);
                break;
            case 4:
                exit(0);
        }
    }while(op != 4);
}

int gradeOp1(float student[L][C], int cont){
    int j, i;
    char op;
    if(cont < L){
        for(i = cont; i < L; i++){
            printf("\nPara o ALUNO %d, informe:\n", i+1);
            for(j = 0; j < C; j++){
                printf("NOTA %d: ", j+1);
                scanf("%f", &student[i][j]);
            }
            return 1;
        }
    } else {
        printf("\n\nLimite MAXIMO de alunos atingido!\n\n");
        return 0;
    }
}

void listGrade(float student[L][C], int cont){
    int i, j;

    if(cont == 0){
        printf("\nNenhum cadastro encontrado!\nPressione alguma tecla para continuar\n");
        opCh = getch();
    } else {
        for(i = 0; i < cont; i++){
            printf("\nALUNO %d \n", i+1);
            for(j = 0; j < C; j++){
                printf("NOTA %d: %.2f \n", j+1, student[i][j]);
            }
            printf("MEDIA: %.2f\n", (student[i][j-2] + student[i][j-1]) / 2.0);
        }
        printf("\nDigite alguma tecla para continuar");
        opCh = getch();
        printf("\n");
    }
}

void highestGrade(float student[L][C], int cont){
    int i, j;
    float high1, high2;

    high1 = student[0][0];
    high2 = student[0][1];

    if(cont == 0){
        printf("\nNenhum cadastro encontrado!\nPressione alguma tecla para continuar\n");
        opCh = getch();
    } else {
        for(i = 0; i < cont; i++){
            for(j = 0; j < C; j++){
                if(student[i][0] > high1){
                    high1 = student[i][0];
                } else
                    if(student[i][1] > high2){
                        high2 = student[i][1];
                    }
            }
        }
        printf("\nA maior nota da PROVA 1: %.2f\n", high1);
        printf("\nA maior nota da PROVA 2: %.2f\n", high2);
        printf("\nDigite alguma tecla para continuar");
        opCh = getch();
        printf("\n");
    }
}
