/*fa�a um programa que use uma fun��o que receba um caractere como par�metro e retorne 1 (um) caso
seja uma vogal e zero caso n�o seja;*/

#include <stdio.h>

int alphabet(char character);
int main(){
    char character;

    printf("Digite um caractere: ");
    scanf("%c", &character);
    printf("%d\n", alphabet(character));
    return 0;
}

int alphabet(char character){
    char vowel[] = "aeiouAEIOU";
    int i;

    for (i = 0; vowel[i] != '\0'; i++){
        if (character == vowel[i]){
            return 1;
        }
    }
    return 0;
}
