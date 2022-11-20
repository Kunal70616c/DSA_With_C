#include<stdio.h>
#include<stdlib.h>
int front =-1 ;
int rear = -1;
int arr[5];	
void enq();
void deq();
void display();
int main()
{
	int ch;
	while(1)
	{
		printf("\nEnter 1 For Enq// 2 for deq // 3 for display:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enq();
					break; 
			case 2: deq();
					break;
			case 3: display();
					break;
		}	
	}
	return 0;
}

void enq()
{
		int data;
		printf("\nEnter data:");
		scanf("%d",&data);
		
	if (front == (rear+1)%10)
	{
		printf("\n OverFlow!");
		exit (1);
	}
	else if (front == -1 && rear == -1)
	{
		front = rear = 0;
		arr[rear]= data;
	}
	else
	{
		rear = (rear+1) % 10; 
		arr[rear]= data;							
	}
}

void deq()
{
	if(front == -1 && rear == -1)
	{
		printf("\n UndrFlow!");
		exit(1);
	}
	else if (front == rear)
	{
		front = rear = -1;		
	}
	front = front+1;	
}


void display()
{
	
	if(front == -1 && rear == -1)
	{
		printf("\n UndrFlow!");
		exit(1);
	}
	int i = front;
	for(i;i<=rear;i++)
	{
		printf("%d -",arr[i]);
	}
}

