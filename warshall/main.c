#include<stdio.h>
void warshall(int n,int a[n][n]){
    int i,j,k;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(a[i][j]==0 && ((a[i][k]==1)&&(a[k][j]==1))){
                    a[i][j]=1;
                }
            }
        }
    }
}
int main(){
    int n,i,j,c;
    printf("Enter the size of the graph\n");
    scanf("%d",&n);
    int graph[n][n];
    printf("Enter the graph\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf ("The following matrix is the input matrix \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf ("\t%d", graph[i][j]);
        }
        printf("\n");
    }
    warshall(n,graph);
    printf ("The following matrix shows the shortest distances between every pair of vertices \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf ("\t%d", graph[i][j]);
        }
        printf("\n");
    }
}