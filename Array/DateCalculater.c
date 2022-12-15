#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int nYear[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int lYear[12]={31,29,31,30,31,30,31,31,30,31,30,31};

int leapYear(int year)
{
	if(year % 400 ==0)
		return 1;
	if(year % 100 ==0)
		return 0;
	if(year % 4 ==0)
		return 1;
	else
		return 0;	
	
}

int main()
{
	int day,month,year;
	int i,totalDay=0;
	printf("\n Enter Day:");
	scanf("%d",&day);
	printf("\n Enter Month:");
	scanf("%d",&month);
	printf("\n Enter Year:");
	scanf("%d",&year);
	printf("\n The Date You Entered: %d / %d / %d",day,month,year);
	
	int leapChk= leapYear(year);
	
	if(leapChk==1)
	{
		for(i=0;i<month-1;i++)
		{
			totalDay= totalDay + lYear[i];
		}
		totalDay= totalDay+day;
		printf("\n The Day is %d -th Day of The Year %d. from 1st January of the year!",totalDay,year);
	}
	else
	{
		for(i=0;i<month-1;i++)
		{
			totalDay= totalDay + nYear[i];
		}
		totalDay= totalDay+day;
		printf("\n The Day is %d -th Day of The Year %d. from 1st January of the year!",totalDay,year);
	}


	return 0;
}
