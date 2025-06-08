#include "test.h"
#include "table.h"
#include "student.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>

void runDefaultTest(void) {
    struct HashTable *table;
    struct Student **students;
    int count, i;

    // Step 1: Create a table of size 11
    printf("Creating hash table of size 11...\n");
    table = createHashTable(11);

    // Step 2: Insert 5 sample students
    printf("Inserting 5 sample students...\n");
    insertStudent(table, 420, "Pedro", "eng-comp");
    insertStudent(table, 13, "Kaue", "eng-comp");
    insertStudent(table, 24, "Luis", "eng-comp");
    insertStudent(table, 777, "Mateus", "eng-comp");
    insertStudent(table, 69, "Marco", "eng-comp");

    // Step 3: Remove 2 students
    printf("Removing 2 students...\n");
    deleteStudent(table, 13); // Kaue
    deleteStudent(table, 777); // Mateus

    // Step 4: Save to hash.txt
    printf("Saving to hash.txt...\n");
    saveHashTableToFile("hash.txt", table);

    // Free the table
    destroyHashTable(table);

    // Step 5: Reload hash.txt and search for 2 existing and 1 non-existent NUSP
    printf("Reloading from hash.txt and searching...\n");
    table = loadHashTableFromFile("hash.txt");

    // Search for students (2 existing, 1 non-existent)
    students = findStudentsByNUSP(table, "420,24,1", &count);
    // Display results
    for (i = 0; i < count; i++) {
        if (students[i])
            printf("Found student: NUSP=%u, Name=%s, Course=%s\n",
                   students[i]->nusp, students[i]->name, students[i]->course);
        else
            printf("Key not found\n");
    }
    // Clean up
    free(students);
    destroyHashTable(table);
}
