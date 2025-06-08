#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include "list.h"

typedef struct hash
{
    FILE* fhash;
    char* fpath;
    unsigned int capacity; // m
    list** student_list; // linked list of students
} hash;

/**
 * creates a new hash pointer
 * @return pointer to new allocated hash table
*/
hash* new_hash(); 

/**
 * frees the memory allocated to a hash table
 * @param hash_table hash pointer to be freed
*/
void free_hash(hash* hash_table); 

/**
 * initalizes a hash table starting inside objects to NULL 
 * and setting capacity to 'capacity'
 * @param hash_table hash to initialize
 * @param capacity hash_table maximum capacity
 * @param path path to the .txt file that stores the hash_table elements
*/
void initialize_hash(hash* hash_table, unsigned int capacity, const char* path); 

/**
 * calculates the position and inserts a new student to the hash table
 * @param hash_table hash to insert
 * @param new_student student that will be added on the hash using its name as hash
*/
void hash_insert(hash* hash_table, student new_student);

/**
 * removes a student from the list that matches the name passed as argument
 * @param hash_table hash to remove
 * @param name name of the student that is going to be removed (if exists)
*/
void hash_remove(hash* hash_table, const char* name);

/**
 * searches for a specific student with name 'name' inside the hash 
 * and print its informations if found
 * @param hash_table hash to search
 * @param name name of the target student
*/
void hash_search(hash* hash_table, const char* name);

/**
 * saves all hash_table content to .txt file with path 'path'
 * @param hash_table hash to save to the file
 * @param path path of the .txt file to dave the hash
*/
void save_hash_file(hash* hash_table, const char* path);

/**
 * loads the contents of a .txt file with path 'path' and puts it into
 * the hash table passed as argument
 * @param hash_table - hash where contents will be copied to
 * @param path - path of the .txt file to be read
*/
int load_hash_file(hash* hash_table, const char* path);

/**
 * hash function that returns the key to a student with name 'name'.
 * It uses the name of the student as the hash
 * @param name name to hash
 * @return key of the given name on the hash
*/
unsigned int h1(const char* name);

/**
 * takes the output of the h1() function and then returns a position
 * on the hash to put the given student name using modulo
 * @param capacity hash capacity to use as modulo
 * @param name name of the student to hash
 * @return position on the vector of a hash_table 
*/
unsigned int h2(unsigned int capacity, const char* name);

/**
 * rotates the binary representation of a given 'value' by 'n_bits' counterclockwise
 * @param value the number to be rotated
 * @param n_bits number of bits to rotate 'value'
 * @return returns the corresponding unsigned int value of the rotation of 'n_bits' bits of 'value'  
*/
unsigned int rotl(unsigned int value, unsigned int n_bits);

/**
 * counts the number of lines a .txt has
 * @param path path to the file
 * @return number of lines of file inside 'path'
*/
unsigned int count_file_lines(const char* path);

#endif