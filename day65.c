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

int dfs(struct Graph* graph, int v, int parent, int* visited) {
    visited[v] = 1;

    struct Node* temp = graph->adj[v];
    while (temp) {
        int adjVertex = temp->vertex;

        if (!visited[adjVertex]) {
            if (dfs(graph, adjVertex, v, visited)) return 1;
        } else if (adjVertex != parent) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

int hasCycle(struct Graph* graph) {
    int visited[graph->n];
    for (int i = 0; i < graph->n; i++) visited[i] = 0;

    for (int i = 0; i < graph->n; i++) {
        if (!visited[i]) {
            if (dfs(graph, i, -1, visited)) return 1;
        }
    }

    return 0;
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

    if (hasCycle(graph)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
