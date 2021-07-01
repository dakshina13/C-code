#include<stdio.h>
int visited[10],startNode,cyclic=0;
int n,a[10][10];
void dfs(int v){
    int i;
    visited[v]=1;
    for(i=0;i<n;i++){
        if(a[v][i]==1){
            if(i==startNode){
                printf("The graph is cyclic.\n");
                cyclic=1;
                break;
            }
            if(visited[i]==0){
                dfs(i);
            }
        }
    }
}
void checkCycle(){
    int i,j;
    for(j=0;j<n;j++){
        visited[j]=0;
    }
    for(i=0;i<n;i++){
        startNode=i;
        //printf("Start node: %d\n",startNode);
        dfs(i);
        if(cyclic==1)
            break;
        //printf("Printing visited node from start node %d\n",startNode);
        //RESETING TO START THE PROCESS AGAIN
        for(j=0;j<n;j++){
            //printf("%d\t",visited[j]);
            visited[j]=0;
        }
        //printf("\n");
    }
    if(cyclic==0){
        printf("The Graph is not cyclic\n");
    }
}
int main(){
    int i,j;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the graph matrix\n");
    for(i=0;i<n;i++){
        printf("Enter the row %d: ",i+1);
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    checkCycle();
}