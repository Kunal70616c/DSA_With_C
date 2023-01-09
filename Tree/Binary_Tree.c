#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *lc,*rc;
};
typedef struct node bin_tere;

int leaf=0,max,min,element,f=0;

void create(bin_tere*);
void preorder(bin_tere*);
void inorder(bin_tere*);
void postorder(bin_tere*);
void count(bin_tere*);
void maxmin(bin_tere*);
void search(bin_tere*);


int main()
{
	bin_tere *root=NULL,*ptr;
	int ch;
	printf("\nenter the information for the root: ");
	ptr=(bin_tere*)malloc(sizeof(bin_tere));
	scanf("%d",&ptr->info);
	ptr->lc=ptr->rc=NULL;
	root=ptr;
	create(root);
	while(1)
	{
		printf("\n**MENU**");
		printf("\n1. Preorder-Inorder-Postorder \n2.Count & Print Leaf \n3.Display Minimum & Maximum Number \n4.Search \n5. exit");
		printf("\nenter your choice: ");
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
			case 5: exit(0);
		}
	}
}

void create(bin_tere *root)
{
	char ans;
	bin_tere *ptr;
	printf("\nDo you want to create the left child of %d? ",root->info);
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='Y' || ans=='y')
	{
		ptr=(bin_tere*)malloc(sizeof(bin_tere));
		printf("\nenter the information for the left child: ");
		scanf("%d",&ptr->info);
		ptr->lc=ptr->rc=NULL;
		root->lc=ptr;
		create(root->lc);
	}
	else
		root->lc=NULL;
	printf("\nDo you want to create the right child of %d? ",root->info);
	fflush(stdin);
	scanf("%c",&ans);
	if(ans=='Y' || ans=='y')
	{
		ptr=(bin_tere*)malloc(sizeof(bin_tere));
		printf("\nenter the information for the right child: ");
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
