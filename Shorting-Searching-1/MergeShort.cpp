#include <stdio.h>
#include <stdlib.h>


void simpleMerge(int *arr,int lb,int mid,int ub)
{
    int i,j,k,n=ub;
    int b[n];
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            b[k]=arr[i];
            i++;
        }
        else
        {
            b[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i > mid)
    {
        while(j<=ub)
        {
            b[k]=arr[j];j++;k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k]=arr[i];i++;k++;
        }
    }
    for(k=lb;k<=ub;k++)
    {
        arr[k]=b[k];
    }
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}



void mergeSort(int *arr,int lb, int ub)
{
	if (lb < ub)
	{
		
		int mid = lb + (ub - lb) / 2;
		mergeSort(arr, lb, mid);
		mergeSort(arr, mid + 1, ub);
		simpleMerge(arr, lb, mid, ub);
	}
}


int main()
{
	int arr[10],size,j;
	
	printf("\n Enter Size Of Array:");
	scanf("%d",&size);
	for(j = 0; j < size ; j++)
	{
		printf("\n Enter %d -th Element:",j);
		scanf("%d",&arr[j]);
	}

	printf("Given array is \n");
	printArray(arr, size);

	mergeSort(arr, 0, size - 1);

	printf("\nSorted array is \n");
	printArray(arr, size);
	return 0;
}

