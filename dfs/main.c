#include <stdio.h>
int a[20][20], reach[20], n;
void dfs(int v)
{
    int i;
    reach[v] = 1;
    for (i = 1; i <= n; i++)
        if (a[v][i]==1 && reach[i]==0){
            dfs(i);
        }
}
void main()
{
    int i, j, count = 0;
    printf("Enter number of vertices:\n");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++){
        reach[i] = 0;
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    }
    //Starting from the first vertice
    //For any connected graph if we start from any vertex
    //it reach all other vertices
    dfs(1);
    //Checking if the depth first search reached
    //all the vertices
    for (i = 1; i <= n; i++)
    {
        if (reach[i]==1)
            count++;
    }
    if (count == n)
        printf("Graph is connected\n");
    else
        printf("Graph is not connected\n");
}