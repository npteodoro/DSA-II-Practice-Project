#include "exerc2.h"
#include <stdlib.h>

/**
 * Helper function to check if a value matches at a given index based on sorting order
 */
int is_match(int* arr, int index, int value, int is_ascending) {
    return arr[index] == value;
}

/**
 * Helper function to check if a value is in the correct half based on sorting order
 */
int is_in_first_half(int* arr, int mid, int value, int is_ascending) {
    if (is_ascending) {
        return value <= arr[mid];
    } else {
        return value >= arr[mid];
    }
}

int find_first_occurrence(int* arr, int low, int high, int value, int is_ascending) {
    // Base case: element not found
    if (low > high) {
        return -1;
    }
    
    int mid = low + (high - low) / 2;
    
    // If we found a match, check if it's the first occurrence
    if (is_match(arr, mid, value, is_ascending)) {
        // If we're at the leftmost element or the previous element is different,
        // we found the first occurrence
        if (mid == 0 || !is_match(arr, mid - 1, value, is_ascending)) {
            return mid;
        }
        // Otherwise, search in the left half
        return find_first_occurrence(arr, low, mid - 1, value, is_ascending);
    }
    
    // If value should be in first half (left half for ascending, right half for descending)
    if ((is_ascending && arr[mid] > value) || (!is_ascending && arr[mid] < value)) {
        return find_first_occurrence(arr, low, mid - 1, value, is_ascending);
    } else {
        // Search in the second half
        return find_first_occurrence(arr, mid + 1, high, value, is_ascending);
    }
}

int find_last_occurrence(int* arr, int low, int high, int value, int is_ascending) {
    // Base case: element not found
    if (low > high) {
        return -1;
    }
    
    int mid = low + (high - low) / 2;
    
    // If we found a match, check if it's the last occurrence
    if (is_match(arr, mid, value, is_ascending)) {
        // If we're at the rightmost element or the next element is different,
        // we found the last occurrence
        if (mid == high || !is_match(arr, mid + 1, value, is_ascending)) {
            return mid;
        }
        // Otherwise, search in the right half
        return find_last_occurrence(arr, mid + 1, high, value, is_ascending);
    }
    
    // If value should be in first half (left half for ascending, right half for descending)
    if ((is_ascending && arr[mid] > value) || (!is_ascending && arr[mid] < value)) {
        return find_last_occurrence(arr, low, mid - 1, value, is_ascending);
    } else {
        // Search in the second half
        return find_last_occurrence(arr, mid + 1, high, value, is_ascending);
    }
}

Range* modified_binary_search(int* arr, int size, int* values, int num_values, int is_ascending) {
    Range* results = (Range*)malloc(num_values * sizeof(Range));
    
    if (results == NULL) {
        return NULL; // Memory allocation failed
    }
    
    for (int i = 0; i < num_values; i++) {
        int first = find_first_occurrence(arr, 0, size - 1, values[i], is_ascending);
        int last = -1;
        
        // Only search for last occurrence if we found a first occurrence
        if (first != -1) {
            last = find_last_occurrence(arr, 0, size - 1, values[i], is_ascending);
        }
        
        results[i].start = first;
        results[i].end = last;
    }
    
    return results;
}