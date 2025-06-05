#include <stdio.h>       // Biblioteca padr�o para entrada e sa�da (ex: printf, scanf)
#include <stdlib.h>      // Biblioteca para aloca��o de mem�ria, convers�o de strings e outras utilidades (ex: malloc, free, atoi)
#include <string.h>      // Biblioteca para manipula��o de strings (ex: strlen, strcpy)
#include "Rainhas.h"     // Inclus�o do cabe�alho onde est� declarada a fun��o 'exec' e possivelmente outras auxiliares do problema das N rainhas

int main(int argc, char *argv[])
{
    // Aloca dinamicamente um vetor de 2 inteiros para armazenar os testes
    int *testes = (int *)malloc(2 * sizeof(int));

    // Verifica se o programa foi executado com menos de dois argumentos (ou seja, s� o nome do programa)
    if(argc < 2){
        // Caso nenhum argumento seja passado, define valores padr�o para os testes:
        // 4 rainhas (testes[0]) e 8 rainhas (testes[1])
        testes[0] = 4;
        testes[1] = 8;
    }
    else{
        // Caso um argumento tenha sido passado via linha de comando

        // Aloca dinamicamente espa�o para copiar a string do argumento (n�mero de rainhas)
        char *buffer = (char *)malloc(strlen(argv[1]) + 1);  // +1 para o caractere nulo '\0'

        // Copia o conte�do do argumento para o buffer
        strcpy(buffer, argv[1]);

        // Converte o conte�do do buffer (string) para inteiro e armazena em testes[0]
        testes[0] = atoi(buffer);

        // Define o segundo valor como 0 (nesse c�digo ele n�o � utilizado ativamente)
        testes[1] = 0;

        // Libera a mem�ria alocada para o buffer ap�s o uso
        free(buffer);
    }

    // Chama a fun��o que executa o algoritmo das N rainhas com base nos valores definidos em 'testes'
    exec(testes);

    // Libera a mem�ria alocada para o vetor 'testes'
    free(testes);

    // Retorna 0 indicando que o programa terminou com sucesso
    return 0;
}
