#include <stdio.h>
#include <stdlib.h>

int main()
{

	int* arr;
	int n, i;
	int min,pos;
	int item,temp,j;

	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Entered number of elements: %d\n", n);


	arr = (int*)malloc(n * sizeof(int));



	if (arr == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else 
	{
			printf("Memory successfully allocated using malloc.\n");
			for(i=0;i<n;i++)
			{
				printf("\nEnter Data of arr[%d]:",i+1);
				scanf("%d",&arr[i]);
			}
			for(i=0; i<=n-1; i++)
			{
				min = arr[i];
				pos = i;
				for(j=i+1;j<n;j++)
				{	
					if(arr[j]<min)
					{
						min = arr[j];
						pos = j;
					}
					temp = arr[i];
					arr[i] = arr[pos];
					arr[pos] = temp; 
				}
			}		
			printf("\nSorted Array >>>>");
			for(i=0;i<n;i++)
			{
				printf("%d ",arr[i]);
			}
	}
	return 0;
}

