#include <stdio.h>
#define size 5

int stack[size];
int top = -1; // Initialize top to -1 to indicate an empty stack

int isFull() {
    return top == size - 1; // Returns 1 if the stack is full
}

int isEmpty() {
    return top == -1; // Returns 1 if the stack is empty
}

void push(int element) {
    if (isFull()) {
        printf("Stack Overflow\n");
    } else {
        top++; // Increment top before adding the new element
        stack[top] = element; // Add the element at the top of the stack
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1; // Return -1 or a sentinel value if the stack is empty
    } else {
        int poppedElement = stack[top]; // Get the element at the top
        top--; // Decrement top after popping the element
        return poppedElement; // Return the popped element
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    // Sample usage of the stack
    push(10);
    push(20);
    push(30);
    display(); // Display stack elements

    printf("Popped element: %d\n", pop()); // Pop an element
    display(); // Display stack elements again

    return 0;
}

