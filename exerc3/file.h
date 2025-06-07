#ifndef FILE_H
#define FILE_H

#include "student.h"
#include "table.h"

/**
 * @brief Saves the hash table content to a text file.
 * 
 * This function writes the contents of the hash table to a specified file
 * in a human-readable format.
 * 
 * @param filename The name of the file to save the hash table to.
 * @param table Pointer to the hash table to save.
 * @return 1 on success, 0 on failure.
 */
int saveHashTableToFile(const char *filename, struct HashTable *table);

/**
 * @brief Loads a hash table from a text file.
 * 
 * This function reads the contents of a file and reconstructs the hash table.
 * 
 * @param filename The name of the file to load the hash table from.
 * @return Pointer to the loaded hash table, or NULL on failure.
 */
struct HashTable *loadHashTableFromFile(const char *filename);

/**
 * @brief Inserts students into the hash table from a formatted string.
 * 
 * The input string must follow the format:
 * "nusp1,name1,course1;nusp2,name2,course2;..."
 * 
 * @param table Pointer to the hash table.
 * @param inputString The formatted string containing student data.
 * @return The number of students successfully inserted.
 */
int insertStudentsFromString(struct HashTable *table, const char *inputString);

/**
 * @brief Finds students by their NUSPs from a formatted string.
 * 
 * The input string must follow the format:
 * "nusp1,nusp2,nusp3,..."
 * 
 * @param table Pointer to the hash table.
 * @param nuspString The formatted string containing NUSPs to search for.
 * @param count Pointer to an integer to store the number of students found.
 * @return An array of pointers to student records (NULL for not found).
 *         The caller is responsible for freeing the returned array (but not
 *         the student records themselves).
 */
struct Student **findStudentsByNUSP(struct HashTable *table, 
                                    const char *nuspString, int *count);

/**
 * @brief Parses a command string and determines the action type.
 * 
 * This function interprets a command string and determines the type of
 * operation to perform (e.g., insertion, search, or deletion).
 * 
 * @param commandString The command string to parse.
 * @return 1 for insertion, 2 for search, 3 for deletion, 0 for invalid.
 */
int parseCommandType(const char *commandString);

#endif /* FILE_H */