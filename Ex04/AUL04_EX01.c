#include <stdio.h>

typedef struct MovieNetflix{
    char name[50];
    char gen[12];
    int duration;
    int likes;
}Netflix;

int main() {
    Netflix movie;

    printf("Digite o nome do filme: ");
    gets(movie.name);
    printf("Informe o genero: ");
    gets(movie.gen);
    printf("Informe a duracao em (MIN): ");
    scanf("%d", &movie.duration);
    printf("Digite quantas curtidas: ");
    scanf("%d", &movie.likes);

    printf("\n=====================================\n");
    printf("%s \n%s \n%d \n%d \n", movie.name, movie.gen, movie.duration, movie.likes);
    printf("\n=====================================\n");

    return 0;
}
