#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

struct Node *createNode(int data)
{
    struct Node *newnode;

    newnode = (struct node *)malloc(sizeof(struct Node));

    if (!newnode)
    {
        printf("memory not allocated");
        exit(1);
    }

    newnode->data = data;
    newnode->next == NULL;
}

void insert_at_beg(int data)
{
    struct Node *newnode = createNode(data);
    newnode->next = head;
    head = newnode;
}

void insert_at_specific(int data)
{
}

void insert_end(int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }
    struct Node *temp;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->next = NULL;
}
