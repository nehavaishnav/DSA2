#include <stdio.h>
#include <stdlib.h>

#define max_size 10 // Maximum size of the priority queue

struct priorityQ {
    int data; // The data element
    int p;    // The priority
};

struct priorityQ arr[max_size]; // Array to hold the priority queue
int cur_size = 0; // Current size of the priority queue

// Function to insert an element into the priority queue
void insert(int data, int p) {
    if (cur_size == max_size) {
        printf("Overflow: Priority Queue is full\n");
        return;
    }

    // Find the correct position for the new element
    int i;
    for (i = cur_size - 1; (i >= 0 && p < arr[i].p); i--) {
        arr[i + 1] = arr[i]; // Shift elements to the right
    }

    // Insert the new element at the found position
    arr[i + 1].data = data;
    arr[i + 1].p = p;
    cur_size++; // Increment the size of the priority queue
}

// Function to delete the element with the highest priority
void delete() {
    if (cur_size == 0) {
        printf("Underflow: Priority Queue is empty\n");
        return;
    }

    // The element with the highest priority is at the front (index 0)
    printf("Deleted element: %d with priority: %d\n", arr[0].data, arr[0].p);

    // Shift elements to the left to fill the gap
    for (int i = 0; i < cur_size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    cur_size--; // Decrement the size of the priority queue
}

// Function to display the contents of the priority queue
void display() {
    if (cur_size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i < cur_size; i++) {
        printf("Data: %d, Priority: %d\n", arr[i].data, arr[i].p);
    }
}

int main() {
    insert(34, 2); // Insert element with priority 2
    insert(22, 1); // Insert element with priority 1
    insert(75, 3); // Insert element with priority 3
    insert(99, 0); // Insert element with priority 0 (highest priority)
    insert(27, 2); // Insert element with priority 2

    display(); // Display the current state of the priority queue

    delete(); // Remove the highest priority element
    display(); // Display the current state of the priority queue

    return 0;  
}
