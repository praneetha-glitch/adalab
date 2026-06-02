#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[10][10];
    int visited[10] = {0};
    int mincost = 0;

    printf("Enter cost adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[0] = 1;

    printf("Edges in MST:\n");

    for (int e = 0; e < n - 1; e++)
    {
        int min = 999;
        int a = -1, b = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        printf("%d -> %d : %d\n", a, b, min);

        mincost += min;
        visited[b] = 1;
    }

    printf("Minimum Cost = %d\n", mincost);

    return 0;
}