#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ex1.h" // Inclusão do cabeçalho com as declarações das funções auxiliares como find_expression()



void run_case(int* numbers, int count, int target) {
    char string_vector[6][100]; // Vetor de strings para representar expressões (como "3+2")
    int combinations[100][2];   // Matriz que armazenará as combinações de pares de índices

    // Inicializa string_vector com a versão textual de cada número
    for (int i = 0; i < count; i++) {
        sprintf(string_vector[i], "%d", numbers[i]); // Ex: numbers[i] = 3 → string_vector[i] = "3"
    }

    char ans[100] = "Nao foi possivel formar o valor alvo"; // Resposta padrão, caso não encontre solução
    int tcalls = 0; // Contador de chamadas recursivas (para análise de desempenho)

    // Chamada da função principal que tenta encontrar a expressão que resulta no alvo
    find_expression(count - 1, numbers, 0, target, string_vector, ans, 0, combinations, &tcalls);

    // Exibe a resposta encontrada e o número de chamadas recursivas
    printf("%s\n", ans);
    printf("%d\n", tcalls);
}



int main(int argc, char *argv[]) {
    // Caso o programa seja executado sem argumentos
    if (argc < 2) {
        // Caso de teste 1
        int caso1[] = {
            [0] = 3,
            [1] = 4,
            [2] = 2 
        };

        // Caso de teste 2
        int caso2[] = {
            [0] = 5,
            [1] = 2,
            [2] = 1,
            [3] = 8 
        };

        // Executa os casos pré-definidos
        run_case(caso1, 3, 14); // Deve tentar formar 14 a partir de 3, 4, 2
        run_case(caso2, 4, 16); // Deve tentar formar 16 a partir de 5, 2, 1, 8
        return 0;
    }

    // Se foram passados argumentos via linha de comando:
    char ans[100] = "Nao foi possivel formar o valor alvo"; // Inicializa resposta padrão
    int list[6];  // Vetor com os números fornecidos pelo usuário
    int count = 0; // Quantidade de números lidos

    // Copia os números recebidos como string para um buffer
    char* ls = malloc(strlen(argv[1]) + 1);
    for (int i = 0; i < (int)strlen(argv[1]); i++) {
        ls[i] = argv[1][i];
    }
    ls[strlen(argv[1])] = '\0'; // Termina a string manualmente

    // Converte o segundo argumento para inteiro (valor alvo desejado)
    char *a;
    int value = strtol(argv[2], &a, 10);

    // Divide a string dos números (ex: "5,2,1,8") em tokens separados por vírgula
    char *token = strtok(ls, ",");
    while (token != NULL && count < 100) {
        char *a1;
        int aux = strtol(token, &a1, 10); // Converte token para inteiro
        list[count++] = aux;              // Armazena no vetor
        token = strtok(NULL, ",");        // Próximo token
    }

    // Prepara o vetor de strings correspondente à representação textual dos números
    char string_vector[6][100];
    int combinations[100][2]; // Vetor para armazenar as combinações de índices
    for (int i = 0; i < count; i++) {
        sprintf(string_vector[i], "%d", list[i]); // Ex: list[i] = 5 → string_vector[i] = "5"
    }

    int tcalls = 0; // Contador de chamadas recursivas

    // Chamada principal da função que tenta encontrar a expressão desejada
    find_expression(count - 1, list, 0, value, string_vector, ans, 0, combinations, &tcalls);

    // Imprime a resposta (expressão ou mensagem de erro) e número de chamadas
    printf("%s\n", ans);
    printf("%d\n", tcalls);

    return 0;
}
