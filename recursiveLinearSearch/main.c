#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
	int n,i,key;
   float start,end;
	printf("Enter the number of elements\n");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++)
        arr[i]=rand();
    printf("Enter the element to search\n");
    scanf("%d",&key);
    start=clock();
	int result = linearSearch(arr, 0, n - 1, key);
    end=clock();
    if(result==-1)
        printf("Element is not present in array");
    else
        printf("Element is present at index %d",result);
    printf("\n Time taken to sort %d numbers is %f Secs",n, (((double)(end-start))/CLOCKS_PER_SEC));
	return 0;
}
