#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"


int main( int argc, char** argv)
{

  char *PALAVRA_ORIGINAL_1, *PALAVRA_ORIGINAL_2;

      if(argc > 3){
        printf("Erro: Mais de dois argumentos passados, por favor rode o programa da seguinte maneira : \n bash run.sh <palavra1> <palavra2>\n");
        printf("Ou rode o programa sem argumentos para ver os casos de teste padrão:\n bash run.sh\n");
        return 1;
    }

    if (argc < 3){


//CASO PADRÃO
        PALAVRA_ORIGINAL_1 = malloc(15 * sizeof(char));
        PALAVRA_ORIGINAL_2 = malloc(15 * sizeof(char));
//CASO PADRÃO PEDRO E PODER
        strcpy(PALAVRA_ORIGINAL_1,"Pedro");
        strcpy(PALAVRA_ORIGINAL_2,"Poder");
        TESTEPALAVRAS(PALAVRA_ORIGINAL_1,PALAVRA_ORIGINAL_2);
        printf("\n");
//CASO PADRÃO BRASIL E BRASILEIRO
        strcpy(PALAVRA_ORIGINAL_1,"Brasil");
        strcpy(PALAVRA_ORIGINAL_2,"Brasileiro");
        TESTEPALAVRAS(PALAVRA_ORIGINAL_1,PALAVRA_ORIGINAL_2);

    }
    if (argc == 3){
        PALAVRA_ORIGINAL_1 = malloc(strlen(argv[1])+5);
        PALAVRA_ORIGINAL_2 = malloc(strlen(argv[2])+5);

        strcpy(PALAVRA_ORIGINAL_1 ,argv[1]);
        strcpy(PALAVRA_ORIGINAL_2 ,argv[2]);
        TESTEPALAVRAS(PALAVRA_ORIGINAL_1,PALAVRA_ORIGINAL_2);
    }
//liberar todas as memórias alocadas no main
    free(PALAVRA_ORIGINAL_1);
    free(PALAVRA_ORIGINAL_2);
    PALAVRA_ORIGINAL_1 = NULL;
    PALAVRA_ORIGINAL_2 = NULL;
    
    
   printf("\n\n");

return 0;
}

