#ifndef PARSER_H
#define PARSER_H
#include "hash.h"

typedef enum {
    CREATE,
    INSERT,
    REMOVE,
    SEARCH,
    NONE,
    INVALID
} command_enum;

typedef struct parser
{
    command_enum command;
    char* path;
    int num_args;
    int input_size; // when the input has a list of names or students I need to know the size of this list
    union {
        int size;
        char** names;
        student* new_students;
    };
} parser;

parser* new_parser(int arg_count);
void free_parser(parser* p);
parser* parse_command_line_arguments(int arg_count, char* arg_values[]);

#endif