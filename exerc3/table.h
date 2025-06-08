#ifndef TABLE_H
#define TABLE_H

struct Student; // Forward declaration of Student structure

/**
 * @brief Entry in the hash table containing a student record.
 */
struct HashEntry {
    unsigned int nusp;       /**< Hash student ID number (NUSP). */
    struct Student *student; /**< Pointer to student data. */
    int probingType;         /**< Type of probing used (0 for quadratic, 1 for double hashing). */
};

/**
 * @brief Hash table data structure.
 */
struct HashTable {
    struct HashEntry *entries; /**< Array of hash entries. */
    int size;                  /**< Size of the hash table (number of slots). */
    int count;                 /**< Number of occupied slots. */
    float loadFactor;          /**< Current load factor (count/size). */
};

/**
 * @brief Creates a new hash table with specified initial size.
 * @param size Desired size (will be adjusted to next prime number).
 * @return Pointer to the newly created hash table.
 */
struct HashTable* createHashTable(int size);

/**
 * @brief Resizes the hash table when the load factor exceeds the threshold.
 * @param table Pointer to the hash table to resize.
 */
void resizeHashTable(struct HashTable *table);

/**
 * @brief Frees all memory allocated for the hash table and its entries.
 * @param table Pointer to the hash table to destroy.
 */
void destroyHashTable(struct HashTable *table);

#endif // TABLE_H