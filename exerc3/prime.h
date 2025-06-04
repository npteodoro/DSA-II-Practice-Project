#ifndef PRIME_H_
#define PRIME_H_

/**
 * @brief Determines if a number is prime
 * @param number The integer to check for primality
 * @return 1 if the number is prime, 0 otherwise
 */
int isPrime(int number);

/**
 * @brief Finds the nth prime number
 * @param position The position of the prime to find (1st, 2nd, etc.)
 * @return The nth prime number
 */
int nthPrime(int position);

/**
 * @brief Finds the next prime number greater than or equal to the given number
 * @param number The starting value for the search
 * @return The next prime number after the input
 */
int nextPrime(int number);

#endif // PRIME_H_
