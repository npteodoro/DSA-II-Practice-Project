#include <stdio.h>       // Biblioteca padrão para entrada e saída (ex: printf, scanf)
#include <stdlib.h>      // Biblioteca para alocação de memória, conversão de strings e outras utilidades (ex: malloc, free, atoi)
#include <string.h>      // Biblioteca para manipulação de strings (ex: strlen, strcpy)
#include "Rainhas.h"     // Inclusão do cabeçalho onde está declarada a função 'exec' e possivelmente outras auxiliares do problema das N rainhas

int main(int argc, char *argv[])
{
    // Aloca dinamicamente um vetor de 2 inteiros para armazenar os testes
    int *testes = (int *)malloc(2 * sizeof(int));

    // Verifica se o programa foi executado com menos de dois argumentos (ou seja, só o nome do programa)
    if(argc < 2){
        // Caso nenhum argumento seja passado, define valores padrão para os testes:
        // 4 rainhas (testes[0]) e 8 rainhas (testes[1])
        testes[0] = 4;
        testes[1] = 8;
    }
    else{
        // Caso um argumento tenha sido passado via linha de comando

        // Aloca dinamicamente espaço para copiar a string do argumento (número de rainhas)
        char *buffer = (char *)malloc(strlen(argv[1]) + 1);  // +1 para o caractere nulo '\0'

        // Copia o conteúdo do argumento para o buffer
        strcpy(buffer, argv[1]);

        // Converte o conteúdo do buffer (string) para inteiro e armazena em testes[0]
        testes[0] = atoi(buffer);

        // Define o segundo valor como 0 (nesse código ele não é utilizado ativamente)
        testes[1] = 0;

        // Libera a memória alocada para o buffer após o uso
        free(buffer);
    }

    // Chama a função que executa o algoritmo das N rainhas com base nos valores definidos em 'testes'
    exec(testes);

    // Libera a memória alocada para o vetor 'testes'
    free(testes);

    // Retorna 0 indicando que o programa terminou com sucesso
    return 0;
}
