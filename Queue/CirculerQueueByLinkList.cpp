#include <stdio.h>  
#include<conio.h>
#include<stdlib.h>
 
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *front=NULL;  
struct node *rear=NULL;  

  
void enqueue(int x)  
{  
    struct node *newnode; 
    newnode=(struct node *)malloc(sizeof(struct node));  
    newnode->data=x;  
    newnode->next=0;  
    if(rear==NULL)  
    {  
        front=rear=newnode;  
        rear->next=front;  
    }  
    else  
    {  
        rear->next=newnode;  
        rear=newnode;  
        rear->next=front;  
    }  
}  
  

void dequeue()  
{  
    struct node *temp;   
    temp=front;  
    if((front==NULL)&&(rear==NULL))  
    {  
        printf("\nQueue is empty");  
    }  
    else if(front==rear)  
    {  
    	printf("\n Element Removed :%d",front->data);
        front=rear=NULL;  
        free(temp);  
    }  
    else  
    {
		printf("\n Element Removed :%d",front->data);  
        front=front->next;  
        rear->next=front;  
        free(temp);  
    }  
}  
  
void display()  
{  
    struct node *temp;  
    temp=front;  
    printf("\n The elements in a Queue are : ");  
    if((front==NULL) && (rear==NULL))  
    {  
        printf("Queue is empty");  
    }  
  
    else   
    {  
        while(temp->next!=front)  
        {  
            printf("%d,", temp->data);  
            temp=temp->next;  
        }  
        printf("%d", temp->data);  
    }  
}  
  
int main()
{
	int data,ch;
	while(1)
	{
		printf("\nEnter 1 For Enq// 2 for deq // 3 for display:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter The Data:");
					scanf("%d",&data);
					enqueue(data);
					break; 
			case 2: dequeue();
					break;
			case 3: display();
					break;
		}	
	}
	return 0;
}
