#include <stdio.h>
#define MAX 5

void swap(int *a, int *b) {
    int temp = *a; // Use pointers to swap values
    *a = *b;
    *b = temp;
}

int main() {
    int arr[MAX] = {23, 1, 10, 5, 2};

    // Selection sort algorithm
    for (int i = 0; i < MAX - 1; i++) {
        int min = i; // Assume the min is the first element

        // Find the minimum element in the unsorted portion
        for (int j = i + 1; j < MAX; j++) {
            if (arr[j] < arr[min]) {
                min = j; // Update min if a smaller element is found
            }
        }

        // Swap the found minimum element with the first element
        if (min != i) {
            swap(&arr[min], &arr[i]);
        }
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
