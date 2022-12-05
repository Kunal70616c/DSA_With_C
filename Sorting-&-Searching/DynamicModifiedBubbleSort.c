#include <stdio.h>
#include <stdlib.h>

int main()
{

	int* arr;
	int n, i;
	int item,temp,j;
	int flag=1;

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
		for(i=0; i<=n-1 && flag == 1; i++)
		{
			flag=0;
			for(j=0; j<n-i-1; j++)
			{
				if(arr[j]>arr[j+1])
				{
					flag = 1;
					temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1]= temp;
				}
			}
		}
		for(i=0;i<n;i++)
		{
				printf("%d ",arr[i]);
		}
	}
	return 0;
}

