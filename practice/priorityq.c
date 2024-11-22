#include<stdio.h>
#include<stdlib.h>
#define max_size 10
    int i;
struct PriorityQ{
    int data;
    int p;


};

struct PriorityQ arr[max_size];
int curr_size=0;
void insert(int data,int p){

    if (curr_size==max_size){
        printf("overflow");
    }
for ( i=curr_size-1;i>=0;i--){
    if(p<arr[i].p){
        arr[i+1].data=arr[i].data;
        arr[i+1].p=arr[i].p;
    }
    else{break;
    }}
    arr[i+1].data=data;
    arr[i+1].p=p;
    curr_size++;
    ;}
void display(){
    for(i=0;i<=curr_size;i++){
        printf("%d ",arr[i].data);
        printf("%d ",arr[i].p);
    }
}
    int main(){
        insert(10,1);
        insert(20,1);
    display();


    }

