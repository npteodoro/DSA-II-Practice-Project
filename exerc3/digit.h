#ifndef DIGIT_H
#define DIGIT_H

/**
 * @brief Finds the highest power of 10 less than or equal to a number
 * @param number The number to analyze
 * @return The highest power of 10 that is <= the number
 */
unsigned int digitHighestPow10(unsigned int number);

/**
 * @brief Extracts the most significant digit from a number
 * @param number Pointer to the number being processed
 * @param powerOf10 Pointer to the current power of 10 (will be updated)
 * @return The extracted digit
 */
unsigned int digitExtract(unsigned int *number, unsigned int *powerOf10);

#endif // DIGIT_H