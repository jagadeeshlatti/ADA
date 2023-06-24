#include<stdio.h>
#include<stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
bool visited[MAX_VERTICES];
int stack[MAX_VERTICES];
int top = -1;

void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int start, int end) {
    graph[start][end] = 1;
}

void topologicalSortUtil(int vertex, int vertices) {
    visited[vertex] = true;

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            topologicalSortUtil(i, vertices);
        }
    }

    stack[++top] = vertex;
}

void topologicalSort(int vertices) {
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, vertices);
        }
    }

    printf("Topological Ordering: ");
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}

int main() {
    int vertices, edges, start, end;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    initializeGraph(vertices);

    printf("Enter the edges (start end):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }

    topologicalSort(vertices);

    return 0;
}
