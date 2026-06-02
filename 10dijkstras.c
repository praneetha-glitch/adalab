#include <stdio.h>

int main()
{
    int n, src;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[10][10];
    int dist[10];
    int visited[10] = {0};

    printf("Enter cost adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0 && i != j)
                cost[i][j] = 999;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    for (int i = 0; i < n; i++)
        dist[i] = cost[src][i];

    visited[src] = 1;
    dist[src] = 0;

    for (int count = 1; count < n; count++)
    {
        int min = 999, u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
        }
    }

    printf("Shortest distances from vertex %d:\n", src);

    for (int i = 0; i < n; i++)
        printf("%d -> %d = %d\n", src, i, dist[i]);

    return 0;
}