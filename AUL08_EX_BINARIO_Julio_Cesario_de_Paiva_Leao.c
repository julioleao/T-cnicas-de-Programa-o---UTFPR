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
void backup(youtube *youtubers);
void contar(youtube *youtubers);
void restoreBak();
void busca(youtube *youtubers);
void limpar();

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
                break;
            case 3:
                busca(youtubers);
                break;
            case 4:
                copyFile(youtubers);
                break;
            case 5:
                contar(youtubers);
                break;
            case 6:
                limpar();
                break;
            case 7:
                backup(youtubers);
                break;
            case 8:
                restoreBak();
                break;
            case 9:
                free(youtubers);
                printf("\n\tProcesso encerrado!\n");
                exit(1);
                break;
            default:
                break;
        }
    } while (op != 9);

    return 0;
}

int menu(){
    int op;
    do{
        system("cls");
        printf("\n\t[ 1 ] - Inserir um novo Youtuber\n");
        printf("\t[ 2 ] - Listar os Youtubers\n");
        printf("\t[ 3 ] - Buscar um registro\n");
        printf("\t[ 4 ] - Excluir um registro\n");
        printf("\t[ 5 ] - Quantidade de registros cadastrados\n");
        printf("\t[ 6 ] - Limpar todo o arquivo\n");
        printf("\t[ 7 ] - Fazer backup em um arquivo temporario\n");
        printf("\t[ 8 ] - Restaurar backup feito\n");
        printf("\t[ 9 ] - Sair\n");
        scanf("%d", &op);
        system("cls");
    } while (op < 1 || op > 9);
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
        printf("\n\tErro %d - %s\n", errno, strerror(errno));
        return 0;
    }
    return file;
}

void closeFile(FILE *file){
    fclose(file);
}

void gravarFile(youtube *youtubers){
    FILE *file;
    file = openFile("youtubers.bin", 'a');
    fwrite (youtubers, sizeof(youtube), 1, file);
    closeFile(file);
}

void listarFile(youtube *youtubers){
    FILE *file;
    long tam;
    file = openFile("youtubers.bin", 'r');
    fseek(file, 0, SEEK_END);
    tam = ftell(file);
    rewind(file);
    if(tam == 0){
        printf("\n\t Arquivo vazio!\n");
    } else {
        while(fread(youtubers, sizeof(youtube), 1, file) == 1){
            printf("Nome: %s \nViews: %d \nInscritos: %d \n\n", youtubers->channel_name, youtubers->views, youtubers->subscribers);
        }
    }
    while(fread(youtubers, sizeof(youtube), 1, file) == 1){
        printf("Nome: %s \nViews: %d \nInscritos: %d \n\n", youtubers->channel_name, youtubers->views, youtubers->subscribers);
    }
    closeFile(file);
    getch();
}

void copyFile(youtube *youtubers){
    char name[100];
    int tam;
    FILE *file1, *file2;
    file1 = openFile("youtubers.bin", 'r');
    file2 = openFile("file_bak.bin", 'w');
    fseek(file1, 0, SEEK_END);
    tam = ftell(file1);
    rewind(file1);

    if(tam == 0){
        printf("\n\t Arquivo vazio!\n");
    } else {
        fflush(stdin);
        printf("Digite o nome do canal: ");
        gets(name);
        while(fread(youtubers, sizeof(youtube), 1, file1) == 1){
            if(strcmp(name,youtubers->channel_name) != 0){
                fwrite (youtubers, sizeof(youtube), 1, file2);
            } else {
                printf("\n\tArquivo encontrado e excluido!\n");
            }
        }
    }

    closeFile(file2);
    closeFile(file1);
    remove("youtubers.bin");
    rename("file_bak.bin", "youtubers.bin");
    getch();
}

void backup(youtube *youtubers){
    FILE *file1, *file2;

    file1 = openFile("youtubers.bin", 'r');
    file2 = openFile("file_bak.bin", 'w');

    while(fread(youtubers, sizeof(youtube), 1, file1) == 1){
        fwrite (youtubers, sizeof(youtube), 1, file2);
    }
    printf("\n\tBackup criado com Sucesso!\n");
    closeFile(file2);
    closeFile(file1);
    getch();
}

void restoreBak(){
    remove("youtubers.bin");
    rename("file_bak.bin", "youtubers.bin");
    printf("\n\tBACKUP RESTAURADO COM SUCESSO!\n");
    getch();
}

void contar(youtube *youtubers){
    int cont = 0;
    long tam;

    FILE *file;
    file = openFile("youtubers.bin", 'r');
    fseek(file, 0, SEEK_END);
    tam = ftell(file);
    rewind(file);
    while(fread(youtubers, sizeof(youtube), 1, file) == 1){
        cont ++;
    }
    printf("\n\tHa um total de %d registros\n\te o arquivo possui %ld bytes.\n", cont, tam);
    closeFile(file);
    getch();
}

void busca(youtube *youtubers){
    char name[100];
    long tam;
    FILE *file1;
    file1 = openFile("youtubers.bin", 'r');
    fseek(file1, 0, SEEK_END);
    tam = ftell(file1);
    rewind(file1);

    if(tam == 0){
        printf("\n\t Arquivo vazio!\n");
    } else {
        fflush(stdin);
        printf("Digite o nome do canal: ");
        gets(name);
        system("cls");
        while(fread(youtubers, sizeof(youtube), 1, file1) == 1){
            if(strcmp(name,youtubers->channel_name) == 0){
                printf("Nome: %s \nViews: %d \nInscritos: %d \n\n", youtubers->channel_name, youtubers->views, youtubers->subscribers);
            }
        }
    }
    closeFile(file1);
    getch();
}

void limpar(){
    FILE *file;
    file = openFile("youtubers.bin", 'w');
    printf("\n\tArquivo limpado com sucesso!\n");
    getch();
}
