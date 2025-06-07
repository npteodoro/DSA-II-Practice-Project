#include "probing.h"
#include "student.h"
#include "hash.h"
#include <stdlib.h>

unsigned int getNextProbePosition(unsigned int startIndex, unsigned int i,
                                  unsigned int tableSize, int probingType,
                                  unsigned int step) {
    if (probingType == 1) // Quadratic probing
        return (startIndex + i * i) % tableSize;
    else // Double hashing
        return (startIndex + i * step) % tableSize;
}

int findEntryIndex(struct HashTable *table, unsigned int nusp,
                   int probingType, unsigned int *outIndex) {
    unsigned int index = hash1(nusp, table->size);
    unsigned int i = 0, maxProbes = table->size;
    unsigned int probeIndex = index;
    unsigned int step = (probingType == 2) ? hash2(nusp, table->size) : 1;
    int found = 0;

    while (i < maxProbes && !found) {
        if (table->entries[probeIndex].nusp == 0)
            break;

        if (table->entries[probeIndex].nusp == nusp) {
            found = 1;
            if (outIndex)
                *outIndex = probeIndex;
        } else {
            i++;
            probeIndex = getNextProbePosition(index, i, table->size, probingType, step);
        }
    }

    return found;
}

struct Student* findWithProbing(struct HashTable *table, unsigned int nusp, int probingType) {
    unsigned int index;
    struct Student* result = NULL;

    if (findEntryIndex(table, nusp, probingType, &index)) {
        result = table->entries[index].student;
    }

    return result;
}

int insertWithProbing(struct HashTable *table, unsigned int nusp, const char *name,
                      const char *course, unsigned int startIndex, int probingType) {
    unsigned int index = startIndex;
    unsigned int i = 0, maxProbes = table->size;
    unsigned int step = (probingType == 2) ? hash2(nusp, table->size) : 1;
    struct Student *newStudent;
    int inserted = 0;

    while (i < maxProbes && !inserted) {
        if (table->entries[index].nusp == 0 || table->entries[index].nusp == nusp) {
            if (table->entries[index].nusp == nusp) {
                freeStudent(table->entries[index].student);
                table->count--;
            }

            newStudent = createStudent(nusp, name, course);
            table->entries[index].nusp = nusp;
            table->entries[index].student = newStudent;
            table->entries[index].probingType = probingType;
            inserted = 1;
        }

        if (!inserted) {
            i++;
            index = getNextProbePosition(startIndex, i, table->size, probingType, step);
        }
    }

    return inserted;
}

int deleteWithProbing(struct HashTable *table, unsigned int nusp, int probingType) {
    unsigned int index;
    int deleted = 0;

    if (findEntryIndex(table, nusp, probingType, &index)) {
        freeStudent(table->entries[index].student);
        table->entries[index].nusp = 0;
        table->entries[index].student = NULL;
        table->count--;
        table->loadFactor = (float)table->count / table->size;
        deleted = 1;
    }

    return deleted;
}