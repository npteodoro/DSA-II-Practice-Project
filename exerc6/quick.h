#ifndef QUICK_H
#define QUICK_H

/**
 * Quicksort implementation using a unique partitioning approach
 * This implementation partitions from right to left, placing smaller elements
 * at the end of the array section, then moves the pivot to its correct position
 * 
 * @param arr Array to be sorted
 * @param start Starting index of the section to sort
 * @param arr_size Size of the array (one past the last valid index)
 */
void quicksort(int*, int, int);

#endif