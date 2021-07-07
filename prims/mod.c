#include <stdio.h>
int u, v, n, i, j, ns = 1;
int visited[10] = {0},
    min, mincost = 0, graph[10][10];
void main()
{
    int node, start;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = 999;
        }
    printf("The graph:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d\t", graph[i][j]);
        printf("\n");
    }
    visited[1] = 1;
    printf("Enter the node to be excluded\n");
    scanf("%d", &node);
    visited[node] = 1;
    if (node == 1)
    {
        visited[2]=1;
        start = 2;
    }
    else
        start = 1;
    while (ns < n-1)
    {
        for (i = start, min = 999; i <= n; i++)
        {
            for (j = start; j <= n; j++)
            {
                if (graph[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (visited[v] == 0)
        {
            ns++;
            printf("Edge (%d %d) cost:%d\n", u, v, min);
            mincost += min;
            visited[v] = 1;
        }
        graph[u][v] = graph[v][u] = 999;
    }

    printf("Minimum cost=%d\n", mincost);
}