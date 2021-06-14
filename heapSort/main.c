#include<stdio.h>  
int temp;  
void heapify(int hp[],int n,int i)  
{  
    int large=i;    
    int left=2*i+1;    
    int right=2*i+2;    
    if (left<n && hp[left]>hp[large])  
        large=left;  
    //While in heap sort right value will be equal to n
    //So it will not get exchanged with the root
    if (right<n && hp[right]>hp[large])  
        large=right;  
  
    if (large!= i)  
    {  
        temp=hp[i];  
        hp[i]=hp[large];   
        hp[large]=temp;  
        heapify(hp,n,large);  
    }  
}  
  
void heapSort(int hp[], int n)  
{  
    int i,j;
    for (i = n/2-1;i>=0;i--)
    {
        heapify(hp,n,i);
    }
    // printf("\nThe number s in the array are \n");
    // for (j=0; j<n; ++j)  
    // {
    //     printf("%d\t",hp[j]);
    // }
    for (i=n-1;i>=0; i--)  
    {  
        temp=hp[0];  
        hp[0]=hp[i];   
        hp[i]=temp;  
        // printf("\nThe number s in the array are \n");
        // for (j=0; j<n; ++j)  
        // {
        //     printf("%d\t",hp[j]);
        // }
        heapify(hp,i,0);  
    }  
}  
  
int main()  
{
    int n,i;
    printf("Enter number of elements:");
    scanf("%d",&n);
    int hp[n];
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    {
        printf("Enter %d element:",(i+1));
        scanf("%d",&hp[i]);
    }
    heapSort(hp,n);  
    printf("\nSorted Array elements\n");  
    for (i=0; i<n; ++i)  
    {
        printf("%d\t",hp[i]);
    }
    return 0;
}