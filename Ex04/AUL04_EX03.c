#include <stdio.h>

typedef struct MovieNetflix{
    char name[50];
    char gen[12];
    int duration;
    int likes;
}Netflix;

void readData(Netflix movie[]);
void printData(Netflix movie[]);

int main() {
    Netflix movie[15];
    readData(movie);
    printData(movie);

    return 0;
}

void readData(Netflix movie[]){
    int i = 0;
    for(i = 0; i < 15; i++){
        printf("Digite o nome do %do filme: ", i+1);
        gets(movie[i].name);
        printf("Informe o genero: ");
        gets(movie[i].gen);
        printf("Informe a duracao em (MIN): ");
        scanf("%d", &movie[i].duration);
        printf("Digite quantas curtidas: ");
        scanf("%d", &movie[i].likes);
        printf("\n");
        fflush(stdin);
    }
}

void printData(Netflix movie[]){
    int i = 0;
    for (i = 0; i < 15; i++){
        printf("\n=====================================\n");
        printf("%s \n%s \n%d \n%d \n", movie[i].name, movie[i].gen, movie[i].duration, movie[i].likes);
        printf("\n=====================================\n");
    }

}
