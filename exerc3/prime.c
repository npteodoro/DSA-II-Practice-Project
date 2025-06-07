#include "prime.h"
#include <stdio.h>

int isPrime(int number) {
    // Initialize flag: true if number > 1 (since 0 and 1 are not prime)
    int flagPrime = (number > 1);

    // Check all potential divisors from 2 to sqrt(number)
    for (int i = 2; i * i <= number; i++) {
        // If we find any divisor, number is not prime
        if (number % i == 0) {
            flagPrime = 0;
            break;  // Exit early once we know it's not prime
        }
    }

    return flagPrime;
}

int nthPrime(int position) {
    // Track how many primes we've found so far
    int count = 0;
    // Start checking from 1
    int prime = 1;

    // Continue until we find the nth prime
    while (count < position) {
        prime++;  // Check next number
        if (isPrime(prime))
            count++;  // Increment count if prime
    }

    return prime;  // Return the nth prime number
}

int nextPrime(int number) {
    // Keep incrementing until we find a prime
    while(isPrime(number) == 0)
        number++;
    return number;  // Return the found prime
}
