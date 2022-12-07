//Input an array of n elements remove all duplicate elements and print the new array.//

#include<stdio.h>
#define MAX 50

int main()
{
	int arr[MAX],i,j,k,n,data;
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
	for(i = 0 ;i < n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i] == arr[j])
			{
				for(k=j;k<n-1;k++)
				{
					arr[k] = arr[k+1];
				}
				n--;
				j--;
			}
			
		}	
	}
	printf("\n Filtered Array>>>");
	for(i = 0 ; i < n ; i++)
	{
		printf("%d ",arr[i]);
		
	}
	return 0;
}

