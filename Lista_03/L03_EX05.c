/* CABEÇALHO DO EXERCÍCIO
Nome: Julio Cesario de Paiva Leão
RA: 1916033
Turma: Engenharia de Software - ES21

5. Faça​ ​um​ ​programa​ ​que​ ​contenha​ ​uma​ ​função​ ​​recursiva​ ​para​ ​calcular​ ​e​ ​retornar​ ​o
resultado​ ​da​ ​seguinte​ ​série:
..
1
(n) + (n−21) + (n−32) + (n−43) + .5
N ​​ ​é​ ​um​ ​valor​ ​inteiro​ ​maior​ ​ou​ ​igual​ ​a​ ​1​ ​digitado​ ​pelo​ ​usuário.​ ​A​ ​série​ ​deve​ ​ser
calculada​ ​até​ ​que​ ​o​ ​denominador​ ​seja​ ​igual​ ​a​ ​1.​ ​O​ ​valor​ ​de​ ​N​ ​deverá​ ​ser​ ​lido​ ​com​ ​o
usuário​ ​e​ ​armazenado​ ​numa​ ​variável​ ​global.​ ​Dica,​ ​o​ ​parâmetro​ ​da​ ​função​ ​pode​ ​ser
o​ ​valor​ ​que​ ​está​ ​sendo​ ​diminuído​ ​do​ ​denominador.
*/

#include <stdio.h>

float soma(int n, float i);

int n;

int main(){
    float result, i = 1;
    do{
        printf("Digite um numero inteiro acima >= 1: ");
        scanf("%d", &n);
    } while (n < 1);
    result = soma(n, i);
    printf("\nO resultado e de %f\n", result);
    return 0;
}

float soma(int n, float i){
    float p;
    if(n == 1){
        return (i / n);
    } else {
        p = (i / n) + soma(n - 1, i + 1);
    }
     return p;
}
