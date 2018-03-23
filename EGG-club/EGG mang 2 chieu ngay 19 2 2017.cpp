#include <conio.h>
#include <stdio.h>
int main()
{
	int m,n;
	int a[100][100];
	printf("nhap so hang va so cot : "); scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("\ta[%d][%d]= ",i,j); scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	printf("\n mang sau process: \n");
	int b[100][100];
	for(int i=1;i<=n;i++)
	{
		b[1][i]=b[1][i-1]+a[1][i];
		printf("\t %d",b[1][i]);
	}
	printf("\n");
	for(int i=1;i<=m;i++)
	{
		b[i][1]=b[i-1][1]+a[i][1];
		printf("\n%d",b[i][1]);
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=2;j<=n;j++)
	    { 
		    b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+a[i][j];
	    }
		printf("\n");
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("\t %d",b[i][j]);
		}
		printf("\n");
	}
	
}
