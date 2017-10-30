#include <stdio.h>
#include <stdlib.h>
void fibonacci (int qtd, int *pos);

int main(){
    int *pos = NULL, *size;
    int qtd, qtd2, i;

    printf("Informe o n-esimo termo da um sequencia fibonacci: ");
    scanf("%d", &qtd);

    pos = (int *) malloc (qtd * sizeof(int));

    if(pos == 0){
        printf("\nErro na alocacao!\n");
        exit(-1);
    }

    fibonacci(qtd, pos);

    printf("Informe OUTRO n-esimo termo da um sequencia fibonacci: ");
    scanf("%d", &qtd2);

    if(qtd2 < qtd){
        for(i = 0; i <qtd2; i++){
            printf("%d ",pos[i]);
        }
        printf("\n\n");
    } else {
        pos = (int *) realloc(pos, qtd2 * sizeof(int));
        fibonacci(qtd2, pos);
    }

    return 0;
}

void fibonacci (int qtd, int *pos){
    int primeiro = 0, segundo = 1, i;

    for (i = 0 ; i < qtd ; i++){
      if (i <= 1){
        pos[i] = i;
      } else {
         pos[i] = primeiro + segundo;
         primeiro = segundo;
         segundo = pos[i];
      }
      printf("%d ", pos[i]);
   }
    printf("\n\n");
}

