/*
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: ES21

TRABALHO - Simular um jogo de RPG, onde há a seleção de dois personagens através da classe (MAGE, ARCHER e DWARF).
Onde cada um terá os atributos (NOME, HP, STRENGHT, SPELL e CLASS) e entrarão num duelo composto por 3 Rounds.
O primeiro que tiver o HP menor ou igual a zero, encerra o round dando vitória ao outro personagem.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "character.h"

#define H 2

// ENUM de classe
typedef enum character{
    MAGE,
    ARCHER,
    DWARF
}character;

// Registro do herói
typedef struct hero{
    char name[50];
    int hp;
    int strenght;
    int spell;
    int bonus;
    char form[2][70];
    character clas;
}hero;

// Variaveis globais
hero heroes[H]; // Registro de heróis
int i = 0; // Indicie para as estruturas for

// Funções
void chooseYourClass();
void printHero();
void charForm1();
void charForm2();
void fightHeroes();
void damage(float *r1, float *r2);
void numRandon(float *r1, float *r2);
void statusRandom();
void bonuses();
int emptyName();
void damageTaken(float *r1, float *r2);
void delay(unsigned int mseconds);

// Função principal
int main(){

    // Função de escolha de personagens
    chooseYourClass();

    return 0;
}

// Função de escolha de personagens
void chooseYourClass(){
    int op, exit, l, j;
    for(i = 0; i < H; i++){
        do{
            printf("+-----------------------------------------------------------------------+\n");
            printf("|                .::ESCOLHA SUA CLASSE PARA O HEROI %d::.                |\n", i+1);
            printf("+-------------------+---------------------------+-----------------------+\n");
            printf("| MAGE    < 0 >     |      ARCHER    < 1 >      |       DWARF    < 2 >  |\n");
            printf("+-------------------+---------------------------+-----------------------+\n");
            scanf("%d", &heroes[i].clas); //Escolher classe
            fflush(stdin);
            system("cls");
        }while(heroes[i].clas < 0 || heroes[i].clas > 2);
        do{
            printf("\n\t\tInforme o nome do seu HEROI %d\n\n ", i+1);
            gets(heroes[i].name); // Nome do heroi

        } while(emptyName() != 1); // Função para verificar string vazia
        system("cls");

        //Atribuição de valores Randomicos (HP, STRENGHT, SPELL)
        statusRandom();

        // Atribuição de bonus
        bonuses();

    }
    fightHeroes(); //Função para iniciar luta
}

// Função para mostrar herói em forma de tabela
void printHero(){
    for(i = 0; i < H; i++){
        // Informações Mage
        if(heroes[i].clas == MAGE){
            printf("+-----------+---------------------------+\n");
            printf("|            .::HEROI %d::.              |\n", i+1);
            printf("+-----------+---------------------------+\n");
            printf("|   NAME    | %s\t\t\t|\n", heroes[i].name);
            printf("|    HP     | %2.d\t\t\t|\n", heroes[i].hp);
            printf("| STRENGHT  | %d\t\t\t|\n", heroes[i].strenght);
            printf("|  SPELL    | %d\t\t\t|\n", heroes[i].spell);
            printf("|  CLASS    | Mage\t\t\t|\n");
            printf("+-----------+---------------------------+\n");
            // Sprite mago
            mage();
            printf("\nLOADING...\n");
            delay(3000);
            system("cls");
        }else
            if(heroes[i].clas == ARCHER){
                // Informações Archer
                printf("+---------------------------------------+\n");
                printf("|            .::HEROI %d::.              |\n", i+1);
                printf("+-----------+---------------------------+\n");
                printf("|   NAME    | %s\t\t\t|\n", heroes[i].name);
                printf("|    HP     | %2.d\t\t\t|\n", heroes[i].hp);
                printf("| STRENGHT  | %d\t\t\t|\n", heroes[i].strenght);
                printf("|  SPELL    | %d\t\t\t|\n", heroes[i].spell);
                printf("|  CLASS    | Archer\t\t\t|\n");
                printf("+-----------+---------------------------+\n");
                // Sprite arqueiro
                archer();
                printf("\nLOADING...\n");
                delay(3000);
                system("cls");
            } else {
                // Informações Dwarf
                printf("+-----------+---------------------------+\n");
                printf("|            .::HEROI %d::.              |\n", i+1);
                printf("+-----------+---------------------------+\n");
                printf("|   NAME    | %s\t\t\t|\n", heroes[i].name);
                printf("|    HP     | %2.d\t\t\t|\n", heroes[i].hp);
                printf("| STRENGHT  | %d\t\t\t|\n", heroes[i].strenght);
                printf("|  SPELL    | %d\t\t\t|\n", heroes[i].spell);
                printf("|  CLASS    | Dwarf\t\t\t|\n");
                printf("+-----------+---------------------------+\n");
                // Sprite anão
                dwarf();
                printf("\nLOADING...\n");
                delay(3000);
                system("cls");
            }
        if(i == 0){
            vs();
            printf("\n\n\nLOADING...\n");
            delay(2000);
        }
        system("cls");
    }
    printf("\n");
}

// Função de batalha entre heróis
void fightHeroes(){
    float r1, r2;
    int hp1, hp2, hero0 = 0, hero1 = 0, j;
    char opCh;
    // Variavel para guardar o HP original dos heróis para renovar após cada Round
    hp1 = heroes[0].hp;
    hp2 = heroes[1].hp;
    printHero(); //Função para imprimir personagem
    for(j = 0; j < 3; j++){
        // Valores randomicos para
        numRandon(&r1, &r2);

        heroes[0].hp = hp1;
        heroes[1].hp = hp2;


        printf("\n\n\n\n\t\tROUND %d\n\n\n\n", j+1);
        printf("\nLOADING...\n");
        delay(2000);
        system("cls");
        // Efeito de ataque (HIT)
        hit();
        do{
            // Valores randomicos para
            numRandon(&r1, &r2);

            // Função de redução de HP
            damage(&r1, &r2);

            // Função de dano sofrido
            damageTaken(&r1, &r2);
        } while (heroes[0].hp > 0 && heroes[1].hp > 0);

        //Resultado parcial (após cada round)
        if(heroes[0].hp > heroes[1].hp){
            printf("+-----------------------------------------------+\n");
            printf("|\t\t.::HEROI %s::.\t\t|\n", heroes[0].name);
            printf("|\t\tVENCEU O ROUND %d\t\t|\n", j+1);
            printf("+-----------------------------------------------+\n");
            charForm1();
            hero0++;
        } else
            if(heroes[1].hp > heroes[0].hp){
                printf("+-----------------------------------------------+\n");
                printf("|\t\t.::HEROI %s::.\t\t|\n", heroes[1].name);
                printf("|\t\tVENCEU O ROUND %d\t\t|\n", j+1);
                printf("+-----------------------------------------------+\n");
                charForm2();
                hero1++;
            } else {
                printf("+-----------------------------------------------+\n");
                printf("|\t\tEMPATE NO ROUND %d\t\t|\n", j+1);
                printf("+-----------------------------------------------+\n");
                fflush(stdin);
            }
        fflush(stdin);
        printf("\n\nPRESSIONE ALGUMA TECLA PARA CONTINUAR!\n");
        getch();
        system("cls");
    }
    // Resultado Final (após os 3 rounds)
    if(hero0 > hero1){
        printf("+-----------------------------------------------+\n");
        printf("|\t\t.::HEROI %s::.\t\t|\n", heroes[0].name);
        printf("|\t\tO GRANDE CAMPEAO\t\t|\n");
        printf("+-----------------------------------------------+\n");
        charForm1();
    } else {
        printf("+-----------------------------------------------+\n");
        printf("|\t\t.::HEROI %s::.\t\t|\n", heroes[1].name);
        printf("|\t\tO GRANDE CAMPEAO\t\t|\n");
        printf("+-----------------------------------------------+\n");
        charForm2();
    }
    printf("\n\nDeseja criar outro personagem (s/n)? "); // Continuar o game
    opCh = getch();
    if(opCh == 's' || opCh == 'S'){
        system("cls");
        // Criar novos personagens
        chooseYourClass();

    } else {
        system("cls");
        // Encerrar o game
        gameOver();

    }
}

// Função para criar a forma do heroi
void charForm1(){
    if(heroes[0].clas == MAGE){
    // Mage
    mage();

    } else
        if(heroes[0].clas == ARCHER){
            // Archer
            archer();

        } else {
            // Dwarf
            dwarf();
        }
}

// Função para criar a forma do heroi 2
void charForm2(){
    if(heroes[1].clas == MAGE){
        // Mage
        mage();
    } else
        if(heroes[1].clas == ARCHER){
            // Archer
            archer();
        } else {
            // Dwarf
            dwarf();
        }
}

// Função de redução de HP
void damage(float *r1, float *r2){
    // Heroi 1 sofre o atk
    heroes[0].hp = heroes[0].hp - ((((heroes[1].strenght + heroes[1].spell) / 2) + heroes[1].bonus) * (*r2));
    // Heroi 2 sofre o atk
    heroes[1].hp = heroes[1].hp - ((((heroes[0].strenght + heroes[0].spell) / 2) + heroes[0].bonus) * (*r1));
}

// Função para atribuir um numero randomico à variavel r
void numRandon(float *r1, float *r2){
    srand( (unsigned)time(NULL) );
            *r1 = 10 + rand() % 21;
            *r2 = 10 + rand() % 21;
            // Convertendo de INT para Float
            *r1 = *r1 / 100;
            *r2 = *r2 / 100;

}

// Função para atribuir valores randomico ao Status de cada personagem
void statusRandom(){
        srand( (unsigned)time(NULL) );
        heroes[i].hp = rand() % 100; //Numero randomico de HP (0 - 100)
        heroes[i].spell = 50 + (rand() % 50); //Numero randomico de SPELL (50 - 100)
        heroes[i].strenght = 50 + (rand() % 50); //Numero randomico de STRENGHT (50 - 100)
}

// Função para atribuir bonus
void bonuses(){
    // Bonus para MAGE = 3
    if(heroes[i].clas == MAGE){
        heroes[i].bonus = 3;
    } else
        // Bonus para ARCHER = 2
        if(heroes[i].clas == ARCHER){
            heroes[i].bonus = 2;
        } else
            // Bonus para DWARF = 5
            if(heroes[i].clas == DWARF){
                heroes[i].bonus = 5;
            }
}

// Função para verificar string vazia
int emptyName(){
    int j, l;
    for(l = i; l <= i; l++){
        for(j = 0; heroes[l].name[j] != '\0'; j++){
            if(heroes[l].name[j] != '\0' && heroes[l].name[j] != ' '){
                return 1;
            }
        }
    }
     return 0;
}

// Função para dano recebido

void damageTaken(float *r1, float *r2){
    float dmg1 = 0, dmg2 = 0;
    // Heroi 1 sofre o atk
    dmg1 = ((((heroes[1].strenght + heroes[1].spell) / 2) + heroes[1].bonus) * (*r2));
    // Heroi 2 sofre o atk
    dmg2 = ((((heroes[0].strenght + heroes[0].spell) / 2) + heroes[0].bonus) * (*r1));
    printf("+---------------------------------------+\n");
    printf("| %s sofreu %.2f de dano\t\t|\n", heroes[0].name, dmg1);
    printf("| HP restante %d \t\t\t|\n", heroes[0].hp);
    printf("+---------------------------------------+\n");
    printf("| %s sofreu %.2f de dano\t\t|\n", heroes[1].name, dmg2);
    printf("| HP restante %d \t\t\t|\n", heroes[1].hp);
    printf("+---------------------------------------+\n");
    printf("\n/////////////////////////////////////////\n\n");
    delay(3000);
}

// Função para automatizar comandos em milisegundos
void delay(unsigned int mseconds){
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
