#include <stdio.h>
#include <conio.h>
int mang(int i,int j,int m,int *a)
{
	if((i==1)&&(j==1))
	{
		return *(a+i*m+j);
	}
	else if(i==1)
	{
		return mang(i,j-1,m,a)-*(a+i*m+j);
	}
	else if(j==1)
	{
		return mang(i-1,j,m,a)-*(a+i*m+j);
	}
	else
	{
		return mang(i-1,j,m,a)+mang(i,j-1,m,a)-mang(i-1,j-1,m,a)+*(a+i*m+j);
	}
}
int main()
{
	int m,n;
	int a[100][100];
	printf("nhap so hang va so cot"); scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("\ta[%d][%d]= ",i,j); scanf("%d",&a[i][j]);
		}
		printf("\n");
	}
	printf("\n mang sau process: \n");
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("\t %d",mang(i,j,m,a[1]));
		}
		printf("\n");
	}
}
