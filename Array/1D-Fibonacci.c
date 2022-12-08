//Fibonacci With Array

#include<stdio.h>
#define MAX 100
int main()
{
	int arr[MAX],arrSize,i;
	printf("\nEnter Array Size:");
	scanf("%d",&arrSize);
	arr[0]= 0;
	arr[1]= 1;
	for(i = 2;i<arrSize;i++)
	{
		arr[i]= arr[i-2] + arr[i-1];
	}
	printf("\nFibonacci:");
	for(i=0;i<arrSize;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}
