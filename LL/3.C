//CIRCULAR ll
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

struct node* createNode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (!newnode) {
        printf("Memory not allocated");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert_at_beg(int data) {
    struct node* newnode = createNode(data);
    if (!head) {
        head = newnode;
        newnode->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void insert_at_last(int data) {
    struct node* newnode = createNode(data);
    if (!head) {
        head = newnode;
        newnode->next = head;
    } else {
        struct node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newnode;
        newnode->next = head;
    }
}

void delete_at_beg() {
    if (!head) {
        printf("List is empty\n");
        return;
    }
    
    if (head->next == head) {  // Only one node
        free(head);
        head = NULL;
    } else {
        struct node* temp = head;
        struct node* last = head;

        while (last->next != head) {
            last = last->next;
        }

        last->next = head->next;
        head = head->next;
        free(temp);
    }
}

void delete_at_last() {
    if (!head) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {  // Only one node
        free(head);
        head = NULL;
    } else {
        struct node* temp = head;
        struct node* prev = NULL;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        free(temp);
    }
}

void delete_at_specific(int loc) {
    if (!head) {
        printf("List is empty\n");
        return;
    }

    if (loc == 1) {
        delete_at_beg();
        return;
    }

    struct node* temp = head;
    struct node* prev = NULL;

    for (int i = 1; i < loc; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == head) {
            printf("Location out of bounds\n");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
}

void display() {
    if (!head) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    insert_at_beg(40);
    insert_at_beg(30);
    insert_at_beg(20);
    insert_at_beg(10);
    insert_at_last(50);

    printf("Initial list:\n");
    display();

    delete_at_beg();
    printf("After deleting at beginning:\n");
    display();

    delete_at_last();
    printf("After deleting at last:\n");
    display();

    delete_at_specific(2);
    printf("After deleting at specific position 2:\n");
    display();

    return 0;
}
