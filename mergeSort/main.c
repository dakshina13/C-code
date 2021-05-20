#include<stdio.h>
#include<time.h>
#include<stdlib.h>
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
void mergeSort(int a[],int n){
    int b[n],c[n],i,j=0;
    int nOfB=n/2,nOfC=n-nOfB;
    // printf("No of elements in B %d\n",nOfB);
    // printf("No of elements in C %d\n",nOfC);
    if(n>1){
        for(i=0;i<n/2;i++){
            b[i]=a[i];
        }
        for(i=n/2;i<n;i++){
            c[j]=a[i];
            j++;
        }
        mergeSort(b,nOfB);
        mergeSort(c,nOfC);
        merge(b,c,a,nOfB,nOfC);
    }
    // printf("Printing the Divied array B\n");
    // for(i=0;i<nOfB;i++){
    //     printf("%d\t",b[i]);
    // }
    // printf("Printing the Divied array C\n");
    // for(i=0;i<nOfC;i++){
    //     printf("%d\t",c[i]);
    // }
}
int main(){
    int n,i;
    printf("Enter the number of element in array\n");
    scanf("%d",&n);
    int a[n];
    // printf("Enter the elements of array\n");
    // for(i=0;i<n;i++){
    //     scanf("%d",&a[i]);
    // }
    for(i=0;i<n;i++){
        a[i]=rand()%1000;
    }
    double start,end;
    start=clock();
    mergeSort(a,n);
    end=clock();
    // printf("Sorted array is\n");
    // for(i=0;i<n;i++){
    //     printf("%d\t",a[i]);
    //     if(i%8==0)
    //         printf("\n");
    // }
    printf("Start %f\n",start);
    printf("End %f\n",end);
    printf("Number of elements %d sorted in time %f",n,((end-start)/CLOCKS_PER_SEC));
    return 0;
}