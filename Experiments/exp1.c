#include <stdio.h>

#define MAX_SIZE 100

void insertAtBeginning(int arr[], int *size, int element) {

    if (*size > MAX_SIZE) {
        printf("Array is full, cannot insert at the beginning.\n");
    } 
    for (int i = *size; i >=0; i--) {
            arr[i+1] = arr[i];
        }
        arr[0] = element;
        (*size)++;
}

void insertAtEnd(int arr[], int *size, int element) {
    if (*size < MAX_SIZE) {
        arr[*size] = element;
        (*size)++;
    } else {
        printf("Array is full, cannot insert at the end.\n");
    }
}

void insertAtPosition(int arr[], int *size, int element, int position) {
    if (position < 0 || position > *size || *size >= MAX_SIZE) {
        printf("Invalid position or array is full.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice, element, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d", &element);
                insertAtBeginning(arr, &size, element);
                break;
            case 2:
                printf("Enter the element to insert at the end: ");
                scanf("%d", &element);
                insertAtEnd(arr, &size, element);
                break;
            case 3:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position (0 to %d): ", size);
                scanf("%d", &position);
                insertAtPosition(arr, &size, element, position);
                break;
            case 4:
                displayArray(arr, size);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}