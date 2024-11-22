#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5 // Define maximum size of the stack

char stack[MAX][50]; // Stack to store book names (each book can have a name up to 50 characters)
int top = -1;

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Push: Add a book to the stack
void push(char book[]) {
    if (isFull()) {
        printf("Stack is full. Can't add more books.\n");
    } else {
        top++;
        strcpy(stack[top], book);
        printf("Book '%s' added to the stack.\n", book);
    }
}

// Pop: Remove the most recent book from the stack
void pop() {
    if (isEmpty()) {
        printf("Stack is empty. No books to remove.\n");
    } else {
        printf("Book '%s' removed from the stack.\n", stack[top]);
        top--;
    }
}

// Peek: View the most recent book without removing it
void peek() {
    if (isEmpty()) {
        printf("Stack is empty. No books to view.\n");
    } else {
        printf("Most recent book: '%s'\n", stack[top]);
    }
}

// Display: Show all books currently in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty. No books to display.\n");
    } else {
        printf("Books in the stack:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d. %s\n", i + 1, stack[i]);
        }
    }
}

int main() {
    int choice;
    char book[50];

    while (1) {
        printf("\nWelcome to the Bookstack Management System!\n");
        printf("1. Add a book\n");
        printf("2. Remove the most recent book\n");
        printf("3. View the most recent book\n");
        printf("4. Display all books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the book name: ");
                fgets(book, sizeof(book), stdin);
                book[strcspn(book, "\n")] = '\0'; // Remove trailing newline from fgets
                push(book);
                break;
            case 2:
                pop();
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
