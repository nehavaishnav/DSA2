#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom comparator to compare concatenated strings
int myCompare(const void* a, const void* b) {
    char ab[30], ba[30];
    // Concatenate both ways
    sprintf(ab, "%s%s", *(const char**)a, *(const char**)b);
    sprintf(ba, "%s%s", *(const char**)b, *(const char**)a);
    // Compare concatenated strings
    return strcmp(ba, ab);
}

// Function to find the largest concatenated number
char* findLargest(int* arr, int n) {
    // Convert integers to strings
    char** numbers = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        numbers[i] = (char*)malloc(12 * sizeof(char));
        sprintf(numbers[i], "%d", arr[i]);
    }

    // Sort the array using the custom comparator
    qsort(numbers, n, sizeof(char*), myCompare);

    // Handle the case where all numbers are zero
    if (strcmp(numbers[0], "0") == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        strcpy(result, "0");
        for (int i = 0; i < n; i++) {
            free(numbers[i]);
        }
        free(numbers);
        return result;
    }

    // Concatenate sorted strings
    int totalLength = 0;
    for (int i = 0; i < n; i++) {
        totalLength += strlen(numbers[i]);
    }
    char* result = (char*)malloc((totalLength + 1) * sizeof(char));
    result[0] = '\0';
    for (int i = 0; i < n; i++) {
        strcat(result, numbers[i]);
        free(numbers[i]);
    }
    free(numbers);

    return result;
}

int main() {
    int arr[] = {3, 30, 34, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    char* result = findLargest(arr, n);
    printf("%s\n", result);

    free(result);
    return 0;
}
