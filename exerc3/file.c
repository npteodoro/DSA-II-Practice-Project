#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to count items in a delimited string
static int countDelimitedItems(const char *str, char delimiter) {
    int count = 1; // Start with 1 for the last item
    while (*str) {
        if (*str++ == delimiter)
            count++;
        str++;
    }
    return count;
}

int saveHashTableToFile(const char *filename, struct HashTable *table) {
    FILE *file = fopen(filename, "w");
    int i, entriesWritten = 0;
    
    // Write table size as first line
    fprintf(file, "%d\n", table->size);
    
    // Write each non-empty entry
    for (i = 0; i < table->size; i++) {
        if (table->entries[i].nusp != 0) {
            // Get student record from this entry
            struct Student *student = table->entries[i].student;
            
            // Write in format: nusp;name;course with semicolons
            fprintf(file, "%u;%s;%s\n", 
                    student->nusp,
                    student->name,
                    student->course);
            
            entriesWritten++;
        }
    }
    
    fclose(file);
    return 1;
}

struct HashTable *loadHashTableFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    struct HashTable *table = NULL;
    char line[256];
    int tableSize = 0;
    unsigned int nusp;
    char name[128], course[128];
    
    // Read table size from first line
    if (fgets(line, sizeof(line), file)) {
        // Parse table size
        sscanf(line, "%d", &tableSize);
        
        // Create hash table with the specified size
        table = createHashTable(tableSize);
        
        // Read and insert each entry
        while (fgets(line, sizeof(line), file)) {
            // Remove trailing newline if present
            if (line[strlen(line) - 1] == '\n') 
                line[strlen(line) - 1] = '\0';

            // Parse line using semicolons as separators
            if (sscanf(line, "%u;%127[^;];%127s", &nusp, name, course) == 3) {
                // Insert student into the hash table
                insertStudent(table, nusp, name, course);
            }
        }
    }
    
    fclose(file);
    return table;
}

int insertStudentsFromString(struct HashTable *table, const char *inputString) {
    char *copy = strdup(inputString);
    char *pos = copy;
    int count = 0;
    unsigned int nusp;
    char name[128], course[128];
    
    // Process the comma-separated list, reading 3 values at a time
    while (*pos) {
        // Try to parse three values for each student
        if (sscanf(pos, "%u,%127[^,],%127[^,]", &nusp, name, course) == 3) {
            // Insert student into the hash table
            if (insertStudent(table, nusp, name, course))
                count++;
            
            // Skip the three values we just processed
            int i;
            char *nextPos = pos;
            
            // Skip to after the third comma (or end of string)
            for (i = 0; i < 3 && *nextPos; i++) {
                // Find next comma
                nextPos = strchr(nextPos, ',');
                if (!nextPos)
                    break;
                nextPos++; // Move past the comma
            }
            
            // If we found all three values, update position
            if (i == 3)
                pos = nextPos;
            else
                break; // Not enough values left
        } else {
            // Couldn't parse 3 values, try to move to next position
            char *nextComma = strchr(pos, ',');
            if (nextComma)
                pos = nextComma + 1;
            else
                break;
        }
    }
    
    free(copy);
    return count;
}

struct Student **findStudentsByNUSP(struct HashTable *table, 
                                  const char *nuspString, int *count) {
    char *copy;
    char *token = NULL;
    int numNusps;
    int i = 0;
    struct Student **results;
    unsigned int nusp;
    
    copy = strdup(nuspString);
    numNusps = countDelimitedItems(nuspString, ',');
    results = malloc(numNusps * sizeof(struct Student *));
    
    // Find each student by NUSP
    token = strtok(copy, ",");
    while (token && i < numNusps) {
        // Skip whitespace
        while (*token == ' ' || *token == '\t')
            token++;
        
        if (sscanf(token, "%u", &nusp) == 1)
            results[i++] = searchStudent(table, nusp);
        
        token = strtok(NULL, ",");
    }
    
    *count = i;
    free(copy);
    return results;
}
