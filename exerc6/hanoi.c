#include <stdio.h>

void hanoi(int n, char from, char to, char aux, int total_discs,
           int weights[], int *total_weight, int *move_count) {
    // Base case: If there are no disks to move, return
    if (n > 0) {
        // Recursive call: Move the top n-1 disks from the "from" tower to the
        // "aux" tower using the "to" tower as a temporary placeholder
        hanoi(n - 1, from, aux, to, total_discs, weights, total_weight,
              move_count);
        
        // Calculate the index in the weights array
        int idx = total_discs - n;

        // Print the details of the move
        printf("Move disc index %d from %c to %c (weight = %d)\n", idx, from,
               to, weights[idx]);

        // Update the total weight moved
        *total_weight += weights[idx];

        // Increment the move count to track the total number of moves
        *move_count += 1;

        // Recursive call: Move the n-1 disks from the "aux" tower to the "to"
        // tower using the "from" tower as a temporary placeholder
        hanoi(n - 1, aux, to, from, total_discs, weights, total_weight,
              move_count);
    }
}

