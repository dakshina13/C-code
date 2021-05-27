#include<stdio.h>
void merge(int b[],int c[],int a[],int nOfB,int nOfC){
    int i=0,j=0,k=0;
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
    while(i<nOfB&&j<nOfC){
        if(b[i]<=c[j]){
            a[k]=b[i];
            i++;
        }else{
            a[k]=c[j];
            j++;
        }
        k++;
    }
    //printf("Values of i=%d and j=%d\n",i,j);
    if(i==nOfB){
        for(j;j<nOfC;j++){
            a[k]=c[j];
            k++;
        }
    }
    else{
        for(i;i<nOfC;i++){
            a[k]=b[i];
            k++;
        }
    }
    // printf("Printing the Divided array A\n");
    // for(i=0;i<k;i++){
    //     printf("%d\t",a[i]);
    // }
    // printf("\n");
}
void inputArray(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
int main(){
    int n1,n2,i,n,median;
    printf("Enter the number of elements in array 1\n");
    scanf("%d",&n1);
    printf("Enter the sort array 1\n");
    int b[n1];
    inputArray(b,n1);
    printf("Enter the number of elements in array 2\n");
    scanf("%d",&n2);
    printf("Enter the sort array 2\n");
    int c[n2];
    inputArray(c,n2);
    n=n1+n2;
    int a[n];
    merge(b,c,a,n1,n2);
    for(i=0;i<n1+n2;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    if(n%2==1){
        median=(n+1)/2;
        printf("Median is %d\n",a[median-1]);
    }
    else {
        median=(n)/2;
        printf("Median is %f\n",(float)(a[median-1]+a[median])/2);
    }
    return 0;
}