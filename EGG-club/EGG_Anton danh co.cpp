#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int n;
 char *s=(char*)malloc(100000*sizeof(char));
int Anton=0,Danik=0;
void readdata(char *name)
{
	FILE *f;
	f=fopen(name,"r");
	if(f==NULL)
	{
		printf("\n khong mo duoc file");
	}
	else
	{
		fscanf(f,"%d",&n);
		for(int i=0;i<n;i++)
		{
			fscanf(f,"%c",&s[i]);
		}
	}
}
void check()
{
	if(Anton==Danik)
	{
		printf("\n Friendship");
	}
	else if(Anton>Danik)
	{
		printf("\n Anton");
	}
	else
	{
		printf("\n Danik");
	}
}
int main()
{
	int stop=1;
	readdata("Anton_choi_co");
	for(int i=0;i<n;i++)
	{
		if((s[i]=='A')||(s[i]=='D'))
		{
			stop=0;
		}
		if(s[i]=='A')
		{
			Anton++;
		}
		else Danik++;
	}
	if(!stop)
	{
		check();
	}
	else printf("\n input sai");
	
}
