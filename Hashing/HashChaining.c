#include<stdio.h>
#include<stdlib.h>
#include<String.h>
 
int m;
 
typedef struct node
{
    int data;
    struct node *link;
}hash;
 
hash *a[100]={NULL},*la;
 
int HashFn(int k)
{
    return (k%m);
}
 
hash *getnode()
{
    hash *New;
    New=(hash *)malloc(sizeof(hash));
    New->data=NULL;
    New->link=NULL;
    return New;
}
 
void insert(int k)
{
    int h=HashFn(k);
    hash *N=getnode();
    N->data=k;
    if(a[h]==NULL)
    {
        a[h]=N;
    }
    else
    {
        la=a[h];
        while(la->link!=NULL)
        {
            la=la->link;
        }
        la->link=N;
    }
}
void search(int k)
{
    int h=HashFn(k);
    if(a[h] == NULL)
        printf("\n Search element not found\n");
    else
    {
        for(la=a[h];la!=NULL;la=la->link)
        {
            if(la->data == k)
                {
                    printf("Search Element found\n");
                    break;
                }
        }
        if(la==NULL)
            printf("\n Search element not found\n");
   
    }
}
 
void Delete(int k)
{
    hash *x,*y;
    int h=HashFn(k);
    if(a[h] == NULL)
        printf("\n Search element not found\n");
    else
    {
        la=a[h];
        x=la;
        while(la->data!=k)
        {
        	x=la;
        	la=la->link;
		}
		if(la==x && la->link!=NULL)
		{
			a[h]=la->link;
		}
		else
		{
			x->link=la->link;
        	free(la);
		}
    }
}
 
void printHash()
{
    int i;
    for(i=0;i<m;i++)
          {
           printf("\nentries at index %d\n",i);
               if(a[i] == NULL)
               {
               printf("No Hash Entry");
               
               }
               else
               {
                    for(la=a[i];la!=NULL;la=la->link)
                        printf("%d->",la->data);
               }
          }
         
}
int main()
{
    int i,n,ch;
    puts("enter m :");
    scanf("%d",&m);
    
    while(1)
    {
        puts("1>insert a key\n2> search key\n3> delete a key\n4>display the hash table\n5>exit\nenter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("enter the data :");
                scanf("%d",&n);
                insert(n);
            break;
            case 2:
                printf("the data you want ? :");
                scanf("%d",&n);
                search(n);
            break;
            case 3:
                printf("the data you want to delete ? :");
                scanf("%d",&n);
                Delete(n);
            break;
            case 4:
                printHash();
            break;
            case 5:
                exit(0);
            default:
                puts("invalid choice");
        }
    }
    return 0;
}

