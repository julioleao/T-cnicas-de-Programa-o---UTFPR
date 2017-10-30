#include <stdio.h>

int main(){
    char name1[50], name2[50];
    int age1, age2;

    printf("Informe o nome da primeira pessoa: ");
    gets(name1);
    printf("Digite sua idade: ");
    scanf("%d", &age1);
    fflush (stdin);
    printf("Informe o nome da segunda pessoa: ");
    gets(name2);
    printf("Digite sua idade: ");
    scanf("%d", &age2);
    printf("\nA pessoa mais jovem e ");
    if (age1 < age2){
        printf("%s\n", name1);
    } else {
        printf("%s\n", name2);
    }
    return 0;
}
