#include "prime.h"
#include "transform.h"
#include "digit.h"

unsigned int digitArithmeticTransform(unsigned int key) {
    // Initialize variables for processing
    unsigned int digit, result = 0;
    int position = 1;
    // Get the highest power of 10 for digit extraction
    unsigned int highestPowerOf10 = digitHighestPow10(key);

    while (key > 0) {
        // Extract the next digit from the key
        digit = digitExtract(&key, &highestPowerOf10);
        // Add 1 to the digit and multiply by the nth prime number
        digit = (digit + 1) * nthPrime(position);
        // Add the transformed digit to the result
        result += digit;
        // Move to the next position for the next digit
        position++;
    }

    return result;
}

unsigned int bitShiftTransform(unsigned int key) {
    // Extract the most significant 16 bits
    unsigned int leftSide;
    // Extract the least significant 16 bits and shift to the left
    unsigned int rightSide;
    // Store the final transformed result
    unsigned int result;

    // Get the 16 most significant bits and shift them to the right
    // This effectively clears the most significant bits
    // and keeps the least significant bits
    leftSide = (key >> 16);
    // Shift the 16 least significant bits to the left
    // This effectively moves them to the most significant position
    // and clears the least significant bits
    rightSide = (key & 0xFFFF) << 16;
    // Combine both parts with bitwise OR
    result = leftSide | rightSide;

    return result;
}

static unsigned int selectBit(unsigned int digit, unsigned int toggle) {
    // Store the selected bit based on toggle value
    unsigned int bit;

    // If toggle is 0, get the most significant bit (position 3)
    // If toggle is 1, get the least significant bit (position 0)
    bit = toggle == 0 ? (digit >> 3) & 1 : digit & 1;

    return bit;
}

unsigned int bitXorTransform(unsigned int key) {
    // Initialize variables for the transformation
    unsigned int result = 0, xorBit = 0, toggle = 0, digit, bit;
    // Get the highest power of 10 for digit extraction
    unsigned int highestPowerOf10 = digitHighestPow10(key);

    while (key > 0) {
        // Extract the next digit from the key
        digit = digitExtract(&key, &highestPowerOf10);
        // Get either the first or last bit of the digit based on toggle
        bit = selectBit(digit, toggle);
        // XOR the selected bit with the running XOR result
        xorBit ^= bit;
        // Shift the result left and add the new XOR bit
        result = (result << 1) | xorBit;
        // Toggle between first and last bit for next iteration
        toggle = !toggle;
    }

    return result;
}