#ifndef HASH_H
#define HASH_H
#include <stdio.h>

typedef struct student
{
    char* name;
    char* course;
    unsigned int nusp;
} student;

typedef struct hash
{
    FILE* fhash;
    char* fpath;
    unsigned int capacity; // m
    student* list; // student list (TODO: linked list for collision)
} hash;

hash* new_hash();
void initialize_hash(hash* hash_table, unsigned int capacity, const char* path);
void hash_insert(hash* hash_table, student new_student);
void hash_remove(hash* hash_table, const char* name);
void hash_search(hash* hash_table, const char* name);
void save_hash_file(hash* hash_table);
unsigned int h1(const char* name);
unsigned int h2(unsigned int capacity, const char* name);
unsigned int rotl(unsigned int value, unsigned int n_bits);

#endif