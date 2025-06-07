#include "student.h"
#include "probing.h"
#include "prime.h"
#include "hash.h"
#include "table.h"
#include <stdlib.h>
#include <stdio.h>

struct HashTable* createHashTable(int size) {
    int primeSize = nextPrime(size);
    struct HashTable *table = (struct HashTable*)malloc(sizeof(struct HashTable));
    table->entries = (struct HashEntry*)calloc(primeSize, sizeof(struct HashEntry));
    table->size = primeSize;
    table->count = 0;
    table->loadFactor = 0.0;
    return table;
}

void resizeHashTable(struct HashTable *table) {
    int newSize = nextPrime(table->size * 2);
    struct HashEntry *newEntries = (struct HashEntry*)calloc(newSize, sizeof(struct HashEntry));

    for (int i = 0; i < table->size; i++) {
        if (table->entries[i].nusp != 0) {
            unsigned int newIndex = hash1(table->entries[i].nusp, newSize);
            unsigned int probe = 0, step = 1;

            while (newEntries[newIndex].nusp != 0) {
                probe++;
                newIndex = getNextProbePosition(hash1(table->entries[i].nusp, newSize), probe, newSize, 1, step);
            }

            newEntries[newIndex] = table->entries[i];
            newEntries[newIndex].probingType = 1;
        }
    }

    free(table->entries);
    table->entries = newEntries;
    table->size = newSize;
    table->loadFactor = (float)table->count / table->size;
}

void destroyHashTable(struct HashTable *table) {
    // Free all student records and their data
    for (int i = 0; i < table->size; i++) {
        if (table->entries[i].nusp != 0)
            freeStudent(table->entries[i].student);
    }

    // Free table structure and entries array
    free(table->entries);
    free(table);
}