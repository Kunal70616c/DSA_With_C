#include<stdio.h>
#include<stdlib.h>

int m=11;
int c =1;
 
int hashFun(int k,int i)
{
    return ((k+(i*c))%m);
}
 
int isFull(int *a)
{
    int i,f=0;
    for(i=0;i<m;i++)
    {
        if(a[i]!=-1)
        {
            f++;
        }
    }
    if(f==0)
    return 1;
    else
    return 0;
}
 
int isEmpty(int *a)
{
    int i,f=0;
    for(i=0;i<m;i++)
    {
        if(a[i]==-1)
        {
            f++;
        }
    }
    if(f==m+1)
    return 1;
    else
    return 0;
}
void printHash(int *a)
{
    int i;
    printf("#-Index\t\tData\n");
    for(i=0;i<m;i++)
    {
        
        if(a[i]==-1)
        printf("%d\t\t---\n",i);
        else
        printf("%d\t\t%d\n",i,a[i]);
    }
} 
 
void insert(int *a,int k)
{
    int i=0;
    int h=hashFun(k,i);
    while (a[h]!=-1)
    {
        if(isFull(a)==1)
        {
            printf("\n No Space // Space Full");
            break;
        }
        i++;
        h=hashFun(k,i);
    }
    a[h]=k;
    printf("\n Data Added\n");
    
}
 
void searchKey(int *a,int n1)
{
    int i=0;
    int h=hashFun(n1,i);
    while (a[h]!=n1)
    {
        i++;
        h=hashFun(n1,i);
    if(a[h]==n1)
    {
        printf("the data is present at position%d\n",h);
    }
    else
    {
        printf("not found !\n");
        break;
    }
    }
}
 
void deleteKey(int *a,int n1)
{
    int i=0;
    int h=hashFun(n1,i);
    while (a[h]!=n1)
    {
        if(isEmpty(a)==1)
        {
            printf("\n No Space ");
            break;
        }
        i++;
        h=hashFun(n1,i);
    }
    if(a[h]==n1)
    {
        a[h]=-1;
        printf("\nDeleted\n");
    }
    else
    {
        printf("\nData Not Found!\n");
    }
}
 
int main()
{
    int *a,i,n,ch;
    a=(int*) calloc(m,sizeof(int));
    
    for(i=0;i<m;i++)
    {
        a[i]=-1;
    }
    while(1)
    {
        printf("\n====MENU====\n1==>Insert\n2==>Search\n3==>Delete\n4==>Display\n5==>Exit\n Enter Your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter data :");
                	scanf("%d",&n);
                	insert(a,n);
                	printHash(a);
            		break;
            case 2: printf("\n Search The Data/Key :");
                	scanf("%d",&n);
               		searchKey(a,n);
            		break;
            case 3: printf("\n Data You Want to Delete :");
                	scanf("%d",&n);
                	deleteKey(a,n);
            break;
            case 4: printHash(a);
            		break;
            case 5:  exit(0);
            default: printf("\n Wrong Choice Man :( )");
        }
    }
    return 0;
}
