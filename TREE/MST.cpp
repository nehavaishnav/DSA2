#include<limits.h>
#include<stdbool.h>
#include<stdio.h>
#define V 5
int minKey(int key[],bool mstSet[]){

}
int printMST(int parent[],int graph[V][V]){
    for(int i=1;i<V;i++)
     printf("%d - %d \t%d \n",parent[i],i)
}
int prim(int graph[V][V]){
    int parent[V];
    int weight[V];
    int visited[V];
    for(int i=0;i<V;i++){
        weight[i]=INT_MAX,visited[i]=false;
    }
    weight[0]=0;
}