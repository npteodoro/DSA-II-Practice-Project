#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "test.h"

int main(int argc, char *argv[]) {
    // Check if arguments provided
    if (argc < 2) {
        // Run default test
        runDefaultTest();
        return 0;
    }
    
    // Dispatch to appropriate command handler
    if (strcmp(argv[1], "criar") == 0)
        return criarCommand(argc, argv);
    else if (strcmp(argv[1], "inserir") == 0)
        return inserirCommand(argc, argv);
    else if (strcmp(argv[1], "buscar") == 0)
        return buscarCommand(argc, argv);
    else if (strcmp(argv[1], "remover") == 0)
        return removerCommand(argc, argv);

    // Unknown command
    printf("Failure\n");
    return 1;
}