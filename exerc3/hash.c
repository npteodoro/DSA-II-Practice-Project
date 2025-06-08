#include "transform.h"
#include "hash.h"

unsigned int hash1(unsigned int key, int size) {
    // Step 1: Apply digit arithmetic transformation (multiply each digit+1 by nth prime)
    key = digitArithmeticTransform(key);
    
    // Step 2: Swap the 16 most significant bits with the 16 least significant bits
    key = bitShiftTransform(key);
    
    // Step 3: Apply XOR operations between bits of different positions
    key = bitXorTransform(key);
    
    // Step 4: Compute final hash value by taking modulo of table size
    return key % size;
}

unsigned int hash2(unsigned int key, int size) {
    // Return value between 1 and (size-1) to ensure the step size:
    // 1) Is never zero (adding 1 ensures this)
    // 2) Is relatively prime to table size when size is prime
    return 1 + (key % (size - 1));
}