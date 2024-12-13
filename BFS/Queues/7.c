//costly deque
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the stacks

int stack1[MAX], stack2[MAX]; // Two stacks used for implementing the queue
int top1 = -1, top2 = -1;     // Top pointers for both stacks

// Function to push an element onto stack1
void push1(int data) {
    if (top1 == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        top1++;
        stack1[top1] = data;
    }
}

// Function to push an element onto stack2
void push2(int data) {
    if (top2 == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        top2++;
        stack2[top2] = data;
    }
}

// Function to pop an element from stack1
int pop1() {
    if (top1 == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        int popped = stack1[top1];
        top1--;
        return popped;
    }
}

// Function to pop an element from stack2
int pop2() {
    if (top2 == -1) {
        printf("Stack Underflow!\n");
        return -1;
    } else {
        int popped = stack2[top2];
        top2--;
        return popped;
    }
}

// Function to add an element to the queue
void Enqueue(int x) {
    push1(x); // Always push new elements onto stack1
    printf("Enqueued: %d\n", x);
}

// Function to remove and return the front element of the queue
int Dequeue() {
    // If both stacks are empty, the queue is empty
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    // If stack2 is empty, move elements from stack1 to stack2
    if (top2 == -1) {
        while (top1 != -1) {
            int temp = pop1();
            push2(temp);
        }
    }
    // Return the top element of stack2, which is the front of the queue
    int frontElement = pop2();
    printf("Dequeued: %d\n", frontElement);
    return frontElement;
}

// Function to display the queue elements
void Display() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty!\n");
        return;
    }

    // Display elements of stack2 in reverse order (if present)
    printf("Queue elements: ");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }

    // Display elements of stack1 in order
    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

void reversequeue(){

    while(top1!=-1){
        int temp=pop1();
        push2(temp);

    }

    
}

// Main function to demonstrate the queue operations
int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Display();

    Dequeue();
    Display();

    Enqueue(40);
    Enqueue(50);
    Display();

    Dequeue();
    Display();
    reversequeue();

    Display();

    return 0;
}
