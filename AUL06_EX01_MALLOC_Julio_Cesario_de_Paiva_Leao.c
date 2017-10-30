#include <stdio.h>
#include <stdlib.h>

typedef struct youtube{
    char channel_name[50];
    int views;
    int subscribers;
}youtube;

int menu();
void op1(youtube *pontInt, int i);
void op2(youtube *pontInt, int cont);

int main(){
    int quant, op, i = 0, j, cont = 0;
    youtube * pontInt;

    printf("Informe a quantidade de cadastros a ser realizado: ");
    scanf("%d", &quant);

    if (quant <= 0){
        printf("\a\nErro!\n");
        return -1;
    }

    pontInt = (youtube*) malloc(quant * sizeof(youtube));

    if(pontInt == NULL){
        printf("\a\nErro na alocacao da memoria!\n\n");
        return -2;
    }

    printf("\nSucesso na alocacao!\n\n");
    do{
        op = menu();

        switch (op){
            case 1:
                if(i == quant){
                    printf("\nEspaco insuficiente!\n\n");
                    getch();
                } else {
                    op1(pontInt, i);
                    cont++;
                    i++;
                }
                break;
            case 2:
                op2(pontInt, cont);
                break;
            case 3:
                free(pontInt);
                printf("\nMemoria liberada e processo encerrado!\n");
                exit(1);
                break;
            default:
                break;
        }
    } while (op != 3);
    return 0;
}

int menu(){
    int op;
    do{
        system("cls");
        printf("[1] Inserir um novo Youtuber\n");
        printf("[2] Listar os Youtubers cadastrados\n");
        printf("[3] Liberar memoria e sair\n");
        scanf("%d", &op);
        system("cls");
    } while (op < 1 || op > 3);
    return op;
}

void op1(youtube *pontInt, int i){
    fflush(stdin);
    printf("Digite o nome do youtuber: ");
    gets(pontInt[i].channel_name);
    printf("Digite a quantidade de views: ");
    scanf("%d", &pontInt[i].views);
    printf("Informe a quantidade de Inscritos: ");
    scanf("%d", &pontInt[i].subscribers);
}

void op2(youtube *pontInt, int cont){
    int j;
    for (j = 0; j < cont; j++){
        printf("Nome: %s\n", pontInt[j].channel_name);
        printf("Views: %d\n", pontInt[j].views);
        printf("Inscritos: %d\n", pontInt[j].subscribers);
        printf("\n");
    }
    getch();
}
