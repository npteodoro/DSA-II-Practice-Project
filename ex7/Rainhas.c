#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Rainhas.h"

// Verifica se a solu��o atual j� foi registrada (para evitar duplicatas)
int verify_for_replicas(int *cur_table, int tsize, int *tsol, int **cur_sol)
{
    for(int i = 0; i < (*tsol); i++)
    {
        int cont = 0;
        for(int j = 0; j < tsize; j++)
        {
            // Compara cada posi��o das solu��es j� encontradas com a atual
            if(cur_sol[i][j] == cur_table[j]) cont++;
        }
        if(cont == tsize)
        {
            // Se todas as posi��es s�o iguais, a solu��o j� existe
            return 0;
        }
    }
    // Solu��o � �nica
    return 1;
}

// Reflete o tabuleiro verticalmente (simetria)
void vertical_reflect(int *cur_table, int tsize)
{
    for(int i = 0; i < tsize; i++){
        cur_table[i] = tsize - cur_table[i] - 1;
    }
    return;
}

// Rotaciona o tabuleiro 90 graus (simetria)
void rotate_ninety_degrees(int *cur_table, int tsize)
{
    int *aux_table = malloc(tsize * sizeof(int));
    // Constr�i o tabuleiro rotacionado
    for(int i = 0 ; i < tsize; i++){
        aux_table[cur_table[i]] = tsize - i - 1;
    }
    // Copia o tabuleiro rotacionado de volta para o original
    for(int i = 0; i < tsize; i++){
        cur_table[i] = aux_table[i];
    }
    free(aux_table);
    return;
}

// Verifica se a solu��o atual � sim�trica a alguma j� encontrada
int check_for_simmetry(int *cur_table, int tsize,int *tsol, int **cur_sol)
{
    int ok = 1;

    // Reflete verticalmente e verifica duplicata
    vertical_reflect(cur_table, tsize);
    ok &= verify_for_replicas(cur_table, tsize, tsol, cur_sol);
    vertical_reflect(cur_table, tsize); // Reverte a reflex�o

    // Executa rota��es e reflex�es para cobrir todas as simetrias poss�veis
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

    rotate_ninety_degrees(cur_table, tsize); // Retorna � orienta��o original

    return ok;
}

// Fun��o recursiva que tenta posicionar as rainhas uma por linha
void find_queens(int row ,int tsize, int **vec_sol, int *cur_table, int *diag, int *columns, int *tsol , int *tcalls)
{
    (*tcalls)++; // Contador de chamadas recursivas

    // Se todas as rainhas foram posicionadas
    if(row == tsize)
    {
        // Verifica se a solu��o n�o � sim�trica a alguma j� encontrada
        if(check_for_simmetry(cur_table,tsize,tsol,vec_sol) == 1)
        {
            // Armazena a nova solu��o no vetor de solu��es
            for(int i = 0; i < tsize; i++)
            {
                vec_sol[(*tsol)][i] = cur_table[i];
            }
            (*tsol)++; // Incrementa o n�mero de solu��es
        }
        return;
    }

    // Tenta colocar a rainha em todas as colunas dispon�veis da linha atual
    for(int i = 0; i < tsize; i++)
    {
        // Verifica se a coluna e diagonais est�o livres
        if(columns[i] != 1 && diag[row + i] != 1 && diag[3*tsize - 2 + row - i] != 1)
        {
           // Marca as posi��es ocupadas
           columns[i] = 1;
           diag[row + i] = 1;
           diag[3*tsize - 2 + row - i] = 1;
           cur_table[row] = i;

           // Chama recursivamente para a pr�xima linha
           find_queens(row + 1, tsize, vec_sol, cur_table, diag, columns, tsol, tcalls);

           // Desmarca posi��es (backtracking)
           columns[i] = 0;
           diag[row + i] = 0;
           diag[3*tsize - 2 + row - i] = 0;
        }
    }
    return;
}

// Fun��o principal de execu��o: resolve o problema para um vetor de tamanhos de tabuleiro
void exec(int *testes)
{
    for(int i = 0; i < 2; i++){
        int n = testes[i];
        if(n == 0) break; // Termina se valor for zero

        // Aloca mem�ria para as solu��es
        int **vec_sol = (int**)malloc(10000*sizeof(int *));
        for(int i = 0; i < 10000; i++){
            vec_sol[i] = (int *)malloc(n*sizeof(int));
        }

        int *cur_table = malloc(n*sizeof(int));               // Armazena uma solu��o parcial
        int *diag = malloc((4*n - 2)*sizeof(int));            // Marca ocupa��o das diagonais
        int *columns = malloc(n*sizeof(int));                 // Marca ocupa��o das colunas
        int tsol = 0;                                          // Total de solu��es
        int tcalls = 0;                                        // Total de chamadas recursivas

        // Inicia a busca por solu��es
        find_queens(0,n,vec_sol,cur_table,diag,columns, &tsol, &tcalls);

        // Exibe as solu��es, se existirem
        if(tsol != 0)
            for(int i = 0; i < tsol; i++){
                for(int j = 0; j < n; j++){
                    if(j == 0)
                        printf("[%d," ,vec_sol[i][j]);
                    else if(j == n - 1)
                        printf("%d]" ,vec_sol[i][j]);
                    else
                        printf("%d,", vec_sol[i][j]);
                }
                printf("\n");
            }
        else
            printf("Nao existe solucao para %d rainhas\n", n);

        // Exibe estat�sticas
        printf("O numero de chamadas e %d\n", tcalls);
        printf("O numero de solucoes e %d\n", tsol);

        // Libera mem�ria
        free(vec_sol);
        free(cur_table);
        free(diag);
        free(columns);
    }
    return;
}
