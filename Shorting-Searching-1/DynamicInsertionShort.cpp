#include <stdio.h>
#include <stdlib.h>

int main()
{

	int* arr;
	int n, i, v, j;

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
			for(i=1;i<=n;i++)
			{
				printf("\nEnter Data of arr[%d]:",i);
				scanf("%d",&arr[i]);
			}
			for(i=2;i<=n;i++)
			{
				v = arr[i];
				j = i-1;
				while(j>=1 && v<arr[j])
				{
					arr[j+1]=arr[j];
					j = j-1;
				}
				arr[j+1]= v;
			}
			
			
					
			printf("\nShorted Array >>>>");
			for(i=1;i<=n;i++)
			{
				printf("%d ",arr[i]);
			}
	}
	return 0;
}

