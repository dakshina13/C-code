#include <stdio.h>
#define INF 9999
void floyd(int n, int a[n][n], int next[n][n])
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][j] > (a[i][k] + a[k][j]))
                {
                    a[i][j] = (a[i][k] + a[k][j]);
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}
int main()
{
    int n, i, j, c, s, d, u;
    printf("Enter the size of the graph\n");
    scanf("%d", &n);
    int graph[n][n], next[n][n];
    printf("Enter the graph\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF;
            if (graph[i][j] == INF)
                next[i][j] = -1;
            else
                next[i][j] = j;
        }
    printf("The following matrix is the input matrix \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (graph[i][j] == INF)
                printf("\t%s", "INF");
            else
                printf("\t%d", graph[i][j]);
        }
        printf("\n");
    }
    floyd(n, graph, next);
    printf("Enter the source and destination vertex\n");
    scanf("%d %d", &s, &d);
    printf("The shortest path from vertex %d to vertex %d is %d\n", s, d, graph[s][d]);
    u = s;
    do
    {
        printf("%d->", u);
        u = next[u][d];
    } while (u != d);
    printf("%d", d);
}