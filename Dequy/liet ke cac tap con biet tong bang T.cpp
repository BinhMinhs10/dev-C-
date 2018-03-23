#include <stdlib.h>
#include <stdio.h>
#define max 100
int n,t;
int count;
int a[max];
int b[9]={1,2,3,4,5,6,7,8,9};
void process()
{
	int tong=0;
	for(int i=1;i<=7;i++)
	{
		if(a[i]==1)
		{
			tong=tong+b[i-1];
		}
	}
	if(tong==t)
	{
		count++;
		printf("so thu %5d : ",count);
		for(int i=1;i<=7;i++)
		{
			if(a[i]==1)
			printf(" %d",b[i-1]);
		}
		printf("\n");
	}
}
void TRY(int k)//try all value for a[k]
{
	int v;
	for(v=0;v<=1;v++)
	{
		a[k]=v;
		if(k==7)
		{
			process();
		}
		else{
			TRY(k+1); //try all value of a[k+1]
		}
	}
}
int main()
{
	printf("nhap tong t : "); scanf("%d",&t);
	TRY(1);
	return 0;
}
