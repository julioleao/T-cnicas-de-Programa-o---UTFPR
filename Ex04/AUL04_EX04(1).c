#include <stdio.h>

typedef struct Computers{
    char name[50];
    int memory;
    int cpu;
}Computers;

int main(){
    Computers pc;

    printf("Digite o nome do computador: ");
    gets(pc.name);
    printf("Digite a quantidade de memoria(GB): ");
    scanf("%d", &pc.memory);
    printf("Informe a CPU(GHz): ");
    scanf("%d", &pc.cpu);
    printf("\n%s \n%d \n%d \n", pc.name, pc.memory, pc.cpu);

    return 0;
}
