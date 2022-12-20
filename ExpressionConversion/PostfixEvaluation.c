#include<stdio.h>
#include<String.h>
#include<Ctype.h>
#include<math.h>
#define MAX 100

int stack[MAX];
int top = -1;
int op1,op2;

void push(int x)
{
	stack[++top]= x;
}
char pop()
{
	if(top == -1)
	{
		printf("\nUnderFlow!");
		exit(0);
	}
	else 
	{
		return stack[top--];	
	}	
}


int main()
{
	char exp[MAX];
	int i,data,res;
	printf("\nEnter Postfix Exp. To Evaluate::");
	scanf("%s",exp);
	for(i=0;exp[i]!='\0';i++)
	{
		if(isalpha(exp[i]))
		{
			printf("\n Enter Value Of --%c =",exp[i]);
			scanf("%d",&data);
			push(data);
		}
		else
		{
			op2 = pop();
			op1 = pop();
			switch(exp[i])
			{
				case '+':	res = op1+op2;
							push(res);
							break;
				case '-':	res = op1-op2;
							push(res);
							break;
				case '*':	res = op1*op2;
							push(res);
							break;
				case '/':	res = op1/op2;
							push(res);
							break;
				case '%':	res = op1%op2;
							push(res);
							break;
				case '^':	res = pow(op1,op2);
							push(res);
							break;
			}
		}		
	}
		printf("\n Result = %d",stack[0]);
	return 0;
}
