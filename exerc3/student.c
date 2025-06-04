#include "student.h"
#include "probing.h"
#include "hash.h"
#include "table.h"
#include <stdlib.h>
#include <string.h>

void freeStudent(struct Student *student) {
    free(student->name);
    free(student->course);
    free(student);
}

struct Student* createStudent(unsigned int nusp, const char *name, const char *course) {
    struct Student *student = (struct Student*)malloc(sizeof(struct Student));
    student->nusp = nusp;
    student->name = strdup(name);
    student->course = strdup(course);
    return student;
}

int insertStudent(struct HashTable *table, unsigned int nusp, const char *name, const char *course) {
    // Resize if load factor too high
    if (table->loadFactor > 0.9)
        resizeHashTable(table);

    // Determine insertion parameters
    unsigned int index = hash1(nusp, table->size);
    int probingType = (table->loadFactor <= 0.7) ? 1 : 2; // 1=quadratic, 2=double hashing

    // Attempt insertion with appropriate probing
    int flagInserted = insertWithProbing(table, nusp, name, course, index, probingType);

    // Update table metrics if insertion successful
    if (flagInserted) {
        table->count++;
        table->loadFactor = (float)table->count / table->size;
        return 1;
    }

    return 0;
}

struct Student* searchStudent(struct HashTable *table, unsigned int nusp) {
    // Try quadratic probing first
    struct Student* result = findWithProbing(table, nusp, 1);

    // If not found, try double hashing
    if (!result)
        result = findWithProbing(table, nusp, 2);

    return result;
}

int deleteStudent(struct HashTable *table, unsigned int nusp) {
    // Try quadratic probing first
    int deleted = deleteWithProbing(table, nusp, 1);

    // If not found, try double hashing
    if (!deleted)
        deleted = deleteWithProbing(table, nusp, 2);
    
    table->count -= deleted; // Decrease count only if deletion was successful
    table->loadFactor = (float)table->count / table->size;

    return deleted;
}