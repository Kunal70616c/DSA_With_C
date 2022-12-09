#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void swap(int *el1, int *el2)
{
	int temp= *el1;
	*el1 = *el2;
	*el2 = temp;
}

int partition(int arr[],int low, int high)
{
	int pivot = arr[low]; 
	int i = low;
	int j = high;
	int temp;
	while(i<j)
	{
		while(arr[i] <= pivot)
			i=i+1;
		while(arr[j]> pivot )
			j=j-1;
		if (i<j)
		{
			swap(&arr[i],&arr[j]);
		}
		swap(&arr[low],&arr[j]);
		return j ;
	}
}
void quickSort(int arr[],int low,int high)
{		
	int pivot;
	if(low < high)
	{	
		pivot = partition(arr ,low , high);
		quickSort(arr,low, pivot);
		quickSort(arr,pivot+1, high);
	}

}

	
int main()
{
	int arr[MAX],size,j,i;
	int low = 0;
	
	printf("\n Enter Size Of Array:");
	scanf("%d",&size);
	for(j = 0; j < size ; j++)
	{
		printf("\n Enter %d th Element:",j);
		scanf("%d",&arr[j]);
	}
	int high = size-1;
	printf(" Input Array ==>> ");
	for(i = 0;i< size; i++)
	{
		printf("%d ",arr[i]);
	}
	

	printf("\n Sorted Input Array ===>> ");

	quickSort(arr,low,high);
	
	for(i = 0;i< size; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}

