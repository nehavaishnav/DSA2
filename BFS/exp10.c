#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100

// BFS function
void bfs(int graph[MAX_NODES][MAX_NODES], int start, int num_nodes) {
    bool visited[MAX_NODES] = {false}; // Visited array
    int queue[MAX_NODES]; // Queue for BFS
    int front = 0, rear = 0;

    // Start BFS from the start node
    visited[start] = true;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Explore all neighbors of the current node
        for (int i = 0; i < num_nodes; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

// DFS Helper function
void dfsUtil(int graph[MAX_NODES][MAX_NODES], int node, bool visited[], int num_nodes) {
    visited[node] = true;
    printf("%d ", node);

    // Explore all neighbors of the current node
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfsUtil(graph, i, visited, num_nodes);
        }
    }
}

// DFS function
void dfs(int graph[MAX_NODES][MAX_NODES], int start, int num_nodes) {
    bool visited[MAX_NODES] = {false}; // Visited array
    printf("DFS Traversal: ");
    dfsUtil(graph, start, visited, num_nodes);
    printf("\n");
}

// Main function
int main() {
    // Example adjacency matrix
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0}
    };

    int num_nodes = 5;
    int start_node = 0;

    bfs(graph, start_node, num_nodes);
    dfs(graph, start_node, num_nodes);

    return 0;
}
