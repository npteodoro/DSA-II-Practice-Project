// Fun��o principal do algoritmo para resolver o problema das N rainhas
void find_queens(int row, int tsize, int **vec_sol, int *cur_table, int *diag, int *columns, int *tsol, int *tcalls);
    // Fun��o recursiva para tentar colocar uma rainha na linha 'row' e verificar a solu��o
    // 'row' representa a linha onde estamos tentando colocar a rainha
    // 'tsize' � o tamanho do tabuleiro (n�mero de linhas/colunas)
    // 'vec_sol' armazena todas as solu��es encontradas at� o momento
    // 'cur_table' mant�m o estado atual do tabuleiro (onde cada valor indica a coluna da rainha)
    // 'diag' verifica os conflitos nas diagonais
    // 'columns' verifica os conflitos nas colunas
    // 'tsol' conta o n�mero total de solu��es encontradas
    // 'tcalls' conta o n�mero total de chamadas feitas pela fun��o

// Fun��o que verifica se uma solu��o � sim�trica em rela��o a outras solu��es encontradas
int check_for_simmetry(int *cur_table, int tsize, int *tsol, int **cur_sol);
    // Verifica se a solu��o 'cur_table' � sim�trica, evitando solu��es duplicadas.
    // 'cur_table' � o estado atual do tabuleiro
    // 'tsize' � o tamanho do tabuleiro
    // 'tsol' � o n�mero total de solu��es encontradas
    // 'cur_sol' armazena as solu��es at� o momento// Retorna 0 ou 1 dependendo se encontrou simetria (implementa��o necess�ria)

// Fun��o para rotacionar a solu��o atual do tabuleiro em 90 graus
void rotate_ninety_degrees(int *cur_table, int tsize);
    // Rotaciona a solu��o atual do tabuleiro em 90 graus
    // O estado 'cur_table' ser� modificado para representar a solu��o rotacionada.
    // 'tsize' � o tamanho do tabuleiro (n�mero de linhas e colunas)


// Fun��o para refletir verticalmente a solu��o do tabuleiro
void vertical_reflect(int *cur_table, int tsize);
    // Reflete a solu��o do tabuleiro verticalmente
    // 'cur_table' representa o estado atual do tabuleiro
    // 'tsize' � o tamanho do tabuleiro

// Fun��o para verificar se a solu��o 'cur_table' j� foi encontrada anteriormente
int verify_for_replicas(int *cur_table, int tsize, int *tsol, int **cur_sol);
    // Verifica se a solu��o 'cur_table' � uma r�plica de solu��es anteriores
    // Se for uma r�plica, retorna 1 (verdadeiro), caso contr�rio retorna 0 (falso).
    // 'cur_table' � o estado atual do tabuleiro
    // 'tsize' � o tamanho do tabuleiro
    // 'tsol' � o n�mero total de solu��es encontradas
    // 'cur_sol' cont�m as solu��es anteriores

// Fun��o principal que executa o algoritmo para resolver o problema das N rainhas
void exec(int *testes);
    // 'testes' � um vetor que cont�m par�metros para a execu��o
    // O vetor pode conter o n�mero de rainhas e outras vari�veis de configura��o
    // Aqui voc� inicializaria as vari�veis necess�rias e chamaria a fun��o 'find_queens'

