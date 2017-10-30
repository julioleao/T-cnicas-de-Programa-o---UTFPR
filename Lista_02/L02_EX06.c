/*Turma: ES21

EX06. Crie um programa que deverá receber como entrada um número de 1 a 12. Valide
para que apenas este intervalo seja aceito. O programa deverá ter 2 enums: Meses e
Estacoes. O primeiro deverá ser um enum com cada mês do ano: JANEIRO = 1,
FEVEREIRO, MARCO, ABRIL, MAIO, JUNHO, JULHO, AGOSTO, SETEMBRO,
OUTUBRO, NOVEMBRO, DEZEMBRO. O segundo deverá ter as estações do ano:
PRIMAVERA = 1, VERÃO, OUTONO, INVERNO. Crie ainda definições de tipo: Meses
→ tipoMes e Estacoes → tipoEstacap. O programa deverá utilizar o número
digitado para criar uma nova variável do tipo tipoMes, e passá-la para uma função
chamada validaEstacao que verifica qual mês foi passado e retorna outro enum
com a estação correspondente (tipoEstacao). Utilize a variável retornada pela
função validaEstacao na sua função main, para imprimir a estação utilizando o
comando switch. Considere: Primavera → de março a junho, Verão → de junho a
setembro, Outono → de setembro a dezembro, Inverno → de dezembro a março.
*/

#include <stdio.h>

typedef enum meses{
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO,
}tipoMes;

typedef enum estacoes{
    PRIMAVERA = 1,
    VERAO,
    OUTONO,
    INVERNO,
}tipoEstacao;

int validaEstacao(tipoMes num);

int main(){
    tipoMes num;
    do{
        printf("Digite um numero entre 1 e 12: ");
        scanf("%d", &num);
    }while(num < 1 || num > 12);
    validaEstacao(num);
    switch (validaEstacao(num)){
        case INVERNO:
            printf("\nEstacao INVERNO!\n");
            break;
        case PRIMAVERA:
            printf("\nEstacao PRIMAVERA!\n");
            break;
        case OUTONO:
            printf("\nEstacao OUTONO!\n");
            break;
        case VERAO:
            printf("\nEstacao VERAO!\n");
            break;
    }


    return 0;
}

int validaEstacao(tipoMes num){
    switch (num){
        case JANEIRO:
            return INVERNO;
            break;
        case FEVEREIRO:
            return INVERNO;
            break;
        case MARCO:
            return INVERNO;
            break;
        case ABRIL:
            return PRIMAVERA;
            break;
        case MAIO:
            return PRIMAVERA;
            break;
        case JUNHO :
            return PRIMAVERA;
            break;
        case JULHO:
            return OUTONO;
            break;
        case AGOSTO:
            return OUTONO;
            break;
        case SETEMBRO:
            return OUTONO;
            break;
        case OUTUBRO:
            return VERAO;
            break;
        case NOVEMBRO:
            return VERAO;
            break;
        case DEZEMBRO:
            return VERAO;
            break;
    }
}
