#include <stdio.h>
int parent[10];
int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}
int union_set(int i, int j) {
    
    return 0;
}
int main() {
    int n, edges = 1;
    int min, cost = 0;
    int a, b, u, v;
    int graph[10][10];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter adjacency matrix (0 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = 999;
        }
    }
    printf("\nEdges in Minimum Spanning Tree:\n");
    while (edges < n) {
        min = 999;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][j] < min) {
                    min = graph[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if (union_set(u, v)) {
            printf("%d - %d : %d\n", a, b, min);
            cost += min;
            edges++;
        }
        graph[a][b] = graph[b][a] = 999;
    }
    printf("\nTotal cost of MST = %d\n", cost);
    return 0;
}
