#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100
int main()
{
	int arr[MAX];
	int item,n;
	printf("\nEnter Array Size:");
	scanf("%d",&n);
	int i,flag =0;
	int lb = 0; int ub = n-1;
	
	for(i=0;i<n;i++)
	{
		printf("\nEnter Data of arr[%d]:",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("\n Ender Value To find:");
	scanf("%d",&item);
	
	while(lb<=ub)
	{
		int mid = (lb+ub)/2;
		if (item == arr[mid])
		{
			flag = 1;
			printf("\n Found at %d",mid+1);
			exit(0);
		}
		else if(item < arr[mid])
		{
			ub = mid-1;
		}
		else 
			lb = mid+1;
	}
	if(flag == 0)
	{
		printf("\n Not Found ");
	}
	return 0;
}

