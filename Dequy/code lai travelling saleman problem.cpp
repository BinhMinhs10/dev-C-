#include <stdio.h>
#include <conio.h>
#define max 100
int a[max],c[max][max];
bool mark[max];
int f,n;
void readdata(char *fn)
{
	FILE *f;
	if((f=fopen(fn,"r"))==NULL)
	{
		printf("\n khong mo duoc file");
	}
	else
	{
		fscanf(f,"%d",&n);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			fscanf(f,"%d",&c[i][j]);
		}
	}
}
int f_min;
int x_min[max];
void process()
{
	if(f+c[a[n]][a[1]]<f_min)
	{
		f_min=f+c[a[n]][a[1]];
		for(int i=1;i<=n;i++)
		{
			x_min[i]=a[i];
		}
	}
}
void hoanvicacdiemdi(int k)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(mark[i]==false)
		{
			a[k]=i;
			mark[i]=true;
			f+=c[a[k-1]][a[k]];
			if(k==n)
			{
				process();
			}
			else
			{
				hoanvicacdiemdi(k+1);
			}
			mark[i]=false;
			f-=c[a[k-1]][a[k]];
		}
	}
}
int main()
{
	f_min=10000000;
	f=0;
	for(int i=0;i<=n;i++)
	{
		mark[i]=false;
	}
	readdata("tsp");
	a[1]=1;
	mark[a[1]]=true;
	hoanvicacdiemdi(2);
	//best solution
	printf("\nbest solution: %d \n",f_min);
	for(int i=1;i<=n;i++)
	{
		printf(" %d -> ",x_min[i]);
	}
	printf(" 1");
	return 0;
}
