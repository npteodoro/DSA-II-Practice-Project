// Gera todas as combinações possíveis de pares (i, j) distintos, ou seja, i ≠ j.
// Os pares são armazenados em uma matriz 'combinations'.
// Parâmetros:
//   - i, j: índices atuais para controle da recursão
//   - size: número total de elementos na lista
//   - combinations: matriz que armazena os pares (i, j)
//   - it: ponteiro para o índice atual da matriz de combinações
void generate_combinations(int i, int j, int size, int combinations[][2], int *it);


// Gera uma nova lista (`new_list`) a partir de `curr_list`, realizando uma operação entre os elementos
// de índices i1 e i2. Também gera um novo vetor de strings (`new_string_vector`) com a expressão correspondente.
// Parâmetros:
//   - curr_list: lista atual de inteiros
//   - curr_string_vector: vetor de strings representando expressões atuais
//   - size: tamanho da lista atual
//   - i1, i2: índices dos elementos que serão combinados
//   - operation_type: tipo de operação (0=*, 1=/, 2=+, 3=-)
//   - new_list: nova lista resultante após a operação
//   - new_string_vector: novo vetor de strings com a operação aplicada
//   - i: índice atual do loop recursivo
//   - k: deslocamento usado para manter os índices corretos ao remover elementos
//   - flag: indica se a operação já foi aplicada (para evitar aplicar mais de uma vez)
void generate_new_list(int *curr_list, char curr_string_vector[][100], int size, int i1, int i2,
                       int operation_type, int *new_list, char new_string_vector[][100], int i, int k, int flag);


// Função recursiva que tenta encontrar uma expressão aritmética que resulta no valor desejado.
// Testa todas as combinações de operações (+, -, *, /) entre os elementos da lista.
// Parâmetros:
//   - size: tamanho atual da lista (decrementa a cada passo)
//   - curr_list: lista de inteiros atual
//   - i: índice da combinação atual a ser processada
//   - value: valor alvo que se deseja alcançar
//   - curr_string_vector: vetor de strings com a representação das expressões atuais
//   - ans: string onde a resposta (expressão final) será armazenada
//   - flag: controle para evitar recomputar combinações
//   - combinations: matriz com as combinações de pares de índices
//   - tcalls: ponteiro para contador de chamadas (para análise de complexidade)
void find_expression(int size, int *curr_list, int i, int value,
                     char curr_string_vector[][100], char *ans, int flag,
                     int combinations[][2], int *tcalls);
