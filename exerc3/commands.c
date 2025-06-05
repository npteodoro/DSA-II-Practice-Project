#include "commands.h"
#include "table.h"
#include "student.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int criarCommand(int argc, char *argv[]) {
    int result = 1;
    int initialSize;
    struct HashTable *newTable;
    
    if (argc >= 4) {
        // Parse initial size
        initialSize = atoi(argv[2]);
        
        // Create hash table
        newTable = createHashTable(initialSize);
        
        // Save empty table to file
        if (saveHashTableToFile(argv[3], newTable)) {
            printf("Success\n");
            result = 0;
        } else
            printf("Failure\n");
        
        // Clean up
        destroyHashTable(newTable);
    } 
    else
        printf("Failure\n");

    return result;
}

int inserirCommand(int argc, char *argv[]) {
    int result = 1;
    struct HashTable *insertTable;
    int insertCount;
    
    if (argc < 4)
        printf("Failure\n");
    else {
        // Load hash table from file
        insertTable = loadHashTableFromFile(argv[2]);
        
        // Insert students from string
        insertCount = insertStudentsFromString(insertTable, argv[3]);
        
        // Save table back to file
        if (insertCount > 0 && saveHashTableToFile(argv[2], insertTable)) {
            printf("Success\n");
            result = 0;
        } else {
            printf("insertcount == %d\n", insertCount);
            printf("Failure\n");
        }
        
        // Clean up
        destroyHashTable(insertTable);
    }
    
    return result;
}

int buscarCommand(int argc, char *argv[]) {
    int result = 1, i, searchCount;
    struct HashTable *searchTable = NULL;
    struct Student **searchResults = NULL;

    if (argc < 4)
        printf("Failure\n");
    else {
        searchTable = loadHashTableFromFile(argv[2]);
        searchResults = findStudentsByNUSP(searchTable, argv[3], &searchCount);
        for (i = 0; i < searchCount; i++)
            if (searchResults[i])
                printf("%u,%s,%s\n", searchResults[i]->nusp, searchResults[i]->name, searchResults[i]->course);
            else
                printf("Key not found\n");

        free(searchResults);
        destroyHashTable(searchTable);
        result = 0;
    }

    return result;
}

int removerCommand(int argc, char *argv[]) {
    int result = 1, deleteSuccess = 0;
    struct HashTable *deleteTable = NULL;
    char *nuspCopy = NULL, *token = NULL;
    unsigned int nusp;

    if (argc < 4) {
        printf("Failure\n");
        return result;
    }

    // Load the hash table from the file
    deleteTable = loadHashTableFromFile(argv[2]);
    if (!deleteTable) {
        printf("Failure\n");
        return result;
    }

    // Duplicate the input string to safely tokenize it
    nuspCopy = strdup(argv[3]);
    if (!nuspCopy) {
        printf("Failure\n");
        destroyHashTable(deleteTable);
        return result;
    }

    // Tokenize the input string to extract NUSPs
    token = strtok(nuspCopy, ",");
    while (token) {
        // Parse the NUSP and attempt to delete it
        if (sscanf(token, "%u", &nusp) == 1) {
            if (deleteStudent(deleteTable, nusp)) {
                deleteSuccess = 1;
            }
        }
        token = strtok(NULL, ",");
    }

    // Save the updated hash table back to the file if any deletions were successful
    if (deleteSuccess && saveHashTableToFile(argv[2], deleteTable)) {
        printf("Success\n");
        result = 0;
    } else {
        printf("Failure\n");
    }

    // Clean up
    free(nuspCopy);
    destroyHashTable(deleteTable);

    return result;
}