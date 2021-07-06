#include <stdio.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}

void knapSack(int W, int wt[], int val[], int n)
{
    int i, w, res, count = 0;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    res = K[n][W];
    printf("\n\nMaximum Value that can be obtained is : %d", res);
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
    knapSack(wtkey, wt, val, valsize);
    return 0;
}