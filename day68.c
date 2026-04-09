#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], indegree[MAX], queue[MAX];
int n, front = 0, rear = -1;

void topologicalSort() {
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    while (front <= rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }
}

int main() {
    int edges, u, v;
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    topologicalSort();
    return 0;
}
