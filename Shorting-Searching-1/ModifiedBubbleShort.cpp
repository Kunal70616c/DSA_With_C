#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int n = 5;
	int a[n], item,i,temp,j;
	int flag=1;
	for(i=0;i<n;i++)
	{
		printf("\nEnter Data of arr[%d]:",i+1);
		scanf("%d",&a[i]);
	}
	for(i=0; i<=n-1 && flag == 1; i++)
	{
		flag=0;
		for(j=0; j<n-i-1; j++)
		{
			if(a[j]>a[j+1])
			{
				flag = 1;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1]= temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
			printf("%d ",a[i]);
	}
	
	
}

