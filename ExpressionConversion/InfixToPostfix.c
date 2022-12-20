#include<stdio.h>
#include<String.h>
#include<Ctype.h>
#define MAX 100

char stack[MAX],postfix[MAX];
int top = -1 ,top2=-1;

void push(char x)
{
	stack[++top]= x;
}
char pop()
{
	if(top == -1)
		return -1;
	else 
	{
		return stack[top--];	
	}	
}

int prc(char x)
{
	if(x =='(')
		return 0;	
	else if(x == '^')
		return 3;
	else if(x =='*' || x =='/' || x=='%')
		return 2;
	else if(x =='+' || x =='-')
		return 1; 
}



int main()
{
	char exp[MAX];
	char *ptr,data;
	int i;

	printf("\n Enter Exp. =");
	scanf("%s",exp);
	ptr=exp;
	while(*ptr!='\0')
	{
		if(isalnum(*ptr))
			//printf("%c",*ptr);
			postfix[++top2]=*ptr;
		else if(*ptr=='(')
			push(*ptr);
		else if(*ptr==')')
		{
			while(1)
				{
					data = pop();
					if(data == '(' )
						break;	
					postfix[++top2]=data;
				}
		}
		else
		{
			while(prc(stack[top]) >= prc(*ptr))
			{
				data = pop();
				postfix[++top2]=data;
			}
			push(*ptr);
		}	
		ptr++;	
	}
	while(top!= -1)
	{
		data = pop();
		postfix[++top2]=data;	
	}
	printf("\nPostfix Exp -> \n");
	for(i=0;i<=top2;i++)
	{
		printf("%c",postfix[i]);
	}
	return 0;
}
