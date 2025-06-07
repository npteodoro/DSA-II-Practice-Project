#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include "list.h"

typedef struct hash
{
    FILE* fhash;
    char* fpath;
    unsigned int capacity; // m
    list** student_list; 
} hash;

hash* new_hash();
void free_hash(hash* hash_table);
void initialize_hash(hash* hash_table, unsigned int capacity, const char* path);
void hash_insert(hash* hash_table, student new_student);
void hash_remove(hash* hash_table, const char* name);
void hash_search(hash* hash_table, const char* name);
void save_hash_file(hash* hash_table, const char* path);
int load_hash_file(hash* hash_table, const char* path);
unsigned int h1(const char* name);
unsigned int h2(unsigned int capacity, const char* name);
unsigned int rotl(unsigned int value, unsigned int n_bits);
unsigned int count_file_lines(const char* path);

#endif