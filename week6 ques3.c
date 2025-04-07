#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
bool visited[MAX_VERTICES];
bool recStack[MAX_VERTICES];

void initGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }
}

void addEdge(int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

bool isCyclicUtil(int v) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        Node* temp = adjList[v];
        while (temp) {
            if (!visited[temp->vertex] && isCyclicUtil(temp->vertex))
                return true;
            else if (recStack[temp->vertex])
                return true;
            temp = temp->next;
        }
    }
    recStack[v] = false;
    return false;
}

void detectCycle(int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < vertices; i++) {
        if (isCyclicUtil(i)) {
            printf("Yes Cycle Exists\n");
            return;
        }
    }
    printf("No Cycle Exists\n");
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination pairs):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    detectCycle(vertices);

    return 0;
}