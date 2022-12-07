/*Input an array of n elements and an item from the user. 
Delete the occurrences of the element from the array. Display “Item not found” otherwise.*/

#include<stdio.h>
#define MAX 50

int main()
{
	int arr[MAX],i,j,l,n,data;
	printf("\nEnter Size Of array(<50):");
	scanf("%d",&n);
	for(i = 0 ; i < n ; i++)
	{
		printf("\n Enter Arr[%d] =",i);
		scanf("%d",&arr[i]);
	}
	printf("\n Entered Array>>>");
	for(i = 0 ; i < n ; i++)
	{
		printf("%d ",arr[i]);
		
	}
	printf("\n Entered Data You Want To Find & Delete>>>");
	scanf("%d",&data);
	l = n;
	
	for(i = 0 ;i < n;i++)
	{
		if(arr[i] == data)
		{
			for(j=i;j<l;j++)
				arr[j] = arr[j+1];
			l--;
		}
		else
		{
			printf("\n Item Not Found");
			exit(0);
		}
	}
	printf("\n Filtered Array>>>");
	for(i = 0 ; i < l ; i++)
	{
		printf("%d ",arr[i]);
		
	}
	return 0;
}

