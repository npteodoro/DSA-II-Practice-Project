#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rainhas.h"
#define INF 1000000000

// Verifica se a solução atual já foi registrada (para evitar duplicatas)
int verify_for_replicas(int *cur_table, int tsize, int *tsol, int **cur_sol)
{
    for(int i = 0; i < (*tsol); i++)
    {
        int cont = 0;
        for(int j = 0; j < tsize; j++)
        {
            // Compara cada posição das soluções já encontradas com a atual
            if(cur_sol[i][j] == cur_table[j]) cont++;
        }
        if(cont == tsize)
        {
            // Se todas as posições são iguais, a solução já existe
            return 0;
        }
    }
    // Solução é única
    return 1;
}

// Reflete o tabuleiro verticalmente (simetria)
void vertical_reflect(int *cur_table, int tsize)
{
    int *aux_table = malloc(tsize * sizeof(int));
    // Constrói o tabuleiro refletido   
    for(int i = 0; i < tsize; i++){
        aux_table[i] = cur_table[tsize - i - 1];
    }
    // Copia o tabuleiro refletido de volta para o original
    for(int i = 0; i < tsize; i++){
        cur_table[i] = aux_table[i];
    }
    free(aux_table);
    return;
}

// Rotaciona o tabuleiro 90 graus (simetria)
void rotate_ninety_degrees(int *cur_table, int tsize)
{
    int *aux_table = malloc(tsize * sizeof(int));
    // Constrói o tabuleiro rotacionado
    for(int i = 0 ; i < tsize; i++){
        aux_table[tsize - cur_table[i] - 1] = i;
    }
    // Copia o tabuleiro rotacionado de volta para o original
    for(int i = 0; i < tsize; i++){
        cur_table[i] = aux_table[i];
    }
    free(aux_table);
    return;
}

// Verifica se a solução atual é simétrica a alguma já encontrada
int check_for_simmetry(int *cur_table, int tsize,int *tsol, int **cur_sol)
{
    int ok = 1;

    // Reflete verticalmente e verifica duplicata
    vertical_reflect(cur_table, tsize);
    ok &= verify_for_replicas(cur_table, tsize, tsol, cur_sol);
    vertical_reflect(cur_table, tsize); // Reverte a reflexão

    // Executa rotações e reflexões para cobrir todas as simetrias possíveis
    rotate_ninety_degrees(cur_table, tsize);
    ok &= verify_for_replicas(cur_table, tsize, tsol, cur_sol);
    vertical_reflect(cur_table, tsize);
    ok &= verify_for_replicas(cur_table, tsize, tsol, cur_sol);
    vertical_reflect(cur_table, tsize);

    rotate_ninety_degrees(cur_table, tsize);
    ok &= verify_for_replicas(cur_table, tsize, tsol, cur_sol);
    vertical_reflect(cur_table, tsize);
    ok &= verify_for_replicas(cur_table, tsize, tsol, cur_sol);
    vertical_reflect(cur_table, tsize);

    rotate_ninety_degrees(cur_table, tsize);
    ok &= verify_for_replicas(cur_table, tsize, tsol, cur_sol);
    vertical_reflect(cur_table, tsize);
    ok &= verify_for_replicas(cur_table, tsize, tsol, cur_sol);
    vertical_reflect(cur_table, tsize);

    rotate_ninety_degrees(cur_table, tsize); // Retorna à orientação original

    return ok;
}

// Função recursiva que tenta posicionar as rainhas uma por linha
void find_queens(int row ,int tsize, int **vec_sol, int *cur_table, int *diag, int *columns, int *tsol , int *tcalls)
{
    (*tcalls)++; // Contador de chamadas recursivas

    // Se todas as rainhas foram posicionadas
    if(row == tsize)
    {
        // Verifica se a solução não é simétrica a alguma já encontrada
        if(check_for_simmetry(cur_table,tsize,tsol,vec_sol) == 1)
        {
            // Armazena a nova solução no vetor de soluções
            for(int i = 0; i < tsize; i++)
            {
                vec_sol[(*tsol)][i] = cur_table[i];
            }
            (*tsol)++; // Incrementa o número de soluções
        }
        return;
    }

    // Tenta colocar a rainha em todas as colunas disponíveis da linha atual
    for(int i = 0; i < tsize; i++)
    {
        int anti_diag_idx = 3*tsize - 2 + row - i; // Índice da antidiagonal principal
        // Verifica se a coluna e diagonais estão livres
        if(columns[i] != 1 && diag[row + i] != 1 && diag[anti_diag_idx] != 1)
        {
           // Marca as posições ocupadas
           columns[i] = 1;
           diag[row + i] = 1;
           diag[anti_diag_idx] = 1;
           cur_table[i] = row;

           // Chama recursivamente para a próxima linha
           find_queens(row + 1, tsize, vec_sol, cur_table, diag, columns, tsol, tcalls);

           // Desmarca posições (backtracking)
           columns[i] = 0;
           diag[row + i] = 0;
           diag[3*tsize - 2 + row - i] = 0;
        }
    }
    return;
}

void fill_with_zero(int* vector, int vector_size) {
    for(int i = 0; i < vector_size; i++) {
        vector[i] = 0;
    }
}

// Função principal de execução: resolve o problema para um vetor de tamanhos de tabuleiro
void exec(int *testes)
{
    for(int i = 0; i < 2; i++){
        int n = testes[i];
        if(n == INF) break; // Termina se valor for zero

        // Aloca memória para as soluções
        int **vec_sol = (int**)malloc(10000*sizeof(int *));
        for(int i = 0; i < 10000; i++){
            vec_sol[i] = (int *)malloc(n*sizeof(int));
        }

        int *cur_table = malloc(n*sizeof(int));               // Armazena uma solução parcial
        fill_with_zero(cur_table, n);
        int *diag = malloc((4*n - 2)*sizeof(int));            // Marca ocupação das diagonais
        fill_with_zero(diag, 4*n - 2);
        int *columns = malloc(n*sizeof(int));                 // Marca ocupação das colunas
        fill_with_zero(columns, n);
        int tsol = 0;                                          // Total de soluções
        int tcalls = 0;                                        // Total de chamadas recursivas

        // Inicia a busca por soluções
        find_queens(0,n,vec_sol,cur_table,diag,columns, &tsol, &tcalls);

        // Exibe as soluções, se existirem
        if(tsol != 0 && n != 0)
            for(int i = 0; i < tsol; i++){
                for(int j = 0; j < n; j++){
                    if(j == 0) printf("[");
                    printf("%d", vec_sol[i][j]);
                    if(j != n - 1) printf(",");
                    if(j == n - 1) printf("]");
                }
                printf("\n");
            }
        else
            printf("Nao existe solucao para %d rainhas\n", n);

        // Exibe estatísticas
        printf("O numero de chamadas e %d\n", tcalls);
        printf("O numero de solucoes e %d\n", tsol);

        // Libera memória
        for(int i = 0; i < 10000; i++) {
            free(vec_sol[i]);
        }
        free(vec_sol);
        free(cur_table);
        free(diag);
        free(columns);
    }
    return;
}
