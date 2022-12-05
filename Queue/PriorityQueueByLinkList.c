# include<stdio.h>  
# include<stdlib.h> 
  
typedef struct node  
    {  
    int priority;  
    int info;  
    struct node *link;  
}NODE;  
NODE *front = NULL;  
  
 
void insertNode(int data,int priority)  
{  
    NODE *temp,*q;  
  
    temp = (NODE *)malloc(sizeof(NODE));  
    temp->info = data;  
    temp->priority = priority;   
    if( front == NULL || priority < front->priority )
    {  
        temp->link = front;  
        front = temp;  
    }  
    else  
    {  
        q = front;  
        while( q->link != NULL && q->link->priority <= priority )  
            q=q->link;  
        temp->link = q->link;  
        q->link = temp;  
    }  
}  
    
void delNode()  
{  
    NODE *temp;   
    if(front == NULL)  
        printf("Queue Underflow\n");  
    else  
    {  
        temp = front;  
        printf("Deleted item is %d\n", temp->info);  
        front = front->link;  
        free(temp);  
    }  
}
  
 
void displayNode()  
{  
    NODE *ptr;  
    ptr = front;  
    if(front == NULL)  
        printf("Queue is empty\n");  
    else  
    {     
        printf("Queue is :\n");  
        printf("Priority       Data\n");  
        while(ptr != NULL)  
        {  
            printf("%d        %d\n",ptr->priority,ptr->info);  
            ptr = ptr->link;  
        }  
    }  
}  
 
  
int main()  
{  
    int choice, data, priority;  
    
	printf("Priority Order : Low Number High Priority\n");
	while(1) 
    {  
    	printf("= = Menu = =\n"); 
        printf("1.Insert\n");  
        printf("2.Delete\n");  
        printf("3.Display\n");  
        printf("4.Quit\n");  
        printf("Enter your choice : ");  
        scanf("%d", &choice);  
        switch(choice)  
        {  
            case 1: printf("Enter the data which is to be added in the queue : ");  
                	scanf("%d",&data);  
                	printf("Enter its priority : ");  
                	scanf("%d",&priority);  
                	insertNode(data,priority);  
                	break;  
            case 2: delNode();  
                	break;  
            case 3: displayNode();  
                	break;  
            case 4: exit(1);  
            
			default:printf("Wrong choice\n");  
        }  
    }  
  
    return 0;  
} 
