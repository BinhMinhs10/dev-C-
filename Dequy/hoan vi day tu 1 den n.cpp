#include <stdlib.h>
#include <stdio.h>
#define max 100
int n;
int count;
int a[max];
bool marked[50];
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
	for(v=1;v<=n;v++)
	{
		if(marked[v]==false)
		{
			a[k]=v;
			marked[v]=true;
			if(k==n)
			{
				process();
			}
			else
			{
				TRY(k+1);
			}
			marked[v]=false;
		}
	}
}
int main()
{
	printf("nhap n tu ban phim: "); scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		marked[i]=false;
	}
	TRY(1);
	return 0;
}
