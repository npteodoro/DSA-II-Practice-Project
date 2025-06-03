#include "quick.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Swaps two integers by reference
 * @param a Pointer to first integer
 * @param b Pointer to second integer
 */
void swap_int(int* a, int *b) {
    int c = *a;  // Store value of first integer in temporary variable
    *a = *b;     // Copy second integer's value to first
    *b = c;      // Copy temporary value to second integer
}

/**
 * Quicksort implementation using a unique partitioning approach
 * This implementation partitions from right to left, placing smaller elements
 * at the end of the array section, then moves the pivot to its correct position
 * 
 * @param arr Array to be sorted
 * @param start Starting index of the section to sort
 * @param arr_size Size of the array (one past the last valid index)
 */
void quicksort(int* arr, int start, int arr_size) {
    // Base case: if start index >= array size, nothing to sort
    if(start >= arr_size) return;
    
    // Choose the first element as pivot
    int pivot_pos = start;
    int pivot = arr[pivot_pos];
    
    // 'smaller' tracks the boundary: all elements from 'smaller' to end are < pivot
    int smaller = arr_size;
    
    // Start from the rightmost element and work backwards
    int index = arr_size - 1;
    
    // Partition phase: move all elements smaller than pivot to the right side
    while(index > start) {
        if(arr[index] < pivot) {
            smaller--;  // Move the boundary left
            // Swap current element with the element at the boundary
            swap_int(&arr[smaller], &arr[index]);
        }
        index--;  // Move to the next element (going right to left)
    }
    
    // Calculate final position for pivot (just before the smaller elements)
    pivot_pos = smaller - 1;
    
    // Move pivot from start position to its correct sorted position
    swap_int(&arr[start], &arr[pivot_pos]);
    
    // Recursively sort the left partition (elements smaller than pivot)
    quicksort(arr, start, pivot_pos);
    
    // Recursively sort the right partition (elements greater than or equal to pivot)
    quicksort(arr, pivot_pos+1, arr_size);