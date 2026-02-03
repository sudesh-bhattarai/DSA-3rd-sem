#include <stdio.h>
#include<limits.h>
#include<stdbool.h>
#define MAX 10
#define INF INT_MAX
int findMinDistance(int dist[], bool visited[], int n) 
{
    int min = INF, minIndex;
    for (int v = 0; v < n; v++) 
    {
        if (!visited[v] && dist[v] <= min) 
        {
            min = dist[v], minIndex = v;
        }
    }
    return minIndex;
}
void dijkstra(int graph[MAX][MAX], int src, int n) 
{
    int dist[MAX];
    bool visited[MAX]; 
    for (int i = 0; i < n; i++) 
    {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) 
    {
        int u = findMinDistance(dist, visited, n);
        visited[u] = true;
        for (int v = 0; v < n; v++) 
        {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }
}
int main() {
    int graph[MAX][MAX];
    int n, src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(graph, src, n);
    return 0;
}
