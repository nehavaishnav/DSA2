#include<stdio.h>
int maxsize=5;
int cur_size=1;
int val;
void inserr_at_end(int arr[]){
    if(cur_size<maxsize){
        arr[cur_size]=val;
        cur_size++;
    }
    else{
        printf("array is full\n");
    }

}
void insert_at_beg(int arr[]){
    if(cur_size<maxsize){
        for (int i=0;i<cur_size;i--)
        {
        arr[i+1]=arr[i];
        }
        arr[0]=val;
    }
}
void diplay(int arr[])

{
    for (int i=0;i<cur_size;i++){
        printf("%d",arr[i]);
    }
}
int main(){
int arr[maxsize];
arr[0]=1;
scanf("%d",&val);
inserr_at_end(arr);
diplay(arr);
return 0;

}