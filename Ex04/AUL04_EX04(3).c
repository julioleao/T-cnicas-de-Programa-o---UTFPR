#include <stdio.h>
#define L 15

typedef struct Computers{
    char name[50];
    int memory;
    float cpu;
}Computers;

void readData(Computers pc[]);
void printData(Computers pc[]);

int main(){
    Computers pc[15];
    readData(pc);

    return 0;
}

void readData(Computers pc[]){
    int i;
    for(i = 0; i < L; i++){
        printf("Digite o nome do computador: ");
        gets(pc[i].name);
        printf("Digite a quantidade de memoria(GB): ");
        scanf("%d", &pc[i].memory);
        printf("Informe a CPU(GHz): ");
        scanf("%f", &pc[i].cpu);
        printf("\n");
        fflush(stdin);
    }
    printData(pc);
}

void printData(Computers pc[]){
    int i;

    for(i = 0; i < L; i++){
        printf("\n%s \n%d GB \n%.2f Ghz\n", pc[i].name, pc[i].memory, pc[i].cpu);
    }
}
