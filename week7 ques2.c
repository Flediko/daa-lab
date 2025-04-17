#include <stdio.h>
#define MAX 100
#define INF 99999

int minDist(int dist[], int visited[], int n) {
    int min = INF, index = -1;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] < min)
            min = dist[i], index = i;
    return index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j + 1);
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j + 1);
}

void dijkstra(int graph[MAX][MAX], int n, int start, int end) {
    int dist[MAX], visited[MAX] = {0}, parent[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDist(dist, visited, n);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[end] == INF)
        printf("no path\n");
    else {
        printPath(parent, end);
        printf(": %d\n", dist[end]);
    }
}

int main() {
    int n, graph[MAX][MAX], src, dest;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    scanf("%d %d", &src, &dest);
    dijkstra(graph, n, src - 1, dest - 1);
    return 0;
}