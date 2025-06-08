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

/**
 * creates a new parser object to parse some text from the command line
 * @param arg_count number of arguments to parse
 * @return pointer to a new parser
*/
parser* new_parser(int arg_count);

/**
 * frees the allocated memory to a parser
 * @param p pointer to the parser that needs to be freed
*/
void free_parser(parser* p);

/**
 * parses the command line arguments passed to the code and 
 * returns it to a parser, so that the important informations can
 * be more easily used 
 * @param arg_count number of command line arguments
 * @param arg_values array of the command line arguments
 * @return a parser with all the information separated 
*/
parser* parse_command_line_arguments(int arg_count, char* arg_values[]);

#endif