#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Task structure definition
struct Node {
    int id;               // Unique Task ID
    char description[100]; // Task description
    char status[15];       // Status of the task: "Pending" or "Completed"
    struct Node* next;
};

// Global head pointer for the linked list
struct Node* head = NULL;

// Create a new task node
struct Node* createNode(int id, char description[], char status[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->id = id;
    strcpy(newNode->description, description);
    strcpy(newNode->status, status);
    newNode->next = NULL;
    return newNode;
}

// Add a new task at the end of the linked list
void add_task(int id, char description[], char status[]) {
    struct Node* newnode = createNode(id, description, status);
    if (head == NULL) {
        head = newnode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    printf("Task added: ID = %d, Description = %s, Status = %s\n", id, description, status);
}

// Remove a task by its ID
void remove_task(int id) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    
    if (head == NULL) {
        printf("Task list is empty!\n");
        return;
    }
    
    // If the task to be deleted is the head
    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("Task with ID %d removed.\n", id);
        return;
    }
    
    // Search for the task to delete
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    // If the task with the given ID is not found
    if (temp == NULL) {
        printf("Task with ID %d not found.\n", id);
        return;
    }
    
    // Unlink the node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Task with ID %d removed.\n", id);
}

// Mark a task as completed by its ID
void mark_completed(int id) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            strcpy(temp->status, "Completed");
            printf("Task with ID %d marked as Completed.\n", id);
            return;
        }
        temp = temp->next;
    }
    printf("Task with ID %d not found.\n", id);
}

// Display all tasks in the list
void display_tasks() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("Task list is empty!\n");
        return;
    }
    printf("Task List:\n");
    while (temp != NULL) {
        printf("ID: %d | Description: %s | Status: %s\n", temp->id, temp->description, temp->status);
        temp = temp->next;
    }
}

// Main menu and operations
int main() {
    int choice, id;
    char description[100];
    while (1) {
        printf("\nTask Manager\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Display All Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Task ID: ");
                scanf("%d", &id);
                getchar();  // To consume the newline character
                printf("Enter Task Description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove trailing newline
                add_task(id, description, "Pending");
                break;
            case 2:
                printf("Enter Task ID to remove: ");
                scanf("%d", &id);
                remove_task(id);
                break;
            case 3:
                printf("Enter Task ID to mark as completed: ");
                scanf("%d", &id);
                mark_completed(id);
                break;
            case 4:
                display_tasks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
