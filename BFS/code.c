#include <stdio.h>
#include <stdlib.h>

void BFS(int g[][5], int s, int v) {
    int q[v];               // Queue for BFS
    int visited[v];         // Visited array to track visited nodes

    for (int i = 0; i < v; i++) { 
        visited[i] = 0;     // Initialize all nodes as not visited
    }

    int rear = -1, front = -1;

    // Start BFS from the source node
    rear++;
    q[rear] = s;
    visited[s] = 1;

    printf("BFS Traversal: ");
    while (front < rear) {
        int curr = q[++front]; // Dequeue
        printf("%d ", curr);  // Print the current node

        // Check all adjacent nodes
        for (int i = 0; i < v; i++) {
            if (g[curr][i] == 1 && visited[i] != 1) {
                visited[i] = 1;      // Mark node as visited
                q[++rear] = i;       // Enqueue the node
            }
        }
    }
    printf("\n");
}

int main() {
    // Define a graph as an adjacency matrix (example with 9 nodes)
    int g[5][5] = {
      {0, 1, 1, 0, 0},
{1, 0, 0, 1, 1},
{1, 0, 0, 0, 0},
{0, 1, 0, 0, 0},
{0, 1, 0, 0, 0}
    };

    int startNode = 0; // Start BFS from node 0
    BFS(g, startNode, 5);

    return 0;
}
