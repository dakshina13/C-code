#include <stdio.h>

int main()
{
    int i, j, k, n, count = 0;

    printf("Enter the no of vertices:\n");
    scanf("%d", &n);
    int a[n][n], indeg[n], flag[n];

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter row %d\n", i + 1);
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    for (i = 0; i < n; i++)
    {
        indeg[i] = 0;
        flag[i] = 0;
    }

    //Finding the indeg of each vertex of graph
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            indeg[i] = indeg[i] + a[j][i];

    printf("Printing Indeg of adjacent matrix:\n");

    for (i = 0; i < n; i++)
        printf("%d\t", indeg[i]);

    printf("\nThe topological order is:");

    while (count < n)
    {
        for (k = 0; k < n; k++)
        {
            //flag those vertices that have indeg 0
            //and that is printed
            if ((indeg[k] == 0) && (flag[k] == 0))
            {
                printf("%d ", (k + 1));
                flag[k] = 1;
            }
            //Decreasing the indeg of those vertices
            //that have been printed
            for (i = 0; i < n; i++)
            {
                if (a[i][k] == 1)
                {
                    indeg[k]--;
                }
            }
        }
        count++;
    }
    return 0;
}