#include "digit.h"

unsigned int digitHighestPow10(unsigned int number) {
    // Start with 1 (10^0)
    unsigned int highestPower = 1;

    // Divide by 10 repeatedly until we've identified the highest power of 10
    while (number >= 10) {
        number /= 10;  // Move to next digit
        highestPower *= 10;  // Increase our power of 10
    }
    
    return highestPower;  // Return the highest power of 10 that fits in the number
}

unsigned int digitExtract(unsigned int *number, unsigned int *powerOf10) {
    // Extract the most significant digit using integer division
    unsigned int digit = *number / *powerOf10;
    
    // Remove the extracted digit from the number
    *number %= *powerOf10;
    
    // Reduce the power of 10 to prepare for next digit extraction
    *powerOf10 /= 10;
    
    return digit;  // Return the extracted digit
}