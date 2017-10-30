#include <stdio.h>
#include <stdlib.h>

typedef struct poke{
    float hp, spd, atk, def;
    char name[50];
}poke;

int menu(int *op);
void addPokemon(int cont, int cad, poke *deck);
void listarPokemon(poke *deck, int cont);

int main(){
    int op, cont = 0, cad;
    poke *deck = NULL;

    deck = (poke*) calloc(3, sizeof(poke));
    cad = 3;
    while (menu(&op) != 5){
        switch(op){
            case 1:
                if(cont < cad){
                    addPokemon(cont, cad, deck);
                    cont = cont + 3;
                } else {
                    printf("\nESPACO INSUFICIENTE NA MEMORIA!\nUTILIZE A OPCAO 3\n");
                    getch();
                }
                break;
            case 2:
                free(deck);
                deck = (poke *) calloc(3, sizeof(poke));
                printf("\nMEMORIA RESETADA COM SUCESSO!\n");
                cont = 0;
                cad = 3;
                getch();
                break;
            case 3:
                cad = cad + 3;
                deck = (poke *) realloc(deck, cad * sizeof(poke));
                if(deck == NULL){
                    printf("\nERRO NA REALOCACAO\n");
                    exit(1);
                } else {
                    printf("\nESPACO REALOCADO COM SUCESSO!\n");
                }
                getch();
                break;
            case 4:
                listarPokemon(deck, cont);
                getch();
                break;
            case 5:
                free(deck);
                break;
        }

    }
    return 0;
}

int menu(int *op){
    system("cls");
    do{
        printf("[1] - Adicionar Pokemon\n");
        printf("[2] - Remover Todos Pokemons\n");
        printf("[3] - Alocar Mais 3 espacos\n");
        printf("[4] - Listar Pokemons\n");
        printf("[5] - Liberar memoria e sair\n");
        scanf("%d", &*op);
        system("cls");
    }while (*op < 1 || *op > 5);

    return *op;
}

void addPokemon(int cont, int cad, poke *deck){
    int i;

    for(i = cont; i < cad; i++ ){
        fflush(stdin);
        printf("Registro no %d\n", i + 1);
        printf("Informe o nome do Pokemon: ");
        gets(deck[i].name);
        printf("Informe seu HP: ");
        scanf("%f", &deck[i].hp);
        printf("Informe seu Ataque: ");
        scanf("%f", &deck[i].atk);
        printf("Informe sua Defesa: ");
        scanf("%f", &deck[i].def);
        printf("Informe sua Velocidade: ");
        scanf("%f", &deck[i].spd);
        system("cls");
    }
}

void listarPokemon(poke *deck, int cont){
    int i;

    for(i = 0; i < cont; i++){
        printf("Registro no %d\n", i + 1);
        printf("Nome: %s\n", deck[i].name);
        printf("HP: %.2f\n", deck[i].hp);
        printf("Ataque: %.2f\n", deck[i].atk);
        printf("Defesa: %.2f\n", deck[i].def);
        printf("Velocidade: %.2f\n", deck[i].spd);
        printf("-----------------------------------\n");
    }
}
