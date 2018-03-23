#include <stdio.h>
#include <conio.h>
#define MAX 100
int n,a[MAX],maxend[MAX];
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
		for(int i=0;i<n;i++)
		{
			fscanf(f,"%d",&a[i]);
		}
	}
	fclose(f);
}
int main()
{
	int max=0;
	readdata("input");
	printf("n=%d\n",n);
	maxend[0]=1;
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<i;j++)
		{
			if(a[j]<a[i])
			{
				max=maxend[j]+1;
				if(max>maxend[i])
				{
					maxend[i]=max;
				}
			}
		}
	}
	int x=0;
	for(int i=0;i<n;i++)
	{
		if(maxend[i]>x)
		{
			x=maxend[i];
		}
	}
	printf("\n do dai day tang lon nhat la: %d",x);
	return 0;
}
