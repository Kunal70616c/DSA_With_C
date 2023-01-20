#include<stdio.h>
#include<stdlib.h>



struct node
{
	int info;
	struct node *lc,*rc;
};
typedef struct node bst;

int max,min;


void create(bst*);
void preorder(bst*);
void inorder(bst*);
void postorder(bst*);
void leaves(bst*);
void search(bst*,int);
void max_min(bst*);


int main()
{
	bst *root=NULL,*ptr;
	int ch,l,se,i,x;
	printf("\n Enter Data For Root :: ");
	ptr=(bst*)malloc(sizeof(bst));
	scanf("%d",&ptr->info);
	ptr->lc=ptr->rc=NULL;
	root=ptr;
	create(root);
	while(1)
	{
		printf("\n**MENU**");
		printf("\n1. Inorder\n2. Preorder\n3. Postorder\n4. Find leaf \n5. Search\n6. Max and Min Element \n6. Exit\n");
		printf("\n===>>: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: inorder(root);
					break;		
			case 2: preorder(root);
					break;
			case 3: postorder(root);
					break;
			case 4: printf("\n leaf Nodes :: ");
					leaves(root);
					fflush(stdin);
					printf("\n Number Of Leaf :: %d",c);
					break;
			case 5: printf("\nEnter Search node:\n");
					scanf("%d",&se);
					search(root,se);
					if(k==1)
					{
						k=0;
						printf("\nElement found\n");
					}
					else if(k==0)
					{
						printf("\nElement not found\n");
					}
					break;
			case 6: max=root->info;
					min=root->info;
					max_min(root);
					printf("Max Element :: %d",max);
					printf("Min Element :: %d",min);
					break;
				
			case 7: exit(0);
		}
	}
}

void create(bst *root)
{
	int ans;
	bst *ptr,*x,*y;
	while(1)
	{
		ptr=(bst*)malloc(sizeof(bst));
		printf("\nEnter Data");
		scanf("%d",&ptr->info);
		ptr->lc=ptr->rc=NULL;
		if(root==NULL)
			root=ptr;
		else
		{
			x=root;
			while(x!=NULL)
			{
				y=x;
				if(ptr->info < x->info)
					x=x->lc;
				else
					x=x->rc;
			}
			if(ptr->info < y->info)
				y->lc=ptr;
			else
				y->rc=ptr;
		}
		printf("\nContinue(1/0)? :: ");
		scanf("%d",&ans);
		if(ans==0)
			break;
	}
}

void preorder(bst *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->info);
	preorder(root->lc);
	preorder(root->rc);
}

void inorder(bst *root)
{
	if(root==NULL)
		return;
	inorder(root->lc);
	printf("%d ",root->info);
	inorder(root->rc);
}

void postorder(bst *root)
{
	if(root==NULL)
		return;
	postorder(root->lc);
	postorder(root->rc);
	printf("%d ",root->info);
}

void leaves(bst *root)
{
	if(root==NULL)
		return;
	if(root->lc==NULL && root->rc==NULL)
	{
		c++;
		printf("%d ",root->info);
	}
	leaves(root->lc);
	leaves(root->rc);
}
void search(bst *root,int se)
{
	if(root==NULL)
		return;
	if(root->info==se)
	{
		k=1;
		return;
	}
	search(root->lc,se);
	search(root->rc,se);
}

void max_min(bst *root)
{
	if(root==NULL)
		return;
	if(root->info>max)
		max=root->info;
	if(root->info<min)
		min=root->info;
	max_min(root->lc);
	max_min(root->rc);
}


