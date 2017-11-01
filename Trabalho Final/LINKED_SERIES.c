#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif




int main(){


    switch(menu()){
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
        case 61:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 0:
            printf("\n\t\aATE MAIS JOVEM PADAWAN!\n");
            break;
    }

    return 0;
}

int menu(){
    int option;

    do{
        system(CLEAR);
        printf("\t+-------------------------------------------------------------+\n");
        printf("\t|\t\t\t\t\t\t\t      |\n");
        printf("\t| Ola, vem-vindo ao sistema de gerencia de series e filmes!   |\n");
        printf("\t|\t\tO que voce deseja fazer?\t\t      |\n");
        printf("\t|\t\t\t\t\t\t\t      |\n");
        printf("\t| [ 1 ] - Inserir um item manualmente\t\t\t      |\n");
        printf("\t| [ 2 ] - Carregar um arquivo com os meus itens\t\t      |\n");
        printf("\t| [ 3 ] - Listar os itens de forma iterativa\t\t      |\n");
        printf("\t| [ 4 ] - Listar as itens de forma recursiva\t\t      |\n");
        printf("\t| [ 5 ] - Listar as itens de forma recursiva invertida\t      |\n");
        printf("\t| [ 6 ] - Limpar a lista em memoria\t\t\t      |\n");
        printf("\t| [ 7 ] - Salvar lista em arquivo texto\t\t\t      |\n");
        printf("\t| [ 8 ] - Contar items e memoria\t\t\t      |\n");
        printf("\t| [ 9 ] - Procurar item por data\t\t\t      |\n");
        printf("\t| [ 0 ] - Sair\t\t\t\t\t\t      |\n");
        printf("\t+-------------------------------------------------------------+\n");
        scanf("%d", &option);
        if(option > 9 || option < 0){
            system(CLEAR);
            printf("\n\t\aOPCAO INVALIDA!\n\tTENTE DE NOVO!\n");
            getch();
        }
        system(CLEAR);
    } while(option > 9 || option < 0);

    return option;
}
