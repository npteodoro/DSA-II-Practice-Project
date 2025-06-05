#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

hash* new_hash() {
    hash* h = malloc(sizeof(hash));
    if(h == NULL) return NULL;

    h->capacity = 0;
    h->student_list = NULL;
    
    return h;
}

void free_hash(hash* hash_table) {
    free(hash_table->fpath);
    for(unsigned int i = 0; i < hash_table->capacity; i++) {
        free_list((hash_table->student_list)[i]);
    }
    free(hash_table->student_list);
    free(hash_table);
}

void initialize_hash(hash* hash_table, unsigned int capacity, const char* path) {
    FILE* fhash = fopen(path, "w");
    fclose(fhash);

    hash_table->fpath = malloc( strlen(path) * sizeof(char) + 1);
    strcpy(hash_table->fpath, path);

    hash_table->capacity = capacity;
    hash_table->student_list = malloc( capacity * sizeof( list* ) );
    
    for(unsigned int i = 0; i < capacity; i++) {
        (hash_table->student_list)[i] = create_list();
    }

}

unsigned int bits(unsigned int number) {
    unsigned int n_bits = 0;
    for(int i = 0; i < 32; i++) {
        if( number & (1 << i) ) n_bits++;
    }

    return n_bits;
}

unsigned int rotl(unsigned int value, unsigned int n_bits) {
    unsigned int total_value_bits = bits(value);
    unsigned int new_value = 0;

    if(total_value_bits <= n_bits) {
        // is equivalent to rotate 'value' by (n_bits % total_value_bits)
        n_bits %= total_value_bits;
    }

    new_value = (value << n_bits);
    unsigned int leftmost_bits_that_dissapeared = (value >> (total_value_bits - n_bits));
    new_value |= leftmost_bits_that_dissapeared;

    return new_value;
}

unsigned int h1(const char* name) {
    unsigned int key = 0;
    for(unsigned long i = 0; i < strlen(name); i++) {
        key += ( (int)name[i] << (i % 8));
    }
    return (rotl(key, 13));
}

unsigned int h2(unsigned int hash_capacity, const char* name) {
    return ( h1(name) % hash_capacity);
}

void hash_insert(hash* hash_table, student new_student) {
    unsigned int key = h2(hash_table->capacity, new_student.name);
    //printf("inserting student %s at key %d\n", new_student.name, key);
    insert_element(hash_table->student_list[key], new_student);

}

void hash_remove(hash* hash_table, const char* name) {
    unsigned int key = h2(hash_table->capacity, name);
    //printf("removing student %s at key %d\n", name, key);
    remove_element(hash_table->student_list[key], name);
}

void hash_search(hash* hash_table, const char* name) {
    unsigned int key = h2(hash_table->capacity, name);
    //printf("searching student %s at key %d\n", name, key);
    student* found = search(hash_table->student_list[key], name);
    if(found == NULL) {
        printf("O estudante %s nao esta na lista\n", name);
    }
    else {
        printf("%s:%u:%s\n", found->name, found->nusp, found->course);
    }
}

void save_hash_file(hash* hash_table) {
    hash_table->fhash = fopen(hash_table->fpath, "w");
    if(hash_table->fhash == NULL) {
        printf("Error opening hash file [%s]\n", hash_table->fpath);
        return;
    }

    for(unsigned int i = 0; i < hash_table->capacity; i++) {
        if(hash_table->student_list[i]->head == NULL) { // there is no student at this index 
            fprintf(hash_table->fhash, "\n");
            continue;
        }
        fprintf(hash_table->fhash, "%s:%u:%s", hash_table->student_list[i]->head->data.name,
                hash_table->student_list[i]->head->data.nusp, hash_table->student_list[i]->head->data.course);
        for(node* curr = hash_table->student_list[i]->head->nxt; curr != NULL; curr = curr->nxt) {
            fprintf(hash_table->fhash, ",%s:%u:%s", curr->data.name,
                curr->data.nusp, curr->data.course);
        }
        fprintf(hash_table->fhash, "\n");
    }

    fclose(hash_table->fhash);
}
unsigned int count_file_lines(const char* path) {
    FILE* file = fopen(path, "r");
    if(file == NULL) {
        return 0;
    }
    
    unsigned int lines = 0;
    while(!feof(file)) {
        char ch = fgetc(file);
        if(ch == '\n') lines++;
    }

    fclose(file);
    return lines;
}

void add_student_from_file(hash* hash_table, char* file_line) {
    int info_pos = 0; // 0 -> name; 1 -> nusp; 2 -> course

    student dummy = {
        .name = "",
        .nusp = 0,
        .course = ""
    };
    char double_dot[] = ":";
    for(char* infos = strtok(file_line, double_dot); infos != NULL; infos = strtok(NULL, double_dot)) {
        //printf("infos = %s\n", infos);
        if(info_pos == 0) {
            dummy.name = (char*)malloc(strlen(infos) * sizeof(char) + 1);
            strcpy(dummy.name, infos);
        }else if(info_pos == 1) {
            dummy.nusp = (unsigned int)strtoul(infos, NULL, 10);
        }else {
            info_pos = 0;
            dummy.course = (char*)malloc(strlen(infos) * sizeof(char) + 1);
            strcpy(dummy.course, infos);
            student to_add = copy_student(&dummy);
            free(dummy.name);
            free(dummy.course);
            hash_insert(hash_table, to_add);
            free(to_add.name);
            free(to_add.course);
        }
        info_pos++;
    }

}

void load_hash_file(hash* hash_table, const char* path) {
    if(hash_table->student_list != NULL) {
        for(unsigned int i = 0; i < hash_table->capacity; i++) 
            free_list(hash_table->student_list[i]);
        free(hash_table->student_list);
        // assert that the hash is empty so that we can read from the file and fill it up
    }
    hash_table->capacity = count_file_lines(path);
    hash_table->student_list = (list**)malloc(hash_table->capacity * sizeof(list*));
    for(unsigned int i = 0; i < hash_table->capacity; i++) {
        (hash_table->student_list)[i] = create_list();
    }
    
    FILE* fhash = fopen(path, "r");
    if(fhash == NULL) {
        printf("error reading file\n");
        return;
    }

    char comma[] = ",";
    while(!feof(fhash)) {
        //printf("reading file\n");
        char line_buffer[2048];
        
        fgets(line_buffer, sizeof(line_buffer), fhash);
        line_buffer[strcspn(line_buffer, "\n")] = 0;
        //printf("%s\n", line_buffer);
        if(!strcmp(line_buffer, "\n")) continue;

        char* diff_students = strtok(line_buffer, comma);
        if(diff_students == NULL) {
            add_student_from_file(hash_table, line_buffer);
        }
        for(; diff_students != NULL; diff_students = strtok(NULL, comma)) {
            add_student_from_file(hash_table, diff_students);
        }
        //printf("end line\n");
    }

    fclose(fhash);

}