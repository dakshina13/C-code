#include <stdio.h>
int a[10][10], vis[10], n;
void bfs(int v)
{
    int q[10], f = 1, r = 1, u, i;
    //Adding the source vvertex to the queue
    //And marking it as visited
    q[r] = v;
    vis[v] = 1;
    while (f <= r)
    {
        //taking the front element of the queue
        u = q[f];
        printf("%d\t", u);
        //And checking the connection of this element 
        //with the rest of the vertices
        //And adding those to the queue if it is not already visited
        for (i = 1; i <= n; i++)
        {
            if (a[u][i] == 1 && vis[i] == 0)
            {
                vis[i] = 1;
                r = r + 1;
                q[r] = i;
            }
        }
        //Increamenting the front to point to next element
        f = f + 1;
    }
}

void main()
{
    int i, j, src;

    printf("enter the no of vertices\n");
    scanf("%d", &n);
    printf("enter the adjacency\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
        vis[i] = 0;
    }

    printf("enter the source vertex\n");
    scanf("%d", &src);
    printf("nodes reachable from source vertex are\n");
    bfs(src);
}