#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Define the size of the queue

int queue[SIZE]; // Array to hold the queue elements
int front = -1;  // Points to the front of the queue
int rear = -1;   // Points to the rear of the queue

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return (rear + 1) % SIZE == front;
}

// Function to add an element to the circular queue (enqueue)
void Enqueue(int element) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d\n", element);
    } else {
        // If queue is initially empty, set front to 0
        if (front == -1) {
            front = 0;
        }
        // Update rear position
        rear = (rear + 1) % SIZE;
        queue[rear] = element;
        printf("Enqueued %d\n", element);
    }
}

// Function to remove an element from the circular queue (dequeue)
void Dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        printf("Dequeued %d\n", queue[front]);
        // If there is only one element, reset queue to empty state
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE; // Update front position
        }
    }
}

// Function to get the element at the front of the queue
void Peek() {
    if (isEmpty()) {
        printf("Queue is empty. No front element.\n");
    } else {
        printf("The element at the front is: %d\n", queue[front]);
    }
}

// Function to display all elements of the circular queue
void Display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % SIZE; // Move to the next position in circular manner
        }
        printf("\n");
    }
}

// Main function to demonstrate circular queue operations
int main() {
    // Enqueue elements into the queue
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);

    Display(); // Display the queue elements

    Dequeue(); // Remove an element from the queue
    Display(); // Display the queue elements again

    Enqueue(60); // Try adding another element to the queue
    Display(); // Display the queue elements

    Peek(); // Show the element at the front of the queue

    return 0;
}
