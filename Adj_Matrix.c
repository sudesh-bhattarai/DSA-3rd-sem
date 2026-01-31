#include <stdio.h>
#define MAX 10
void displayMatrix(int adjMatrix[MAX][MAX], int n) 
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int adjMatrix[MAX][MAX] = {0};
    int n, edges, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // For undirected graph, use this line
    }
    displayMatrix(adjMatrix, n);
    return 0;
}
