#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hanoi.h"
#include "quick.h"
#include "heap.h"
#include "test.h"


int main(int argc, char *argv[]) {
    // Check if no arguments are provided
    if (argc < 2) {
        // If no arguments, run the default test cases
        runDefaultTest();
        return 0;
    }

    // Calculate the number of weights provided as arguments
    int size = argc - 2;

    // Initialize the weights array
    int weights[size];
    for (int i = 0; i < size; i++)
        // Convert command-line arguments to integers 
        // and store in weights array
        weights[i] = atoi(argv[i + 2]);

    // Variables to track total weight moved and total number of moves
    int total_weight = 0;
    int move_count = 0;

    // Check which sorting algorithm to use
    if (strcmp(argv[1], "quick") == 0)
        // Use quicksort to sort the weights in descending order
        quicksort(weights, 0, size);
    else if (strcmp(argv[1], "heap") == 0)
        // Use heapsort to sort the weights in descending order
        heapsort(weights, size);

    // Solve the Tower of Hanoi problem with the sorted weights
    hanoi(size, 'A', 'C', 'B', size, weights, &total_weight, &move_count);

    // Print the total number of moves and the total weight moved
    printf("Total moves made: %d\n", move_count);
    printf("Total weight moved: %d\n", total_weight);

    return 0;
}


