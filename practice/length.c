#include <stdio.h>
#include <stdlib.h>

// Define the structure for the header and nodes
struct header {
    int length;   // Store the length of the list
    struct node* next;
};

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Insert a node at the end and update the length in the header
void insert_at_end(struct header* h, int data) {
    struct node* newnode = create_node(data);

    if (h->next == NULL) {
        h->next = newnode;  // If list is empty, first node after header
    } else {
        struct node* temp = h->next;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    h->length++;  // Increment the length stored in the header
}

// Get the length from the header
int get_length(struct header* h) {
    return h->length;
}

// Display the linked list
void display(struct header* h) {
    struct node* temp = h->next;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct header* head = (struct header*)malloc(sizeof(struct header));
    head->length = 0;  // Initialize length to 0
    head->next = NULL;

    insert_at_end(head, 10);
    insert_at_end(head, 20);
    insert_at_end(head, 30);

    printf("Linked list: ");
    display(head);
    printf("Length of the list: %d\n", get_length(head));

    return 0;
}
