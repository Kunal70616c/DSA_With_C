#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main()
{
	
	int n = 5,min,pos;
	int a[n], item,i,temp,j;
	for(i=0;i<n;i++)
	{
		printf("\nEnter Data of arr[%d]:",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0; i<=n-1; i++)
	{
		min = a[i];
		pos = i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<min)
			{
				min = a[j];
				pos = j;
			}
			temp = a[i];
			a[i] = a[pos];
			a[pos] = temp; 
		}
	}
	printf("\nShorted Array >>>>");
	for(i=0;i<n;i++)
	{
			printf("%d ",a[i]);
	}
	
	return 0;
}

