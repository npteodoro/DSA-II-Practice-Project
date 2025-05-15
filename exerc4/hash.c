#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

hash* new_hash() {
    hash* h = malloc(sizeof(hash));
    if(h == NULL) return NULL;

    h->capacity = 0;

    return h;
}

void initialize_hash(hash* hash_table, unsigned int capacity, const char* path) {
    hash_table->fhash = fopen(path, "w");

    hash_table->fpath = malloc( strlen(path) );
    strcpy(hash_table->fpath, path);
    
    if(hash_table->fhash == NULL) {
        printf("Error! (cant open hash file [%s])\n", path);
        return;
    }

    hash_table->capacity = capacity;
    hash_table->list = malloc( capacity * sizeof( student ) );
    
    for(unsigned int i = 0; i < capacity; i++) {
        (hash_table->list)[i].name = NULL;
    }

    fclose(hash_table->fhash);
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
    printf("KEY = %d\n", key);
    if( hash_table->list[key].name != NULL ) {
        // TODO: collision
        return;
    }

    hash_table->list[key] = new_student;
}

void hash_remove(hash* hash_table, const char* name) {
    unsigned int key = h2(hash_table->capacity, name);
    if( hash_table->list[key].name == NULL ) {
        // there is no student with name 'name' on the list
        return;
    }

    // TODO: check collision case
    hash_table->list[key].name = NULL;
    hash_table->list[key].course = NULL;
    hash_table->list[key].nusp = 0;
}
void hash_search(hash* hash_table, const char* name) {
    unsigned int key = h2(hash_table->capacity, name);

    if( !strcmp(hash_table->list[key].name, name) ) {
        // TODO: check collision case
        printf("Found student: %s : %s : %u\n", 
                hash_table->list[key].name, hash_table->list[key].course,
                hash_table->list[key].nusp);
        return;
    }

    printf("Student %s not in the list\n", name);
}

void save_hash_file(hash* hash_table) {
    hash_table->fhash = fopen(hash_table->fpath, "w");
    if(hash_table->fhash == NULL) {
        printf("Error opening hash file [%s]\n", hash_table->fpath);
        return;
    }

    for(unsigned int i = 0; i < hash_table->capacity; i++) {
        fprintf(hash_table->fhash, "%s:%u:%s,", hash_table->list[i].name,
                hash_table->list[i].nusp, hash_table->list[i].course);
    }

    fclose(hash_table->fhash);
}