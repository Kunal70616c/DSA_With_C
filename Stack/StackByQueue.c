#define MAX 10
#include<stdio.h>
#include<stdlib.h>
int f=-1,r=-1;
int queue[MAX];
void display()
{
	int i = 0;
	for(i=f;i<=r;i++)
	{
		printf("%d -",queue[i]);
	}
}
void enqueue()
{
	int n;
	printf("\nEnter Data To Insert In The Queue:");
	scanf("%d",&n);
	if(f==MAX || r== MAX)
	{
		printf("\nOverflow!");
		exit(1);
	}
	if(f==-1 && r==-1)
	{
		f=r=0;
		queue[r] = n;	
		printf("\nData Added!");
	}
	else
	{
		r= r+1;
		queue[r] = n;
		printf("\nData Added!");
	}
}
void dequeue()
	{
		if(f ==-1 && r == -1)
		{
			printf("\nQueue Empty!");
			exit(1);
		}
		else if(f == r)
		{
			printf("%d is removed",queue[f]);
			f = r =-1;
		}
		else
		{
			printf("%d is removed",queue[r]);
			r = r-1;
		}

	}


int main()
{
	int c;
	while(1)
	{
		printf("\n===Menu===\n1->Push in Stack\n2->Pop from Stack \n3->Display\n4->Exit \n ====>");
		scanf("%d",&c);

		switch(c)
		{
			case 1: enqueue();
				break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: exit(0);
				break;
		}
	}
	return 0;
}
