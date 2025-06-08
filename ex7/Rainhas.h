// Função principal do algoritmo para resolver o problema das N rainhas
void find_queens(int row, int tsize, int **vec_sol, int *cur_table, int *diag, int *columns, int *tsol, int *tcalls);
    // Função recursiva para tentar colocar uma rainha na linha 'row' e verificar a solução
    // 'row' representa a linha onde estamos tentando colocar a rainha
    // 'tsize' é o tamanho do tabuleiro (número de linhas/colunas)
    // 'vec_sol' armazena todas as soluções encontradas até o momento
    // 'cur_table' mantém o estado atual do tabuleiro (onde cada valor indica a coluna da rainha)
    // 'diag' verifica os conflitos nas diagonais
    // 'columns' verifica os conflitos nas colunas
    // 'tsol' conta o número total de soluções encontradas
    // 'tcalls' conta o número total de chamadas feitas pela função

// Função que verifica se uma solução é simétrica em relação a outras soluções encontradas
int check_for_simmetry(int *cur_table, int tsize, int *tsol, int **cur_sol);
    // Verifica se a solução 'cur_table' é simétrica, evitando soluções duplicadas.
    // 'cur_table' é o estado atual do tabuleiro
    // 'tsize' é o tamanho do tabuleiro
    // 'tsol' é o número total de soluções encontradas
    // 'cur_sol' armazena as soluções até o momento// Retorna 0 ou 1 dependendo se encontrou simetria (implementação necessária)

// Função para rotacionar a solução atual do tabuleiro em 90 graus
void rotate_ninety_degrees(int *cur_table, int tsize);
    // Rotaciona a solução atual do tabuleiro em 90 graus
    // O estado 'cur_table' será modificado para representar a solução rotacionada.
    // 'tsize' é o tamanho do tabuleiro (número de linhas e colunas)


// Função para refletir verticalmente a solução do tabuleiro
void vertical_reflect(int *cur_table, int tsize);
    // Reflete a solução do tabuleiro verticalmente
    // 'cur_table' representa o estado atual do tabuleiro
    // 'tsize' é o tamanho do tabuleiro

// Função para verificar se a solução 'cur_table' já foi encontrada anteriormente
int verify_for_replicas(int *cur_table, int tsize, int *tsol, int **cur_sol);
    // Verifica se a solução 'cur_table' é uma réplica de soluções anteriores
    // Se for uma réplica, retorna 1 (verdadeiro), caso contrário retorna 0 (falso).
    // 'cur_table' é o estado atual do tabuleiro
    // 'tsize' é o tamanho do tabuleiro
    // 'tsol' é o número total de soluções encontradas
    // 'cur_sol' contém as soluções anteriores

// Função principal que executa o algoritmo para resolver o problema das N rainhas
void exec(int *testes);
    // 'testes' é um vetor que contém parâmetros para a execução
    // O vetor pode conter o número de rainhas e outras variáveis de configuração
    // Aqui você inicializaria as variáveis necessárias e chamaria a função 'find_queens'

