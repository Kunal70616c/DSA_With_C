#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *lc,*rc;
};
typedef struct node bin_tere;

int leaf=0,max,min,element,f=0;
int pre[60],post[60],in[60];
int ic=0,pc=0,poc=0;

void create(bin_tere*);
void preorder(bin_tere*);
void inorder(bin_tere*);
void postorder(bin_tere*);
void count(bin_tere*);
void maxmin(bin_tere*);
void search(bin_tere*);
void inSuc(bin_tere*);
void preSuc(bin_tere*);
void posSuc(bin_tere*);
int height(bin_tere*);
void mirror(bin_tere*);

int main()
{
	bin_tere *root=NULL,*ptr;
	int ch,n,i,j=0,len=0;
	printf("\nEnter the information for the root :: ");
	ptr=(bin_tere*)malloc(sizeof(bin_tere));
	scanf("%d",&ptr->info);
	ptr->lc=ptr->rc=NULL;
	root=ptr;
	create(root);
	while(1)
	{
		printf("\n**MENU**");
		printf("\n1. Preorder-Inorder-Postorder \n2.Count & Print Leaf \n3.Display Minimum & Maximum Number \n4.Search \n5. Inorder Successor \n6. Postorder Successor\n7. Preorder Successor\n8. Inorder Predicessor \n9. Postorder Predicessor \n10. Preorder Predicessor \n11. Height of The Tree \n12. Exit");
		printf("\nEnter your choice :: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nInorder:");     
					inorder(root);
					printf("\nPreorder:");
					preorder(root);
					printf("\nPostorder:");
					postorder(root);
					break;
			case 2: count(root);
					printf("\n Number of leaf Node :: %d",leaf);
					break;
			case 3: max=root->info;
					min=root->info;
					maxmin(root);
					printf("\n Max Element :: %d || Min Element :: %d",max,min);
					break;
			case 4: printf("\nEnter data to Search :: ");
					scanf("%d",&element); 
					search(root);
					if(f>0)
					{
						printf("\n Item Found!");
						f=0;
					}
					else
					{
						printf("\n Item Not Found!");
						f=0;
					}
					break;
			case 5: printf("\nEnter the value ::");
					scanf("%d",&n);
				 	inSuc(root);
				 	j=0;
				 	len=ic;
				 	for(i=0;i<len;i++)
				 	{
				 	
				 		if(in[i]==n)
				 		{
							j=1;
							break;
						}
				 	}
				 	if(j==1)
				 	{
				 		printf("%d",i);
				 		if(i==len-1)
					 		printf("\n No Successor");
				 		else
					 		printf("\n The successor of %d is %d",n,in[i+1]);
				 	}
				 	else
				 			printf("\n No Node Avail.");
				 			break;
			case 6:	printf("\n Enter the value ::");
					scanf("%d",&n);
				 	posSuc(root);
				 	j=0;
				 	len=poc;
				 	for(i=0;i<len;i++)
				 	{
				 		if(post[i]==n)
				 		{
							j=1;
						 	break;
						}
				 	}
				 	if(j==1)
					{
				 		if(i==len-1)
				 			printf("\n No Successor");
				 		else
				 			printf("\n The successor of %d is %d",n,post[i+1]);
				 	}
				 	else
				 		printf("\n No Node Avail.");
				 		break;
			case 7:	printf("\nEnter the value ::");
					scanf("%d",&n);
				 	preSuc(root);
				 	j=0;
				 	len=pc;
				 	for(i=0;i<len;i++)
					{
				 		if(pre[i]==n)
				 		{
							j=1;
						 	break;
						}
				 	}
				 	if(j==1)
					{
				 		if(i==len-1)
				 			printf("\n No Successor");
				 		else
				 			printf("\n The successor of %d is %d",n,pre[i+1]);
				 	}
				 	else
						printf("\n No Node Avail.");
				 		break;
			case 8:	printf("\nEnter the value ::");
				 	scanf("%d",&n);
				 	inSuc(root);
				 	j=0;
				 	len=ic;
				 	for(i=0;i<len;i++)
				 	{	
				 		if(in[i]==n)
				 		{
							j=1;
							break;
						}
				 	}
				 	if(j==1)
				 	{
				 		printf("%d",i);
				 		if(i==0)
					 		printf("\n No predicessorc");
				 		else
					 		printf("\n The predicessor of %d is %d",n,in[i-1]);
				 	}
				 	else
				 		printf("\n No predicessor");
				 		break;
			case 9:	printf("\nEnter the value ::");
				 	scanf("%d",&n);
				 	posSuc(root);
				 	j=0;
				 	len=poc;
				 	for(i=0;i<len;i++)
				 	{
				 		if(post[i]==n)
				 		{
							j=1;
						 	break;
						}
				 	}
				 	if(j==1)
					{
				 		if(i==0)
				 			printf("\n No predicessor");
				 		else
				 			printf("\nThe predicessor of %d is %d",n,post[i-1]);
				 	}
				 	else
				 		printf("\nNo Node Avail.");
				 		break;
			case 10:printf("\nEnter the value ::");
				 	scanf("%d",&n);
				 	preSuc(root);
					j=0;
				 	len=pc;
				 	for(i=0;i<len;i++)
				 	{
				 		if(pre[i]==n)
				 		{
							j=1;
							break;
						}
					}
				 	if(j==1)
					{
				 		if(i==0)
				 			printf("\n No predicessor");
				 		else
				 			printf("\n The predicessor of %d is %d",n,pre[i-1]);
				 	}
				 	else
				 		printf("\nNo Node Avail.");
				 		break;		
			case 11:printf("\n Height of the tree is %d",height(root));
					break;
			case 12: exit(0);
		}
	}
}

void create(bin_tere *root)
{
	char ans;
	bin_tere *ptr;
	printf("\nDo you want to create the left (/) child of %d? ",root->info);
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='Y' || ans=='y')
	{
		ptr=(bin_tere*)malloc(sizeof(bin_tere));
		printf("\nEnter the information for the left child: ");
		scanf("%d",&ptr->info);
		ptr->lc=ptr->rc=NULL;
		root->lc=ptr;
		create(root->lc);
	}
	else
		root->lc=NULL;
	printf("\nDo you want to create the right (\) child of %d? ",root->info);
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='Y' || ans=='y')
	{
		ptr=(bin_tere*)malloc(sizeof(bin_tere));
		printf("\nEnter the information for the right child: ");
		scanf("%d",&ptr->info);
		ptr->lc=ptr->rc=NULL;
		root->rc=ptr;
		create(root->rc);
	}
	else
		root->rc=NULL;
}

void preorder(bin_tere *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->info);
	preorder(root->lc);
	preorder(root->rc);
}

void inorder(bin_tere *root)
{
	if(root==NULL)
		return;
	inorder(root->lc);
	printf("%d ",root->info);
	inorder(root->rc);
}

void postorder(bin_tere *root)
{
	if(root==NULL)
		return;
	postorder(root->lc);
	postorder(root->rc);
	printf("%d ",root->info);
}

void count(bin_tere *root)
{
	if(root==NULL)
		return;
	else if(root->lc== NULL && root->rc==NULL)
	{
		leaf++;
		printf("%d ",root->info);
	}
	count(root->lc);
	count(root->rc);
}

void maxmin(bin_tere *root)
{
	if(root==NULL)
		return;
	else
	{
		if(max < root->info)
		{
			max = root->info;
		}
		else if(min > root->info)
		{
			min = root->info;
		}
	}
	maxmin(root->lc);
	maxmin(root->rc);
}

void search(bin_tere *root)
{
	if(root==NULL)
		return;
	else if(root->info==element)
	{
		f++;
	}
	search(root->lc);
	search(root->rc);
}

int height(bin_tere *root)
{
	if(root==NULL)
	return 0;
	
	int left_height = height(root->lc);
    int right_height = height(root->rc);
	
	return (left_height>right_height?left_height:right_height)+1;
	
}

void inSuc(bin_tere *root)
{
	if(root==NULL)
		return;
	inSuc(root->lc);
	in[ic++]=root->info;
	inSuc(root->rc);
}

void posSuc(bin_tere *root)
{
	if(root==NULL)
		return;
	posSuc(root->lc);
	posSuc(root->rc);
	post[poc++]=root->info;
}

void preSuc(bin_tere *root)
{
	if(root==NULL)
		return;
	pre[pc++]=root->info;
	preSuc(root->lc);
	preSuc(root->rc);
}
void mirror(bin_tere *root) 
{ 
    if (root == NULL) 
        return; 
    else
    { 
        bin_tere *temp; 
  
        mirror(root->lc); 
        mirror(root->rc); 
  
        temp        = root->lc; 
        root->lc  = root->rc; 
        root->rc = temp; 
    } 
} 

