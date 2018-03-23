#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 100
int n,maxend[MAX];
int *a=(int* )malloc(100*sizeof(int));
int *b=(int* )malloc(100*sizeof(int));
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
		for(int i=0;i<n;i++)
		{
			fscanf(f,"%d",&b[i]);
		}
		
	}
	fclose(f);
}
int main()
{
	int max=0,temp1,temp2;
	readdata("thongtin");
	printf("n=%d\n",n);
	maxend[0]=1;
	printf("\n day sau khi da sap xep: \n");
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(b[i]>b[j])
			{
				temp1=b[i];
				b[i]=b[j];
				b[j]=temp1;
				temp2=a[i];
				a[i]=a[j];
				a[j]=temp2;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%3d",a[i]);
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%3d",b[i]);
	}
	
	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<i;j++)
		{
			if(b[j]<=a[i])
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
	printf("\n so cuoc hop to chuc duoc nhieu nhat la: %d",x);
	free(b);
	return 0;
}
