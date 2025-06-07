#ifndef TRANSFORM_H
#define TRANSFORM_H

/**
 * @brief Transforms a key by multiplying each digit+1 by nth prime
 * @param key The unsigned integer to transform
 * @return The transformed value after arithmetic operations
 */
unsigned int digitArithmeticTransform(unsigned int key);

/**
 * @brief Swaps the 16 most significant bits with the 16 least significant bits
 * @param key The unsigned integer to transform
 * @return The transformed value after bit swapping
 */
unsigned int bitShiftTransform(unsigned int key);

/**
 * @brief Applies XOR operations between bits at different positions
 * @param key The unsigned integer to transform
 * @return The transformed value after XOR operations
 */
unsigned int bitXorTransform(unsigned int key);

#endif // TRANSFORM_H