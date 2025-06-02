#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"




char* FORMATSTRING(const char* palavra) // função para as palavras ficarem em maiscula
{
    int i; //DECLARAÇÃO DE VARIAVEL AUXILIAR

    char* copia = malloc((strlen(palavra) + 1) * sizeof(char)); // Aloca espaço suficiente para a cópia da palavra (inclui terminador nulo)
    if (copia != NULL) {
        strcpy(copia, palavra); //copia a palavra
    }
    for (i=0;i< strlen(copia);i++) //checar letra por letra
    {
        if (copia[i] > 96 && copia[i] < 123 ) copia[i] = copia[i] - 32; //transformar minuscula em maiscula
    }
    return copia; //retorna a palavra com letras maisculas
}


char* INSERTIONSORT(const char* palavra)
{
    int i,j,posicao;
    char letra;

     char* copia = malloc((strlen(palavra) + 5) * sizeof(char)); // Aloca espaço suficiente para a copia da palavra
    if (copia != NULL) strcpy(copia, palavra); //copia a palavra

   for(i=0;i<strlen(copia);i++) //para todas as letras na palavra busca o local e insere
   {
       letra = copia[i]; //letra a ser buscada
    if (letra<copia[i-1]){
       posicao = BINARYSEARCH(copia,0,i-1,letra); //retorna a posicao em que deve ser inserida
       for (j=i;j > posicao;j--) //troca a letra pela anterior ate chegar na posicao para liberar o espaco necessario
       {
           copia [j] = copia[j-1];
       }
   copia[posicao] = letra;

   }
   }
    return copia;
}

 int BINARYSEARCH(char *palavra, int left, int right, char letra) //funcao para fazer busca binária em um vetor
{ int mid;
    while(left < right)
    {
        mid = (left + right)/2; //encontra o meio da area de busca
        if (palavra[mid] > letra) right = mid; // se a letra vem antes do meio da busca entao busca na primeira metade
        else left = mid + 1; // se for depois busca na segunda metade
    }
    return left;

}


void TESTEPALAVRAS (const char* PALAVRA_ORIGINAL_1, const char* PALAVRA_ORIGINAL_2)
{
    char *PALAVRA_PADRONIZADA_1,*PALAVRA_PADRONIZADA_2,*PALAVRA_ORDENADA_1,*PALAVRA_ORDENADA_2;



    printf("Palavra 1: %s - Palavra 2: %s - Anagrama? ", PALAVRA_ORIGINAL_1,PALAVRA_ORIGINAL_2);

    if(strlen(PALAVRA_ORIGINAL_1) != strlen(PALAVRA_ORIGINAL_2))//se nao tiver o mesmo tamanho nao eh anagrama, não precisa ordenar
    {
        printf ("não");
        return;
    }


//PADRONIZAR PALAVRA1
    PALAVRA_PADRONIZADA_1 = FORMATSTRING(PALAVRA_ORIGINAL_1) ;

//ORDENO PALAVRA1
    PALAVRA_ORDENADA_1 =  INSERTIONSORT(PALAVRA_PADRONIZADA_1);

//PADRONIZAR PALAVRA2
    PALAVRA_PADRONIZADA_2 = FORMATSTRING(PALAVRA_ORIGINAL_2);


//ORDENO PALAVRA2
    PALAVRA_ORDENADA_2 =  INSERTIONSORT(PALAVRA_PADRONIZADA_2);


//COMPARO PALAVRA 1 COM PALAVRA 2

    if (strcmp(PALAVRA_ORDENADA_1,PALAVRA_ORDENADA_2)) printf("não"); //se forem diferentes, não são anagramas
    else printf("sim"); // se as palavras padronizadas e ordenadas forem iguais são anagramas

}
