#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

char* strdup(const char* s) {
    char* copy = malloc(strlen(s) + 1);
    if (copy) strcpy(copy, s);
    return copy;
}


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
    new_p->input_size = 0;

    return new_p;
}

void free_parser(parser* p) {
    free(p->path);
    if(p->input_size != 0) {
        if(p->command == SEARCH || p->command == REMOVE) {
            for(int i = 0; i < p->input_size; i++) 
                free(p->names[i]);
            free(p->names);

        }
        else if(p->command == INSERT) {
            free(p->new_students);
        }
    }
    free(p);
}

char** parse_students_names(char* input_names, int* list_size) {
    char** names_list;
    int num_names = 1;
    for(int i = 0; i < (int)strlen(input_names); i++) {
        if(input_names[i] == ',') num_names++; 
    }
    *list_size = num_names;
    names_list = (char**)malloc(num_names * sizeof(char*));
    if(names_list == NULL) return NULL;

    char comma[] = ",";
    int i = 0;
    char* input_modifiable = strdup(input_names);
    for(char* name = strtok(input_modifiable, comma); name != NULL; name = strtok(NULL, comma)) {
        names_list[i++] = strdup(name);
    }
    free(input_modifiable);

    return names_list;
}

student parse_student(char* input_student) {
    char double_dot[] = ":";
    int info_pos = 0; // 0->name; 1->nusp; 2->course
    student new_student= {
        .name = NULL,
        .nusp = 0,
        .course = NULL
    };
    char* saveptr;
    for(char* infos = strtok_r(input_student, double_dot, &saveptr); infos != NULL; infos = strtok_r(NULL, double_dot, &saveptr)) {
        if(info_pos == 0) {
            new_student.name = (char*)malloc(strlen(infos) * sizeof(char) + 1);
            strcpy(new_student.name, infos);
        }
        else if(info_pos == 1) {
            new_student.nusp = (unsigned int)strtoul(infos, NULL, 10);
        }
        else {
            info_pos = 0;
            new_student.course = (char*)malloc(strlen(infos) * sizeof(char) + 1);
            strcpy(new_student.course, infos);
            break;
        }
        info_pos++;
    }
    return new_student;
}

student* parse_students_list(char* input_students, int* list_size) {
    student* students_list;
    char* modifiable_input = strdup(input_students);
    int num_students = 1;
    for(int i = 0; i < (int)strlen(input_students); i++) {
        if(input_students[i] == ',') num_students++;
    }
    *list_size = num_students;
    students_list = (student*)malloc(num_students * sizeof(student));
    if(students_list == NULL) return NULL;

    char comma[] = ",";
    int i = 0;
    char* saveptr;

    for(char* stdnt = strtok_r(modifiable_input, comma, &saveptr); stdnt != NULL; stdnt = strtok_r(NULL, comma, &saveptr)) {
        students_list[i++] = parse_student(stdnt);
    }

    free(modifiable_input);
    return students_list;
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
            p->path = malloc(strlen(arg_values[3]) + 1);
            strcpy(p->path, arg_values[3]);
            break;
        case INSERT: // main inserir <path> <lista de estudantes>
            if(p->path == NULL) p->path = malloc(strlen(arg_values[3]) + 1);
            strcpy(p->path, arg_values[2]);
            p->new_students = parse_students_list(arg_values[3], &p->input_size);
            break;
        case REMOVE: // main remover <path> <lista de nomes>
        case SEARCH: // main buscar <path> <lista de nomes>
            if(p->path == NULL) p->path = malloc(strlen(arg_values[3]) + 1);
            strcpy(p->path, arg_values[2]);
            p->names = parse_students_names(arg_values[3], &p->input_size);
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