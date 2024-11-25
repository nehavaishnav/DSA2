#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Doubly Linked List structure
typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

// Function to create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to initialize a doubly linked list
DoublyLinkedList* createList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Insertion at the front
void insertFront(DoublyLinkedList* list, int val) {
    Node* newNode = createNode(val);
    if (list->head == NULL) { // Empty list
        list->head = list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
    printf("Inserted %d at the front.\n", val);
}

// Insertion at the end
void insertEnd(DoublyLinkedList* list, int val) {
    Node* newNode = createNode(val);
    if (list->tail == NULL) { // Empty list
        list->head = list->tail = newNode;
    } else {
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    printf("Inserted %d at the end.\n", val);
}

// Deletion from the front
void deleteFront(DoublyLinkedList* list) {
    if (list->head == NULL) { // Empty list
        printf("List is empty. Cannot delete from the front.\n");
        return;
    }
    Node* temp = list->head;
    if (list->head == list->tail) { // Single element
        list->head = list->tail = NULL;
    } else {
        list->head = list->head->next;
        list->head->prev = NULL;
    }
    printf("Deleted %d from the front.\n", temp->data);
    free(temp);
}

// Deletion from the end
void deleteEnd(DoublyLinkedList* list) {
    if (list->tail == NULL) { // Empty list
        printf("List is empty. Cannot delete from the end.\n");
        return;
    }
    Node* temp = list->tail;
    if (list->head == list->tail) { // Single element
        list->head = list->tail = NULL;
    } else {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    }
    printf("Deleted %d from the end.\n", temp->data);
    free(temp);
}

// Search for an element
void search(DoublyLinkedList* list, int val) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == val) {
            printf("Element %d found in the list.\n", val);
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list.\n", val);
}

// Display list in forward direction
void displayForward(DoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = list->head;
    printf("List in forward direction: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Display list in reverse direction
void displayReverse(DoublyLinkedList* list) {
    if (list->tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* current = list->tail;
    printf("List in reverse direction: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Free all nodes in the list
void freeList(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

// Main function to demonstrate the DLL
int main() {
    DoublyLinkedList* dll = createList();

    // Demonstrate insertions
    insertFront(dll, 10);
    insertEnd(dll, 20);
    insertFront(dll, 5);
    insertEnd(dll, 25);

    // Display list
    displayForward(dll);
    displayReverse(dll);

    // Demonstrate search
    search(dll, 20);
    search(dll, 30);

    // Demonstrate deletions
    deleteFront(dll);
    deleteEnd(dll);

    // Display list after deletions
    displayForward(dll);
    displayReverse(dll);

    // Free the list
    freeList(dll);

    return 0;
}
