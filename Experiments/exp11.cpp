#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 10
#define INF INT_MAX // Represents an infinite distance

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool visited[], int num_nodes) {
    int min = INF, min_index = -1;

    for (int v = 0; v < num_nodes; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Dijkstra's Algorithm
void dijkstra(int graph[MAX_NODES][MAX_NODES], int source, int num_nodes) {
    int dist[MAX_NODES];        // dist[i] will hold the shortest distance from the source to node i
    bool visited[MAX_NODES];    // visited[i] is true if the shortest distance to node i is finalized

    // Initialize all distances as INF and visited[] as false
    for (int i = 0; i < num_nodes; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    // Distance of the source node to itself is always 0
    dist[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < num_nodes - 1; count++) {
        // Pick the minimum distance vertex from the set of unvisited vertices
        int u = minDistance(dist, visited, num_nodes);

        // Mark the picked vertex as visited
        visited[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < num_nodes; v++) {
            // Update dist[v] if:
            // 1. There is an edge from u to v.
            // 2. v is not visited.
            // 3. Total weight of the path from source to v through u is smaller than dist[v].
            if (graph[u][v] && !visited[v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances from the source
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < num_nodes; i++) {
        if (dist[i] == INF) {
            printf("%d\tINF\n", i);
        } else {
            printf("%d\t%d\n", i, dist[i]);
        }
    }
}

// Main function
int main() {
    // Example adjacency matrix
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 7, 9, 0, 0, 0},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 0},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {0, 0, 0, 0, 9, 0}
    };

    int num_nodes = 6; // Number of nodes
    int source = 0;    // Source node

    dijkstra(graph, source, num_nodes);

    return 0;
}
