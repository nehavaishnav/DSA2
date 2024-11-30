#include<limits.h>
#include<stdio.h>
#define V 5
int minKey(int weight[],int visited[]){
    int min=INT_MAX, min_index;
    for(int v=0;v<V;v++)
     if( visited[v]==0 && weight[v]<min){
      min=weight[v];
      min_index=v;
     }
    return min_index;

}


int prim(int graph[V][V]){
    int parent[V];
    int weight[V];
    int visited[V];
    for(int i=0;i<V;i++){
        weight[i]=INT_MAX,visited[i]=0;
    }
    weight[2]=0;
    parent[2]=-1;
    for(int count=0;count<V-1;count++){
        int u=minKey(weight, visited);
        visited[u]=1;

    } 
    for(int v=0;v<v;v++){
        if(graph[u][v] && visited[v]=0){
            parent[v]=u, weight[v]=graph[u][v];
        }
    }

} 
int main(){
    

}