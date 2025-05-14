#ifndef EXERC2_H
#define EXERC2_H

/**
 * Structure to represent a range of indices
 */
typedef struct {
    int start;
    int end;
} Range;

/**
 * Performs a modified binary search to find the first and last occurrence of multiple values
 * in a sorted array.
 * 
 * @param arr The sorted array to search in
 * @param size The size of the array
 * @param values The array of values to search for
 * @param num_values The number of values to search for
 * @param is_ascending Flag indicating if the array is sorted in ascending order
 * @return An array of Range structures containing the first and last indices of each value
 */
Range* modified_binary_search(int* arr, int size, int* values, int num_values, int is_ascending);

/**
 * Helper function to find the first occurrence of a value in a sorted array
 * 
 * @param arr The sorted array to search in
 * @param low The lower bound index
 * @param high The upper bound index
 * @param value The value to search for
 * @param is_ascending Flag indicating if the array is sorted in ascending order
 * @return The index of the first occurrence or -1 if not found
 */
int find_first_occurrence(int* arr, int low, int high, int value, int is_ascending);

/**
 * Helper function to find the last occurrence of a value in a sorted array
 * 
 * @param arr The sorted array to search in
 * @param low The lower bound index
 * @param high The upper bound index
 * @param value The value to search for
 * @param is_ascending Flag indicating if the array is sorted in ascending order
 * @return The index of the last occurrence or -1 if not found
 */
int find_last_occurrence(int* arr, int low, int high, int value, int is_ascending);

#endif /* EXERC2_H */