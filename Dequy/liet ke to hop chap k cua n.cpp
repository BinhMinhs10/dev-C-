#include <stdlib.h>
#include <stdio.h>
#define max 100
int n,k;
int count;
int a[max];
void process()
{
	count++;
	printf("so thu %5d : ",count);
	for(int i=1;i<=k;i++)
	{
		printf(" %d",a[i]);
	}
	printf("\n");
}
void TRY(int i)//try all value for a[k]
{
	int v;
	for(v=a[i-1]+1;v<=n-k+i;v++)
	{
		a[i]=v;
		if(i==k)
		{
			process();
		}
		else{
			TRY(i+1); //try all value of a[k+1]
		}
	}
}
int main()
{
	printf("nhap n tu ban phim: "); scanf("%d",&n);
	printf("\n nhap k: "); scanf("%d",&k);
	TRY(1);
	return 0;
}
