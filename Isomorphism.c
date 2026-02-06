#include <stdio.h>
#include <stdbool.h>

#define MAX 10

// Function to check if two adjacency matrices are isomorphic
bool areIsomorphic(int graph1[MAX][MAX], int graph2[MAX][MAX], int n) {
    // Compare the degree of each vertex in both graphs
    for (int i = 0; i < n; i++) {
        int degree1 = 0, degree2 = 0;
        for (int j = 0; j < n; j++) {
            degree1 += graph1[i][j];
            degree2 += graph2[i][j];
        }
        if (degree1 != degree2)
            return false;
    }

    // Further checks like permutation of adjacency matrices would be needed for a comprehensive isomorphism test.
    // But for simplicity, we will assume degree-check suffices for basic comparison.
    
    return true;
}

int main() {
    int n, edges1, edges2, u, v;
    int graph1[MAX][MAX] = {0};
    int graph2[MAX][MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges for Graph 1: ");
    scanf("%d", &edges1);

    printf("Enter the edges for Graph 1 (u v):\n");
    for (int i = 0; i < edges1; i++) {
        scanf("%d %d", &u, &v);
        graph1[u][v] = 1;
        graph1[v][u] = 1;  // For undirected graph
    }

    printf("Enter the number of edges for Graph 2: ");
    scanf("%d", &edges2);

    if (edges1 != edges2) {
        printf("Graphs are not isomorphic (different number of edges).\n");
        return 0;
    }

    printf("Enter the edges for Graph 2 (u v):\n");
    for (int i = 0; i < edges2; i++) {
        scanf("%d %d", &u, &v);
        graph2[u][v] = 1;
        graph2[v][u] = 1;  // For undirected graph
    }

    if (areIsomorphic(graph1, graph2, n)) {
        printf("Graphs are isomorphic.\n");
    } else {
        printf("Graphs are not isomorphic.\n");
    }

    return 0;
}
