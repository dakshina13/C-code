#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int b[], int c[], int a[], int nOfB, int nOfC)
{
    int i = 0, j = 0, k = 0;
    // printf("Printing the Divided array B\n");
    // for(i=0;i<nOfB;i++){
    //     printf("%d\t",b[i]);
    // }
    // printf("\n");
    // printf("Printing the Divided array C\n");
    // for(i=0;i<nOfC;i++){
    //     printf("%d\t",c[i]);
    // }
    // printf("\n");
    // i=0;j=0;k=0;
    while (i < nOfB && j < nOfC)
    {
        if (b[i] <= c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }
    //printf("Values of i=%d and j=%d\n",i,j);
    if (i == nOfB)
    {
        for (j; j < nOfC; j++)
        {
            a[k] = c[j];
            k++;
        }
    }
    else
    {
        for (i; i < nOfC; i++)
        {
            a[k] = b[i];
            k++;
        }
    }
    // printf("Printing the Divided array A\n");
    // for(i=0;i<k;i++){
    //     printf("%d\t",a[i]);
    // }
    // printf("\n");
}
int main()
{
    int n, m, i;
    printf("Enter the number of element in array 1\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of array 1\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the number of element in array 2\n");
    scanf("%d", &m);
    int b[m];
    printf("Enter the elements of array 2\n");
    for (i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    int c[m + n];
    merge(a, b, c, n, m);
    printf("Sorted array is\n");
    for (i = 0; i < n+m; i++)
    {
        if ((i+1) % 8 == 0)
            printf("\n");
        printf("%d\t", c[i]);
    }
    return 0;
}