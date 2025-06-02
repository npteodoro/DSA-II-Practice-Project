#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ex1.h"




int main (int argc, char *argv[])
{
    char ans[100] = "Nao foi possivel formar o valor alvo";// string para armazenar a resposta
    int list[6]; //vetor que armazena a lista atual
    int count = 0;
    char *ls = argv[1]; // cont�m a linha com os n�meros
    char *a;
    int value = strtol(argv[2],&a,10); // valor desejado

    ls[strcspn(ls,"\n")] = '\0';     // remove o '\n' do final, se houver

    char *token = strtok(ls, ",");
    while (token != NULL && count < 100) {
        char *a1;
        int aux = strtol(token,&a1, 10); // converte para int e armazena
        list[count++] = aux;
        token = strtok(NULL, ",");      // pr�ximo token
    }



    char string_vector[6][100];
    int combinations[100][2]; // cria o vetor que armazena o total de combina��es
    for(int i = 0; i < count; i++)
    {
        sprintf(string_vector[i], "%d", list[i]); // cria o string que representa o vetor atual
    }

    int tcalls = 0;
    find_expression(count - 1,list,0,value,string_vector,ans,0,combinations, &tcalls);
    printf("%s\n", ans);
    printf("%d\n", tcalls);

    return 0;
}
