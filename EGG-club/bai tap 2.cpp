#include <conio.h>
#include <stdio.h>
#define max 100
int n,array[max],tich=1;
int a[max];
void process()
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			tich=tich*array[i];
		}
	}
	printf("tich lon nhat la:%d ",tich);
}
void TRY(int k)//try all value for a[k]
{
	    if((array[k]*array[k+1])>0)
	     {
	     	a[k]=1;
	     	a[k+1]=1;
	     }    
		if(k==n-1)
		{
			process();
		}
		else{
			TRY(k+2); //try all value of a[k+1]
		}
}
int main()
{
	FILE *fp;
	if((fp=fopen("baitap2","r"))==NULL)
	{
		printf("khong mo duoc file\n");
	}
	else
	{
		fscanf(fp,"%d",&n);
		for(int i=0;i<n;i++)
		{
			fscanf(fp,"%d",&array[i]);
		}
		TRY(0);
	}
	return 0;
}
