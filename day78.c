#include <stdio.h>
#include <limits.h>

#define MAX 1000

int graph[MAX][MAX];
int selected[MAX];
int n, m;

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            graph[i][j] = INT_MAX;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    selected[1] = 1;

    int edges = 0;
    int total = 0;

    while (edges < n - 1) {
        int min = INT_MAX;
        int x = 0, y = 0;

        for (int i = 1; i <= n; i++) {
            if (selected[i]) {
                for (int j = 1; j <= n; j++) {
                    if (!selected[j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        selected[y] = 1;
        total += graph[x][y];
        edges++;
    }

    printf("%d\n", total);

    return 0;
}
