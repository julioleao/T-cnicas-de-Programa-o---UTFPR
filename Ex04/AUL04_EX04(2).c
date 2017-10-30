#include <stdio.h>

typedef struct Computers{
    char name[50];
    int memory;
    int cpu;
}Computers;

int main(){
    Computers pc[15];
    int i;

    for(i = 0; i < 15; i++){
        printf("Digite o nome do computador: ");
        gets(pc[i].name);
        printf("Digite a quantidade de memoria(GB): ");
        scanf("%d", &pc[i].memory);
        printf("Informe a CPU(GHz): ");
        scanf("%d", &pc[i].cpu);
    }

    for(i = 0; i < 15; i++){
        printf("\n%s \n%d \n%d \n", pc[i].name, pc[i].memory, pc[i].cpu);
    }

    return 0;
}
