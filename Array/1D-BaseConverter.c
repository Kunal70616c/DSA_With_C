// Base Converter

#include<stdio.h>
#define MAX 100

void binary(int n)
{
	int binary[MAX],base = 2,j,i=0;
	while(n!=0)
	{
		binary[i]= n % base;
		n = n/base;
		i++;
	}
	printf("\n Binary =>");
	for(j=i-1;j >= 0;j--)
	{
		printf("%d",binary[j]);
	}
}

void octal(int n)
{
	int octal[MAX],base = 8,j,i=0,octalRes=0;
	
	while(n!=0)
	{
		octal[i]= n % base;
		n = n/base;
		i++;
	}
	printf("\n Octal =>");
	for(j=i-1;j >= 0;j--)
	{
		octalRes = octalRes * 10 + octal[j];	
	}
	printf("%d",octalRes);
}

void hex(int n)
{
	int hex[MAX],rem,base = 16,j,i=0;
	while(n!=0)
	{
		rem = n % base;
		if(rem<10)
			hex[i++]= 48 + rem;
		else
			hex[i++]= 55 + rem;
		n=n/base;
		
	}
	printf("\n HexaDecimal =>");
	for(j=i-1;j >= 0;j--)
	{
		printf("%c",hex[j]);
	}
}




int main()
{
	int arr[MAX],dec,i;
	printf("\nEnter Decimal Number:");
	scanf("%d",&dec);
	binary(dec);
	octal(dec);
	hex(dec);
	return 0;
	
}
