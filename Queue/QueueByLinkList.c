#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node n;
n *f=NULL;
n *r=NULL;

void display()
{
	n *x;
	if(f == NULL && r == NULL)
	{
		printf("\nQueue Empty!");
		return;
	}
	x=f;
	while(x != NULL)
	{
		printf("%d -",x->data);
		x=x->next;
	}
}

void enq()
{
	n*ptr;
	ptr=(n*) malloc(sizeof(n));
	printf("\nEnter Data: ");
	scanf("%d",&ptr->data);
	ptr->next=NULL;
	if(f==NULL && r == NULL)
	{
		f=ptr;
		r=ptr;
	}
	else
	{
		r->next= ptr;
		r=ptr;
	}
}

void dq()
{
	n* x;
	if(f == NULL && r == NULL)
	{
		printf("\nQueue Empty!");
		return;
	}
	x=f;
	if(f == r)
		f=r=NULL;
	else
		f=f->next;
	printf("\nData Removed %d",x->data);
	free(x);
}

int main()
{
	int c;
	while(1)
	{
		printf("\nOptions:\n 1-enqueue \n 2-dequeue \n 3-Display\n 4-exit \n ====>");
		scanf("%d",&c);
		switch(c)
		{
			case 1: enq();
				break;
			case 2: dq();
				break;
			case 3: display();
				break;
			case 4: exit(0);
				break;
		}
	}
	return 0;
}


