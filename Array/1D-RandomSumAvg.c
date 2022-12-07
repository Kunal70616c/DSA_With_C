//Input n random numbers between 0 and 1 (using rand() function) and find their sum and average.

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int main()
{
	int arr[MAX],n,i;
	int sum = 0;
	float average;
	printf("\nEnter Size Of array(<10):");
	scanf("%d",&n);
	for(i = 0 ; i < n ; i++)
	{
		arr[i]= rand() % (1 + 1 - 0) + 0;
		sum = sum + arr[i];
		printf("\n Added Arr[%d] = %d",i,arr[i]);
	}
	average= (float) sum/n;
	printf("\n Sum= %d",sum);
	printf("\n Avarage= %.2f",average);
	return 0;
}
