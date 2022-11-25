#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 10

int indx = -1;

struct pqueue
{
	int data;
	int order;
};
struct pqueue pq[MAX];

void enqueue(int data, int priority)
{
	if(indx == MAX -1)
	{
		printf("\nQueue FULL!!");
		exit (1);
	}	
	else
	{
		indx++;
		pq[indx].data = data;
		pq[indx].order = priority;
	}
}

int peek()
{
	int maxPriority = INT_MIN , indxPos= -1;
	for(int i = 0; i<=indx;i++)
	{
		if(maxPriority < pq[i].order) 
		{
            maxPriority = pq[i].order;
            indxPos = i;
		}
	}
	return indxPos;
}

void dequeue()
{
    if(indx == -1)
    {
		printf("\nQueue Empty!!");
		exit(1);
	}
    else
    {
    	int indxPos = peek();
    	for(int i = indxPos; i < indx; i++) 
		{
            pq[i] = pq[i + 1];
            
        }

        indx--;
    }
    	
}
        
void display()
{
	if(indx == -1)
    {
		printf("\nQueue Empty!!");
		exit(1);
	}
    for (int i = 0; i <= indx; i++) 
	{
        printf("(%d, %d)\n",pq[i].data, pq[i].order);
    } 
}

int main()
{
	int c,dpeek;
	int n,p;
	while(1)
	{
		printf("\n Options:\n 1->Enqueue | 2->Dequeue | 3-Display | 4->Peek | 5->Exit \n ====>");
		scanf("%d",&c);

		switch(c)
		{
			case 1: printf("\n Enter Data To Insert In The Queue:");
					scanf("%d",&n);
					printf("\n Enter Priority Of the entered Data :");
					scanf("%d",&p);
					enqueue(n , p);
					break;
			case 2: dequeue();
				break;
			case 3: display();
				break;
			case 4: dpeek = peek();
					printf("Peek >_< = (%d , %d)",pq[dpeek].data,pq[dpeek].order);
				break;
			case 5: exit(0);
				break;
		}
	}
	return 0;
}
