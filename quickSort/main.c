#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void quickSort(int a[],int f,int l){
    if(f<l){
        //Assigning the pivot to the first element of array
        int povit=f;
        int i=f;
        int j=l;
        while(i<j){
            //Finding a number greater than or equal to  pivot number
            while(a[i]<=a[povit]&&i<l)
                i++;
            //Finding a number less than pivot number
            while(a[j]>a[povit]&&j>=f)
                j--;
            //Swapping the i and j elements
            if(i<j){
                int temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
        //Swapping Pivot Element
        int temp=a[j];
        a[j]=a[povit];
        a[povit]=temp;
        //Breaking the array at the position the pivot was moved to
        quickSort(a,f,j-1);
        quickSort(a,j+1,l);
    }
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
    quickSort(a,0,n-1);
    end=clock();
    // printf("Sorted array is\n");
    // for(i=0;i<n;i++){
    //     if(i%8==0)
    //         printf("\n");
    //     printf("%d\t",a[i]);
    // }
    printf("Start %f\n",start);
    printf("End %f\n",end);
    printf("Number of elements %d sorted in time %f",n,((end-start)/CLOCKS_PER_SEC));
    return 0;
}