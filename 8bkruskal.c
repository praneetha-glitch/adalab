#include <stdio.h>

int parent[10];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[10][10];
    int mincost = 0;

    printf("Enter cost adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("Edges in MST:\n");

    int edges = 0;

    while (edges < n - 1)
    {
        int min = 999;
        int a = -1, b = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v = find(b);

        if (u != v)
        {
            unionSet(u, v);
            printf("%d -> %d : %d\n", a, b, min);
            mincost += min;
            edges++;
        }

        cost[a][b] = cost[b][a] = 999;
    }

    printf("Minimum Cost = %d\n", mincost);

    return 0;
}