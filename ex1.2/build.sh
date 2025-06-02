#!/bin/bash

# Nome do executável
EXEC=programa

# Compilação
gcc -Wall -Wextra -std=c99 -o $EXEC main.c ex1.c

# Verifica se a compilação foi bem-sucedida
if [ $? -eq 0 ]; then
    echo "Compilação concluída com sucesso. Executando..."
    ./$EXEC
else
    echo "Erro na compilação."
fi