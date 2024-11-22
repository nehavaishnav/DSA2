#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = NULL;

// Function declarations
void insert_at_beg(int data);
void insert_at_end(int data);
void insert_at_position(int data, int pos);
void display();

int main() {
    insert_at_beg(10);
    insert_at_end(20);
    insert_at_end(30);
    display();
    insert_at_position(15, 2);

    printf("Doubly Circular Linked List: ");
    display();

    return 0;
}

// Insert at the beginning
void insert_at_beg(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if (head == NULL) {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
    } else {
        struct node* tail = head->prev;

        newnode->next = head;
        newnode->prev = tail;
        tail->next = newnode;
        head->prev = newnode;

        head = newnode;
    }
}

// Insert at the end
void insert_at_end(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if (head == NULL) {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
    } else {
        struct node* tail = head->prev;

        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
    }
}

// Insert at a specific position
void insert_at_position(int data, int pos) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    if (head == NULL || pos == 1) {
        insert_at_beg(data);
        return;
    }

    struct node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position out of bounds\n");
            return;
        }
    }

    struct node* next_node = temp->next;
    newnode->next = next_node;
    newnode->prev = temp;
    temp->next = newnode;
    next_node->prev = newnode;
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}
