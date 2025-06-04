#ifndef HASH_H
#define HASH_H

/**
 * @brief Primary hash function used for initial index calculation
 * @param key The key to hash (e.g., student NUSP)
 * @param size The size of the hash table
 * @return The calculated hash index
 */
unsigned int hash1(unsigned int key, int size);

/**
 * @brief Secondary hash function used when load factor exceeds 0.7
 * @param key The key to hash (e.g., student NUSP)
 * @param size The size of the hash table
 * @return The step size for double hashing probing
 * @note This function is used in the double hashing collision resolution
 *       strategy when the table load factor is greater than 0.7
 */
unsigned int hash2(unsigned int key, int size);

#endif // HASH_H