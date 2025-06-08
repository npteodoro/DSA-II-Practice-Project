#include <stdio.h>
#include <stdlib.h>
#include "hanoi.h"
#include "quick.h"
#include "heap.h"

void runDefaultTest(void) {
    // Define the number of disks and their weights for two test cases
    int n1 = 3, n2 = 4; // Number of disks for each test case
    int weights1[] = {8, 1, 5}; // Weights of disks for the first test case
    int weights2[] = {3, 9, 2, 4}; // Weights of disks for the second test case

    // Sort the weights array for the first test case using quicksort
    quicksort(weights1, 0, n1);

    // Sort the weights array for the second test case using heapsort
    heapsort(weights2, n2);

    // Initialize variables to track total weight moved and move count
    int total_weight1 = 0, total_weight2 = 0; // Total weight moved for tests
    int move_count1 = 0, move_count2 = 0; // Total number of moves for tests

    // First test case: Solve Tower of Hanoi with 3 disks
    printf("First test with 3 disks:\n");
    hanoi(n1, 'A', 'C', 'B', n1, weights1, &total_weight1, &move_count1);
    printf("Total moves: %d\n", move_count1); // Print the total moves
    printf("Total weight moved: %d\n", total_weight1); // Print total weight

    // Second test case: Solve Tower of Hanoi with 4 disks
    printf("\nSecond test with 4 disks:\n");
    hanoi(n2, 'A', 'C', 'B', n2, weights2, &total_weight2, &move_count2);
    printf("Total moves: %d\n", move_count2); // Print the total  moves
    printf("Total weight moved: %d\n", total_weight2); // Print total weight

}
