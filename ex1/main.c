#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ex1.h"




int main ()
{
    char ans[100] = "Nao foi possivel formar o valor alvo";// string para armazenar a resposta
    int list[6]; //vetor que armazena a lista atual
    int value; // valor desejado
    int count = 0;
    char ls[100];

    fgets(ls,sizeof(ls), stdin);  // lê a linha com os números

     // remove o '\n' do final, se houver
    ls[strcspn(ls,"\n")] = '\0';

    char *token = strtok(ls, ",");
    while (token != NULL && count < 100) {
        char *a1;
        int aux = strtol(token,&a1, 10); // converte para int e armazena
        list[count++] = aux;
        token = strtok(NULL, ",");      // próximo token
    }
    scanf("%d", &value);


    char string_vector[6][100];
    int combinations[100][2]; // cria o vetor que armazena o total de combinações
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
