#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int n;
    struct Node** adj;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->n = n;
    graph->adj = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = graph->adj[v];
    graph->adj[v] = newNode;
}

void dfs(struct Graph* graph, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->adj[v];
    while (temp) {
        if (!visited[temp->vertex]) {
            dfs(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int s;
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    dfs(graph, s, visited);

    return 0;
}
