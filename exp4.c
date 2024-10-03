#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Define maximum size of the queue

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

// Enqueue: Add a customer to the queue
void enqueue(int customerID) {
    if (isFull()) {
        printf("Queue is full. Cannot add more customers.\n");
        return;
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = customerID;
        printf("Customer %d added to the queue.\n", customerID);
    }
}

// Dequeue: Remove a customer from the front of the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. No customers to serve.\n");
    } else {
        printf("Customer %d served and removed from the queue.\n", queue[front]);
        front++;
        // Reset the queue if no more customers are left
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

// Peek: View the customer at the front of the queue
void peek() {
    if (isEmpty()) {
        printf("Queue is empty. No customers to view.\n");
    } else {
        printf("Customer at the front of the queue: %d\n", queue[front]);
    }
}

// Display: Show all customers currently in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Current queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, customerID;

    while (1) {
        printf("\n1. Enqueue Customer\n");
        printf("2. Dequeue Customer\n");
        printf("3. Peek Front Customer\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer ID to add: ");
                scanf("%d", &customerID);
                enqueue(customerID);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
