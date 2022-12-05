#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int count(int *arr) 
{
  	int c = 0, i;
	for (i = 0; i < MAX; i++)
	{
    	if (arr[i] != 0)
      		c++;
  	}
  return c;
}

void addFront(int *arr, int item, int *pfront, int *prear) 
{
  int i, k, c;
  if (*pfront == 0 && *prear == MAX - 1) 
  {
     printf("\nDeque is full.\n");
     return;
  }
  if (*pfront == -1) 
  {
	 *pfront = *prear = 0;
     arr[*pfront] = item;
     return;
  }
  if (*prear != MAX - 1) 
  {
     c = count(arr);
     k = *prear + 1;
    for (i = 1; i <= c; i++) 
	{
      arr[k] = arr[k - 1];
      k--;
    }
    	arr[k] = item;
    	*pfront = k;
    	(*prear)++;
    } 
  else 
  {
     (*pfront)--;
     arr[*pfront] = item;
  }
}

void addRear(int *arr, int item, int *pfront, int *prear) 
{
  	int i, k;
	if (*pfront == 0 && *prear == MAX - 1) 
	{
    	printf("\nDeque is full.\n");
    	return;
    }
	if (*pfront == -1) 
	{
   		*prear = *pfront = 0;
    	arr[*prear] = item;
    	return;
    }
	if (*prear == MAX - 1) 
	{
    	k = *pfront - 1;
    	for (i = *pfront - 1; i < *prear; i++) 
		{
      	k = i;
      	if (k == MAX - 1)
        	arr[k] = 0;
      	else
        	arr[k] = arr[i + 1];
    	}
    	(*prear)--;
    	(*pfront)--;
   }
  	(*prear)++;
  	arr[*prear] = item;
}

int delFront(int *arr, int *pfront, int *prear) 
{
	int item;

	if (*pfront == -1) 
	{
    	printf("\nDeque is empty.\n");
    	return 0;
    }

  	item = arr[*pfront];
  	arr[*pfront] = 0;
	if (*pfront == *prear)
    	*pfront = *prear = -1;
  	else
    	(*pfront)++;

  	return item;
}

int delRear(int *arr, int *pfront, int *prear) 
{
  	int item;
	if (*pfront == -1) 
	{
    	printf("\nDeque is empty.\n");
    	return 0;
  	}

  	item = arr[*prear];
  	arr[*prear] = 0;
  	(*prear)--;
  	if (*prear == -1)
    	*pfront = -1;
  	return item;
}

void display(int *arr) 
{
  	int i;
  	for (i = 0; i < MAX; i++)
    	printf("  %d", arr[i]);
}

int main() 
{
  int arr[MAX];
  int front, rear, i, n;
  int ch,x;
  front = rear = -1;
  while(1)
	{
		printf("\n1->Insert (Rear)\n2->Insert (Front)\n3->Delete (Rear)\n4->Delete(Front)\n5->Display\n6->Count\n7->Exit\n");
		printf("Enter choice >>>>>>");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter Data:");
					scanf("%d",&x);
					addRear(arr, x, &front, &rear);
					break;
			case 2: printf("\nEnter Data:");
					scanf("%d",&x);
					addFront(arr, 5, &front, &rear);
					break;
			case 3: i = delRear(arr, &front, &rear);
  					printf("\nRemoved item: %d", i);
					break;
			case 4: i = delFront(arr, &front, &rear);
  					printf("\nRemoved item: %d", i);
					break;
			case 5: display(arr);
					break;
			case 6: n = count(arr);
  					printf("\nTotal number of elements in deque: %d", n);
					break;
					
			case 7: exit(0);			
			
			default:printf("Wrong Choice\n");
		}
	}

  
}

	

 

