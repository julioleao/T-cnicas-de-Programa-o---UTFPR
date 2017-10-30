#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct youtube{
    char channel_name[50];
    int views;
    int subscribers;
}youtube;

int menu();
void op1(youtube *youtubers);
FILE* openFile(char caminho[30], char modo);
void closeFile(FILE *file);
void gravarFile(youtube *youtubers);
void listarFile(youtube *youtubers);
void copyFile(youtube *youtubers);

int main(){
    FILE *file;
    int quant, op, i = 1;
    youtube *youtubers;

    youtubers = (youtube*) malloc(i*sizeof(youtube));

    do{
        op = menu();

        switch (op){
            case 1:

                op1(youtubers);
                i++;
                youtubers = (youtube*) realloc(youtubers, i*sizeof(youtube));
                break;
            case 2:
                listarFile(youtubers);
                getch();
                break;
            case 3:
                copyFile(youtubers);
                break;
            case 4:
                free(youtubers);
                printf("\a\n\tProcesso encerrado!\n");
                exit(1);
                break;
            default:
                break;
        }
    } while (op != 4);

    return 0;
}

int menu(){
    int op;
    do{
        system("cls");
        printf("[1] Inserir um novo Youtuber\n");
        printf("[2] Listar os Youtubers cadastrados\n");
        printf("[3] Buscar e excluir registro\n");
        printf("[4] Sair\n");
        scanf("%d", &op);
        system("cls");
    } while (op < 1 || op > 4);
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
        printf("\a\n\tErro %d - %s\n", errno, strerror(errno));
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
        fscanf(file, "%s %d %d\n", youtubers->channel_name, &youtubers->views, &youtubers->subscribers);
        printf("Nome: %s \nViews: %d \nInscritos: %d \n\n", youtubers->channel_name, youtubers->views, youtubers->subscribers);
    }
    closeFile(file);
}

void copyFile(youtube *youtubers){
    char name[100];
    FILE *file1, *file2;
    fflush(stdin);
    printf("Digite o nome do canal: ");
    gets(name);
    file1 = openFile("youtubers.txt", 'r');
    file2 = openFile("file_bak.txt", 'w');

    while(!feof(file1)){
        fscanf(file1, "%s %d %d\n", youtubers->channel_name, &youtubers->views, &youtubers->subscribers);
        if(strcmp(name,youtubers->channel_name) != 0){
            fprintf(file2, "%s %d %d\n", youtubers->channel_name, youtubers->views, youtubers->subscribers);
        } else {
            printf("\n\t\aArquivo encontrado e excluido!\n");
            getch();
        }
    }
    closeFile(file2);
    closeFile(file1);
    remove("youtubers.txt");
    rename("file_bak.txt", "youtubers.txt");
}
