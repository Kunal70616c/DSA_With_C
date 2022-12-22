#include<stdio.h>
#include<String.h>
#include<Ctype.h>
#define MAX 100

char stack[MAX],prefix[MAX];
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
	if(x ==')')
		return 0;	
	else if(x == '^')
		return 3;
	else if(x =='*' || x =='/' || x=='%')
		return 2;
	else if(x =='+' || x =='-')
		return 1; 
}

//int isChar(char x)
//{
//	if(x>='A' && x<='Z')
//		return 1;
//	else
//		return 0;
//}

int main()
{
	char exp[MAX];
	char *ptr,data;
	int i;

	printf("\n Enter Exp. =");
	scanf("%s",exp);
	strrev(exp);
	ptr=exp;
	while(*ptr!='\0')
	{
		if(isalnum(*ptr))
			//printf("%c",*ptr);
			prefix[++top2]=*ptr;
		else if(*ptr==')')
			push(*ptr);
		else if(*ptr=='(')
		{
			while(1)
				{
					data = pop();
					if(data == ')' )
						break;	
					prefix[++top2]=data;
				}
		}
		else
		{
			while(prc(stack[top]) > prc(*ptr))
			{
				data = pop();
				prefix[++top2]=data;
			}
			push(*ptr);
		}	
		ptr++;	
	}
	while(top!= -1)
	{
		data = pop();
		prefix[++top2]=data;	
	}
	printf("\nPrefix Exp -> \n");
		printf("%s",strrev(prefix));
	return 0;
}
