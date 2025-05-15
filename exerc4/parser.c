#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int check_parser_command(const char* command) {
    if( !strcmp(command, "criar") ) {
        return CREATE;
    }
    else if( !strcmp(command, "inserir") ) {
        return INSERT;
    }
    else if( !strcmp(command, "remover") ) {
        return REMOVE;
    }
    else if( !strcmp(command, "buscar") ) {
        return SEARCH;
    }
    else {
        return INVALID;
    }
}

parser* new_parser(int arg_count) {
    parser* new_p = malloc(sizeof(parser));
    if(new_p == NULL) return NULL;

    new_p->command = NONE;
    new_p->num_args = arg_count;
    new_p->path = NULL;

    return new_p;
}

parser* parse_command_line_arguments(int arg_count, char* arg_values[]) {
    
    parser* p = new_parser(arg_count);
    if(p == NULL) return NULL;
    
    if(p->num_args < 2) {
        // only argument is the executable => default test case
        p->command = NONE;
        return p;
    }

    p->command = check_parser_command(arg_values[1]); // index 1 is the command to execute (criar, inserir, remover, buscar)
    switch( p->command ) {
        case CREATE: // main criar <tamanho> <path>
            p->size = atoi(arg_values[2]);
            strcpy(p->path, arg_values[3]);
            break;
        case INSERT: // main inserir <path> <lista de estudantes>
            strcpy(p->path, arg_values[2]);
            //p->new_students = parse_students_list(arg_values[3]);
            break;
        case REMOVE: // main remover <path> <lista de nomes>
        case SEARCH: // main buscar <path> <lista de nomes>
            strcpy(p->path, arg_values[2]);
            //p->names = parse_students_names(arg_values[3]);
            break;
        case INVALID:
            free(p);
            printf("Invalid command [%s]\n", arg_values[1]);
            break;
        default:
            break;
    }

    return p;
}