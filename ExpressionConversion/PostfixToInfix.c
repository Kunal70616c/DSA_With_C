#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char S[50][50],res[50];
int top=-1;

void push(char *c)
{
	strcpy(S[++top],c);
}

void pop()
{
	strcpy(res,S[top--]);
}
void clear(char *c)
{
	int i,j=strlen(c);
	for(i=0; i<j;i++)
	{
		c[i]='\0';
	}
}

int main()
{
	char exp[50],temp[50],b1[]="(",b2[]=")",op1[50],op2[50];
	char ptr[50];
	clear(ptr);
	int i;
	puts("Enter Postfix EXP ::");
	gets(exp);
	
	int j=strlen(exp);
	
	for(i=0; i<j;i++)
	{
		if(isalnum(exp[i]))
		{
			temp[0]=exp[i];
			push(temp);
		}
		else
		{
			pop();strcpy(op2,res);
			pop();strcpy(op1,res);
			temp[0]=exp[i];
			strcat(ptr,b1);
			strcat(ptr,op1);
			strcat(ptr,temp);
			strcat(ptr,op2);
			strcat(ptr,b2);
			
			push(ptr);
			clear(ptr);
		}
	}
	pop();
	puts("Infix EXP. ::");
	puts(res);


	return 0;
}
