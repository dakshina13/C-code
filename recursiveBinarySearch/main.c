
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
}
int linearSearch(int arr[], int l, int n, int x)
{
	if (l >= n) {
		if (arr[l] == x)
			return l;
		return linearSearch(arr, l + 1, n, x);
	}
	return -1;
}

int main(void)
{
	int n,i,key,c,result;
   float start,end;
	printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        arr[i]=rand();
    printf("Enter the element to search\n");
    scanf("%d",&key);
    printf("Enter choice\n");
    printf("1.Linear search\n");
    printf("2.Binary Search\n");
    scanf("%d",&c);
    if(c==1){
        start=clock();
        result = linearSearch(arr, 0, n - 1, key);
        end=clock();
    }else{
        start=clock();
        result = binarySearch(arr, 0, n - 1, key);
        end=clock();
    }
    
    if(result==-1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d",result);
    printf("\n Time taken search %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
	return 0;
}


