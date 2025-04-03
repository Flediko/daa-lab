#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjList[MAX_NODES];
    int numVertices;
} Graph;

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void dfs(Graph* graph, int vertex, int target, int* visited, int* path, int* pathIndex) {
    visited[vertex] = 1;
    path[(*pathIndex)++] = vertex;

    if (vertex == target) {
        printf("Path found: ");
        for (int i = 0; i < *pathIndex; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }

    Node* temp = graph->adjList[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            dfs(graph, adjVertex, target, visited, path, pathIndex);
        }
        temp = temp->next;
    }

    (*pathIndex)--;
    visited[vertex] = 0;
}

int main() {
    int numVertices, edges, src, dest;

    printf("Welcome to the DFS Path Finder!\n");
    printf("Please enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Please enter the number of edges: ");
    scanf("%d", &edges);
    printf("Please enter the edges (format: src dest, one per line):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            printf("Invalid edge (%d, %d). Please enter vertices between 0 and %d.\n", src, dest, numVertices - 1);
            i--;
            continue;
        }
        addEdge(graph, src, dest);
    }

    int start, target;
    printf("Please enter the starting node: ");
    scanf("%d", &start);
    printf("Please enter the target node: ");
    scanf("%d", &target);

    if (start < 0 || start >= numVertices || target < 0 || target >= numVertices) {
        printf("Invalid nodes. Please ensure they are between 0 and %d.\n", numVertices - 1);
        free(graph);
        return 1;
    }

    int visited[MAX_NODES] = {0};
    int path[MAX_NODES];
    int pathIndex = 0;

    dfs(graph, start, target, visited, path, &pathIndex);

    for (int i = 0; i < numVertices; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph);

    return 0;
}
