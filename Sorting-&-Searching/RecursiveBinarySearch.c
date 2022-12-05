#include <stdio.h>
#include<conio.h>

int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l)/2;
		if (arr[mid] == x) return mid;
		if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
		return binarySearch(arr, mid+1, r, x);
	}
	return -1;
}
int main()
{
	
	int i,x,size;
	printf("\nEnter Size Of The Array:");
	scanf("%d",&size);
	int arr[size];
	int n = sizeof(arr)/ sizeof(arr[0]);
	for(i=0;i<size;i++)
	{
		printf("\nEnter Data of arr[%d]:",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\nEnter Data You Want To Find:");
	scanf("%d",&x);
	
	
	int result = binarySearch(arr, 0, n-1, x);
	
	if(result == -1)
	
		printf("Element is not present in array");	
	
	else
	
		printf("Element is present at index %d", result+1);
	
	return 0;
}

