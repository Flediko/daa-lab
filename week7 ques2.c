#include <stdio.h>
#include <limits.h>

#define MAXV 100
#define INF 99999

// Edge structure
struct Edge {
    int src, dest, weight;
};

// Bellman-Ford function
void bellmanFord(struct Edge edges[], int V, int E, int source) {
    int distance[MAXV];
    int parent[MAXV];

    // Step 1: Initialize distances
    for (int i = 0; i < V; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }
    distance[source] = 0;

    // Step 2: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;
            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                parent[v] = u;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;
        if (distance[u] != INF && distance[u] + w < distance[v]) {
            printf("Graph contains a negative-weight cycle\n");
            return;
        }
    }

    // Print shortest path and distance
    for (int i = 0; i < V; i++) {
        printf("Distance from %d to %d is %d\n", source, i, distance[i]);
        printf("Path: ");
        int temp = i;
        while (temp != -1) {
            printf("%d ", temp);
            temp = parent[temp];
        }
        printf("\n");
    }
}
