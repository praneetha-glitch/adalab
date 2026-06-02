#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[10][10];
    int indegree[10] = {0};
    int queue[10], front = 0, rear = -1;
    int topo[10], k = 0;

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(graph[i][j] == 1)
                indegree[j]++;
        }
    }
    for(i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            queue[++rear] = i;
    }

    while(front <= rear)
    {
        int v = queue[front++];
        topo[k++] = v;

        for(j = 0; j < n; j++)
        {
            if(graph[v][j] == 1)
            {
                indegree[j]--;

                if(indegree[j] == 0)
                    queue[++rear] = j;
            }
        }
    }

    if(k != n)
    {
        printf("Topological ordering not possible (Graph contains cycle)\n");
    }
    else
    {
        printf("Topological Order: ");
        for(i = 0; i < n; i++)
            printf("%d ", topo[i]);
    }

    return 0;
}