#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "list.h"
#include "parser.h"
#define DEFAULT_CAPACITY 11
#define DEFAULT_PATH "hash_nome.txt"

int is_prime(int x) {
    if(x < 2) return 0;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return 0;
    }
    return 1;
}

int approx_to_prime(int num) {
    for(; !is_prime(num); num++) {}
    return num;
}

void default_test_case(hash* hash_table) {
    const char path[] = "hash_nome.txt"; 
    initialize_hash(hash_table, DEFAULT_CAPACITY, path);

    student default_students[5] = {
        [0].name = "Marco",
        [0].course = "fisica",
        [0].nusp = 1231,

        [1].name = "Pedro",
        [1].course = "eng-comp",
        [1].nusp = 553452,

        [2].name = "Luis",
        [2].course = "eng-comp",
        [2].nusp = 89237,

        [3].name = "Kaue",
        [3].course = "arq",
        [3].nusp = 9812,

        [4].name = "Mateus",
        [4].course = "eng-comp",
        [4].nusp = 12314,
    };

    for(int i = 0; i < 5; i++) {
        hash_insert(hash_table, default_students[i]);
    }

    for(int i = 4; i > 2; i--) {
        hash_remove(hash_table, default_students[i].name);
    }

    save_hash_file(hash_table, DEFAULT_PATH);
    
    load_hash_file(hash_table, DEFAULT_PATH);
    hash_search(hash_table, "Marco");
    hash_search(hash_table, "Pedro");
    hash_search(hash_table, "Kaue");
    
}

int main(int argc, char* argv[]) {
    parser* input_parser = parse_command_line_arguments(argc, argv);
    if(input_parser == NULL) {
        printf("Error! (parser is null)\n");
        exit(1);
    }

    hash* hash_table = new_hash();
    if(hash_table == NULL) {
        printf("Error! (hash table is null)\n");
        exit(1);
    }

    int success = 1;
    switch (input_parser->command)
    {
    case NONE:
        default_test_case(hash_table);
        break;
    case CREATE:
        int hash_capacity = approx_to_prime(input_parser->size);
        initialize_hash(hash_table, hash_capacity, input_parser->path);
        save_hash_file(hash_table, input_parser->path);
        break;
    case SEARCH:
        success = load_hash_file(hash_table, input_parser->path);
        if(!success) break;
        for(int i = 0; i < input_parser->input_size; i++) {
            hash_search(hash_table, input_parser->names[i]);
        }
        break;
    case INSERT:
        hash_capacity = count_file_lines(input_parser->path);
        success = load_hash_file(hash_table, input_parser->path);
        if(!success) {
            printf("Failure\n");
            break;
        }
        for(int i = 0; i < input_parser->input_size; i++) {
            hash_insert(hash_table, input_parser->new_students[i]);
            free(input_parser->new_students[i].course);
            free(input_parser->new_students[i].name);
        }
        save_hash_file(hash_table, input_parser->path);
        printf("Success\n");
        break;
    case REMOVE:
        success = load_hash_file(hash_table, input_parser->path);
        if(!success) {
            printf("Failure\n");
            break;
        }
        for(int i = 0; i < input_parser->input_size; i++) {
            hash_remove(hash_table, input_parser->names[i]);
        }
        save_hash_file(hash_table, input_parser->path);
        printf("Success\n");
        break;
    default:
        break;
    }

    free_hash(hash_table);
    free_parser(input_parser);
    return 0;
}
