 //Input an array of n random numbers within 100 (to be generated using rand() function and 
 //find their mean, median, mode, standard deviation & variance.
 //rand() % (max_number + 1 - minimum_number) + minimum_number
 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 50

void median(int arr[],int n)
{
	int i,temp;
	float median = 0;
	float mid=0;
	if(n%2 == 0)
	{
		int temp=(n/2)-1;
		for(i=0;i<n;i++)
		{	
			if(temp==i || (temp+1)==i)
			{
				mid=mid+arr[i];
			}
		}
		mid=mid/2;
		printf("\n Median value is: %.1f",mid);
	}
	else 
	{
		int temp=(n/2);
		for(i=0;i<n;i++)
		{
			if(temp==i)
			{
				int mid=arr[i];
				printf("\n Median value: %d",mid);
			}
		}
	}
}
void mode(int arr[],int n)
{
	int i, j,z, temp, maxCount, modeValue;
	int tally[n];
     for(i=0;i<n;i++)
         {
               for(j=0;j<n-i;j++)
               {
                     if(arr[j]>arr[j+1])
                     {
                           temp=arr[j];
                           arr[j]=arr[j+1];
                           arr[j+1]=temp;
                     }
               }
         }
    for (i = 0; i < n; i++) 
    {
        for(z=i+1;z<n;z++)
        {
            
            if(arr[i]==arr[z])
            {
                tally[i]++;
            }
        }
    }
    maxCount = 0;
    modeValue = 0;
    for (i = 1; i <= n; i++) 
    {
        if (tally[i] > maxCount) 
        {
            maxCount = tally[i];
            modeValue = arr[i];
        }
    }
    printf("\n Mode value is : %d", modeValue);
}


int main()
{
	int arr[MAX],n,i;
	int sum = 0,sum1 = 0;
	float average;
	printf("\nEnter Size Of array(<50):");
	scanf("%d",&n);
	for(i = 0 ; i < n ; i++)
	{
		arr[i]= rand() % (100 + 1 - 0) + 0;
		sum = sum + arr[i];
		printf("\n Added Arr[%d] = %d",i,arr[i]);
	}
	
	average = sum / (float)n;
	printf("\n ====Results====");
	
	//Mean calculation
	
	printf("\n Mean value is: %.1f ", sum/(float)n);
	
	//Median calculation   
	
	median(arr,n);

	// Mode calculation
	
	mode(arr,n);
	
	// Variance calculation
	
	 for (i = 0; i < n; i++)
    {
        sum1 = sum1 + pow((arr[i] - average), 2);
    }
    float variance = sum1 / (float)n;
	printf("\n Varience value is: %.1f ", variance);

	// Standard Devation calculation
	float std_deviation = sqrt(variance);
    printf("\n Standard deviation value is: %.2f\n", std_deviation);
	
	return 0;
}
