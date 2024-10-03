#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node  *next;
};
struct node *head;
struct node* createnode(){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("memory not allocated");
    }
    newnode->data=NULL;
    newnode->next=NULL;
   
}
void insertbeg(int data){
       struct node *newnode=createnode();
       if(head==NULL){
        printf("empty");
       }
       else{
        newnode->data=data;
    newnode->next=head;
    head=newnode;

       }

}
void insertend(int data){
    struct node*temp=head;
    struct node* newnode=createnode();
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->data=data;
    temp->next=newnode;

}

int main(){
    return 0;
}