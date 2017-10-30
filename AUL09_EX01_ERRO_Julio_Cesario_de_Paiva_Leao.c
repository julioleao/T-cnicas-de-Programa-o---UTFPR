#include <stdio.h>
#include <stdlib.h>

typedef struct youtube{
    char channel_name[80];
    int views;
    int subscribers;
}youtube;

int menu();
void op1(youtube *youtubers);
FILE* openFile(char caminho[30], char modo);
void closeFile(FILE *file);
void gravarFile(youtube *youtubers);
void listarFile(youtube *youtubers);

int main(){
    FILE *file;
    int op, i = 0;
    youtube *youtubers;

    if(youtubers == NULL){
        printf("\a\nErro na alocacao da memoria!\n\n");
        exit(0);
    }

    do{
        op = menu();

        switch (op){
            case 1:
                op1(youtubers);
                i++;
                break;
            case 2:
                listarFile(youtubers);
                getch();
                break;
            case 3:
                printf("\nProcesso Encerrado!\n");
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
        printf("[3] Sair\n");
        scanf("%d", &op);
        system("cls");
    } while (op < 1 || op > 3);
    return op;
}

void op1(youtube *youtubers){
    fflush(stdin);
    printf("Digite o nome do youtuber: ");
    gets(youtubers->channel_name);
    printf("Digite a quantidade de views: ");
    scanf("%d", &youtubers->views);
    printf("Informe a quantidade de Inscritos: ");
    scanf("%d", &youtubers->subscribers);
    gravarFile(youtubers);
}

FILE* openFile(char caminho[30], char modo){
    FILE *file;
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
        printf("Erro na abertura do arquivo!\n");
        exit(0);
    }
    return file;
}

void closeFile(FILE *file){
    fclose(file);
}

void gravarFile(youtube *youtubers){
    FILE *file;
    file = openFile("youtubers.txt", 'a');
    fprintf(file, "%s %d %d\n", youtubers->channel_name, youtubers->views, youtubers->subscribers);
    closeFile(file);
}

void listarFile(youtube *youtubers){
    FILE *file;
    file = openFile("youtubers.txt", 'r');
    while(!feof(file)){
        fscanf(file, "%s %d %d ", youtubers->channel_name, &youtubers->views, &youtubers->subscribers);
        printf("Nome: %s\nViews: %d \nInscritos: %d \n\n", youtubers->channel_name, youtubers->views, youtubers->subscribers);
    }
    closeFile(file);
}
