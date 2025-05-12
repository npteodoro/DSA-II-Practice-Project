#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exerc2.h"

/*
This code is in English 'cause Pedro utterly said so
*/

/**
 * Parse a string of comma-separated integers into an array
 */
int* parse_int_array(const char* str, int* size) {
    // Count the number of commas to determine array size
    int count = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',') {
            count++;
        }
    }
    
    *size = count;
    int* array = (int*)malloc(*size * sizeof(int));
    if (array == NULL) {
        return NULL;
    }
    
    // Copy the string to avoid modifying the original
    char* str_copy = strdup(str);
    if (str_copy == NULL) {
        free(array);
        return NULL;
    }
    
    // Parse the string into integers
    char* token = strtok(str_copy, ",");
    int index = 0;
    
    while (token != NULL && index < *size) {
        array[index++] = atoi(token);
        token = strtok(NULL, ",");
    }
    
    free(str_copy);
    return array;
}

/**
 * Print the search results in the format (start,end) for each value
 */
void print_results(Range* results, int num_values, int* values) {
    for (int i = 0; i < num_values; i++) {
        printf("%d: (%d,%d)", values[i], results[i].start, results[i].end);
        if (i < num_values - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

/**
 * Run a test with the given parameters
 */
void run_test(int* arr, int arr_size, int* values, int values_size, int is_ascending) {
    // Print the array
    printf("Array: [");
    for (int i = 0; i < arr_size; i++) {
        printf("%d", arr[i]);
        if (i < arr_size - 1) {
            printf(", ");
        }
    }
    printf("] (sorted in %s order)\n", is_ascending ? "ascending" : "descending");
    
    // Print the values to search
    printf("Searched values: ");
    for (int i = 0; i < values_size; i++) {
        printf("%d", values[i]);
        if (i < values_size - 1) {
            printf(", ");
        }
    }
    printf("\n");
    
    // Perform the search
    Range* results = modified_binary_search(arr, arr_size, values, values_size, is_ascending);
    
    // Print the results
    printf("Results: ");
    print_results(results, values_size, values);
    printf("\n");
    
    free(results);
}

void run_default_tests() {
    printf("Running default tests:\n\n");
    
    // Test 1: Ascending order
    int test1_arr[] = {1, 2, 3, 3, 3, 4, 5, 6};
    int test1_values[] = {3, 7};
    run_test(test1_arr, 8, test1_values, 2, 1);
    
    // Test 2: Descending order
    int test2_arr[] = {8, 8, 6, 5, 5, 5, 3, 2, 1};
    int test2_values[] = {5, 8, 7};
    run_test(test2_arr, 9, test2_values, 3, 0);
}

int main(int argc, char* argv[]) {
    // If no arguments are provided, run default tests
    if (argc < 4) {
        run_default_tests();
        return 0;
    }
    
    // Parse the array
    int arr_size;
    int* arr = parse_int_array(argv[1], &arr_size);
    if (arr == NULL) {
        printf("Failed to parse array\n");
        return 1;
    }
    
    // Parse the order
    int is_ascending;
    if (strcmp(argv[2], "asc") == 0) {
        is_ascending = 1;
    } else if (strcmp(argv[2], "desc") == 0) {
        is_ascending = 0;
    } else {
        printf("Invalid order: %s (expected 'asc' or 'desc')\n", argv[2]);
        free(arr);
        return 1;
    }
    
    // Parse the values to search
    int values_size;
    int* values = parse_int_array(argv[3], &values_size);
    if (values == NULL) {
        printf("Failed to parse values\n");
        free(arr);
        return 1;
    }
    
 
    run_test(arr, arr_size, values, values_size, is_ascending);
    
 
    free(arr);
    free(values);
    
    return 0;
}