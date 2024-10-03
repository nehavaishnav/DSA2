#include<stdio.h>
#include<stdlib.h>

int queue[100];
int n = 100;          // Define the maximum size of the queue
int rear = -1;        // Index of the last element
int front = -1;       // Index of the first element

// Function to check if the queue is empty
int isEmpty() {
    if (rear == -1 && front == -1) {
        return 1;     // Queue is empty
    }
    return 0;         // Queue is not empty
}

// Function to check if the queue is full
int isFull() {
    if (rear == n - 1) {
        return 1;     // Queue is full
    }
    return 0;         // Queue is not full
}

// Function to add an element to the queue (enqueue)
void Enqueue(int element) {
    if (isFull()) {
        printf("Overflow error! Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;  // Set front to 0 when first element is added
        }
        rear++;
        queue[rear] = element;
        printf("Enqueued %d\n", element);
    }
}

// Function to remove an element from the queue (dequeue)
void Dequeue() {
    if (isEmpty()) {
        printf("Underflow error! Queue is empty.\n");
    } else if (front == rear) {  // When only one element is present
        printf("Dequeued %d\n", queue[front]);
        front = rear = -1;  // Reset both front and rear
    } else {
        printf("Dequeued %d\n", queue[front]);
        front++;
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

// Function to display all elements of the queue
void Display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function to demonstrate queue operations
int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Display();

    printf("Deleted\n");
    Dequeue();
    Enqueue(40);
    Display();

    Peek();
    
    return 0;
}
