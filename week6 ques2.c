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

int isBipartite(Graph* graph) {
    int color[MAX_NODES];
    for (int i = 0; i < graph->numVertices; i++) {
        color[i] = -1; // -1 means uncolored
    }

    for (int start = 0; start < graph->numVertices; start++) {
        if (color[start] == -1) {
            color[start] = 0; // Start coloring with color 0
            int queue[MAX_NODES], front = 0, rear = 0;
            queue[rear++] = start;

            while (front < rear) {
                int current = queue[front++];
                Node* temp = graph->adjList[current];

                while (temp) {
                    int adjVertex = temp->vertex;

                    if (color[adjVertex] == -1) {
                        color[adjVertex] = 1 - color[current]; // Alternate color
                        queue[rear++] = adjVertex;
                    } else if (color[adjVertex] == color[current]) {
                        return 0; // Not bipartite
                    }
                    temp = temp->next;
                }
            }
        }
    }
    return 1; // Graph is bipartite
}

int main() {
    int numVertices, edges, src, dest;

    printf("Welcome to the Bipartite Graph Checker!\n");
    printf("Please enter the number of vertices in the graph: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Now, please enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges in the format 'src dest' (one per line):\n");
    for (int i = 0; i < edges; i++) {
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        if (src < 0 || src >= numVertices || dest < 0 || dest >= numVertices) {
            printf("Invalid edge (%d, %d). Please enter vertices between 0 and %d.\n", src, dest, numVertices - 1);
            i--; // Decrement i to repeat this iteration
            continue;
        }
        addEdge(graph, src, dest);
    }

    if (isBipartite(graph)) {
        printf("The graph is bipartite!\n");
    } else {
        printf("The graph is not bipartite.\n");
    }

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
