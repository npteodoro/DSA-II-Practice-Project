#ifndef HANOI_H
#define HANOI_H

/**
 * @brief Solves the Tower of Hanoi problem with additional weight tracking.
 * 
 * This function recursively solves the Tower of Hanoi problem while tracking
 * the total weight moved and the number of moves. It also prints the details
 * of each move, including the disk index, source tower, target tower, and
 * the weight of the disk being moved.
 * 
 * @param n The number of disks to move.
 * @param from The source tower (e.g., 'A').
 * @param to The target tower (e.g., 'C').
 * @param aux The auxiliary tower (e.g., 'B').
 * @param total_discs The total number of disks in the problem (used for
 *                    indexing).
 * @param weights An array of integers representing the weights of the disks.
 *                The array must be sorted in ascending order before calling
 *                this function.
 * @param total_weight Pointer to an integer that accumulates the total weight
 *                     moved.
 * @param move_count Pointer to an integer that tracks the total number of
 *                   moves.
 */
void hanoi(int n, char from, char to, char aux, int total_discs,
           int weights[], int *total_weight, int *move_count);

#endif // HANOI_H
