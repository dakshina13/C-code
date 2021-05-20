// An element in a sorted array can be found in O[log n) time via binary search.
//  But suppose we rotate an ascending order sorted array at some pivot unknown to you beforehand.
//  So for instance 1,2,3,4,5 might become 3,4,5,1,2. 
// Devise a way to find an element in the rotated array in O(logn) time

#include<stdio.h>
int a[10],n,b[10];
int indexSmallestElement(){
    int i,index=0;
    for(i=0;i<n;i++){
        if(a[index]>a[i])
            index=i;
    }
    return index;
}
void reverseArray(){
    int pivot=indexSmallestElement(),i=0;
    int copyPivot=pivot;
    do{
        b[i]=a[pivot];
        i++;
        pivot=(pivot+1)%n;
    }while(pivot!=copyPivot);
    // printf("Printing sorted array\n");
    // for(i=0;i<n;i++){
    //     printf("%d\t",b[i]);
    // }
}
void inputArray(){
    int i;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    // printf("Printing the input array\n");
    // for(i=0;i<n;i++){
    //     printf("%d\t",a[i]);
    // }
}
int binarySearch(int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (b[mid] == x)
			return mid;
		if (b[mid] > x)
			return binarySearch(l, mid - 1, x);
		return binarySearch(mid + 1, r, x);
	}
	return -1;
}
void searchKey(){
    int key,keyIndex;
    printf("Enter the search key\n");
    scanf("%d",&key);
    keyIndex=binarySearch(0,n-1,key);
    if(keyIndex)
        printf("Element %d found at position %d.\n",key,keyIndex);
    else
        printf("Element %d  not found.\n",key);
}
int main(){
    inputArray();
    reverseArray();
    searchKey();
    return 0;
}