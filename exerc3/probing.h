#ifndef PROBING_H
#define PROBING_H

#include "table.h"

/**
 * @brief Calculates the next position in the hash table based on the probing strategy.
 * @param startIndex The initial index calculated by the hash function.
 * @param i The current probe iteration.
 * @param tableSize The size of the hash table.
 * @param probingType The probing strategy (1 for quadratic, 2 for double hashing).
 * @param step The step size for double hashing.
 * @return The next probe position.
 */
unsigned int getNextProbePosition(unsigned int startIndex, unsigned int i,
                                  unsigned int tableSize, int probingType,
                                  unsigned int step);

/**
 * @brief Finds the index of an entry in the hash table using the specified probing method.
 * @param table Pointer to the hash table.
 * @param nusp The key to search for.
 * @param probingType The probing strategy (1 for quadratic, 2 for double hashing).
 * @param outIndex Pointer to store the found index (if any).
 * @return 1 if the entry is found, 0 otherwise.
 */
int findEntryIndex(struct HashTable *table, unsigned int nusp,
                   int probingType, unsigned int *outIndex);

/**
 * @brief Finds a student record using a specific probing method.
 * @param table Pointer to the hash table.
 * @param nusp The key to search for.
 * @param probingType The probing strategy (1 for quadratic, 2 for double hashing).
 * @return Pointer to the found student or NULL if not found.
 */
struct Student* findWithProbing(struct HashTable *table, unsigned int nusp, int probingType);

/**
 * @brief Attempts to insert a student into the hash table using specified probing.
 * @param table Pointer to the hash table.
 * @param nusp Student's unique ID number.
 * @param name Student's name.
 * @param course Student's course.
 * @param startIndex The initial index calculated by the hash function.
 * @param probingType The probing strategy (1 for quadratic, 2 for double hashing).
 * @return 1 if insertion is successful, 0 otherwise.
 */
int insertWithProbing(struct HashTable *table, unsigned int nusp, const char *name,
                      const char *course, unsigned int startIndex, int probingType);

/**
 * @brief Deletes a student from the hash table using specified probing method.
 * @param table Pointer to the hash table.
 * @param nusp Student's unique ID to delete.
 * @param probingType The probing strategy (1 for quadratic, 2 for double hashing).
 * @return 1 if deletion is successful, 0 otherwise.
 */
int deleteWithProbing(struct HashTable *table, unsigned int nusp, int probingType);

#endif // PROBING_H