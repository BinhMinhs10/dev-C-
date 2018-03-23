#include <stdlib.h>
#include <stdio.h>
#define max 100
int n;
int count;
int a[max];
void process()
{
	count++;
	printf("so thu %5d : ",count);
	for(int i=1;i<=n;i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n");
}
void TRY(int k)//try all value for a[k]
{
	int v;
	for(v=0;v<=1;v++)
	{
		a[k]=v;
		if(k==n)
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
	printf("nhap n tu ban phim: "); scanf("%d",&n);
	TRY(1);
	return 0;
}
