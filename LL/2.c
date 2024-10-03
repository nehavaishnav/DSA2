//DLL
#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*prev;
    int data;
    struct node*next;
};
struct node* head;

struct node* createnode(int data){
struct node* newnode;
newnode=(struct node*)malloc(sizeof (struct node));
    if(!newnode)
    {
        printf("overflow");
        exit(1);
    }
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
  return newnode;
}


void insert_at_beg(int data) {
    struct node* newnode = createnode(data); // Create the new node

    if (!head) { // If the list is empty
        head = newnode;
    } else {
        newnode->next = head;  // Point new node's next to current head
        head->prev = newnode;  // Update current head's prev pointer
        head = newnode;        // Make the new node the head
    }
}
void insert_at_end(int data) {
    struct node* temp = head;
    struct node* newnode = createnode(data);
    
    // Case when list is empty
    if (head == NULL) {
        head = newnode;
        return;  // No need to exit, just finish here
    }
    
    // Traverse to the end of the list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Insert the new node at the end
    temp->next = newnode;
    newnode->prev = temp;
}

void display() {
    struct node* temp = head;
    if (!head) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

 void insert_at_spec(int data,int loc){
    struct node*temp=head;
    struct node* newnode=createnode(data);
    
 
    if(loc==1){
        insert_at_beg(data);
      return;
    }
    for(int i=1;i<loc-1;i++){
        temp=temp->next;
        if (temp == NULL) {
            printf("Location out of bounds\n");
            return;
        }
    }
  
   newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;



 }
 
 void delete_at_beg() {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);  // Free the memory of the deleted node
}
void delete_at_end() {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct node* temp = head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;  // Update the second last node's next to NULL
    } else {
        head = NULL;  // If the list had only one node
    }

    free(temp);  // Free the memory of the deleted node
}
void delete_at_spec(int loc) {
    if (head == NULL) {
        printf("List is empty, nothing to delete\n");
        return;
    }

    struct node* temp = head;

    if (loc == 1) {  // If deleting the first node
        delete_at_beg();
        return;
    }

    // Traverse the list to reach the desired location
    for (int i = 1; i < loc; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("Location out of bounds\n");
            return;
        }
    }

    // Adjust the previous and next pointers to bypass the node to be deleted
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);  // Free the memory of the deleted node
}

int main(){
    insert_at_beg(10);
    insert_at_beg(20);
    insert_at_beg(30);
    display();
    insert_at_end(40);
    insert_at_end(50);
    display();
    insert_at_spec(100,3);
    display();
    delete_at_beg();
    delete_at_end();
    display();
    delete_at_spec(2);
    display();
    return 0;
}