#include <stdio.h>
#include <conio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void knapsack(int w[], int v[], int s, int n)
{
    int k[n + 1][s + 1];
    int i, j, res = 0, count = 0;

    for (i = 0; i <= n; i++)
        for (j = 0; j <= s; j++)
        {
            if (i == 0 || j == 0)
                k[i][j] = 0;
            else if (w[i - 1] <= j)
                k[i][j] = max(v[i - 1] + k[i - 1][j - w[i - 1]], k[i - 1][j]);
            else
                k[i][j] = k[i - 1][j];
        }

    res = k[n][s];
    printf("\n\nMaximum Value that can be obtained is : %d", res);
    j = s;
    printf("\nSelected objects are :  ");
    for (i = n; i > 0 && res > 0; i--)
    {
        if (res == k[i - 1][j])
            continue;
        else
        {
            printf("%d\t", i);
            res = res - v[i - 1];
            j = j - w[i - 1];
        }
        count++;
    }
    printf("\n\nThe count of the items selected: %d", count);
}

int main()
{
    int valsize, i, wtsize, wtkey;
    printf("enter the size of value and weight arrays\n");
    scanf("%d %d", &valsize, &wtsize);
    int val[valsize];
    int wt[wtsize];
    printf("enter the values array\n");
    for (i = 0; i < valsize; i++)
    {
        scanf("%d", &val[i]);
    }
    printf("enter the weight array\n");
    for (i = 0; i < wtsize; i++)
    {
        scanf("%d", &wt[i]);
    }
    printf("enter the weight key\n");
    scanf("%d", &wtkey);
    knapsack(wt, val, wtkey, valsize);
    return 0;
}