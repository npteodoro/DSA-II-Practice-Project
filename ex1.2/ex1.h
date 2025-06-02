// Gera todas as combinações possíveis de pares (i, j) diferentes em uma matriz de combinações.
void generate_combinations(int i, int j, int size, int combinations[][2], int *it);

// Gera uma nova lista e vetor de strings representando uma operação entre dois elementos da lista atual.
void generate_new_list(int *curr_list,char curr_string_vector[][100],int size,int i1,int i2,int operation_type,int *new_list,char new_string_vector[][100],int i,int k,int flag);

// Função recursiva que tenta encontrar uma expressão que resulte no valor desejado.
void find_expression(int size,int *curr_list,int i,int value,char curr_string_vector[][100],char *ans,int flag,int combinations[][2], int *tcalls);

