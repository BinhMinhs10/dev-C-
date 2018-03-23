#include <stdio.h>
#include <conio.h>
int x[9][9];
int a[9][9];
bool b[9][9][9];
void print(int x[9][9])
{
	for(int i=0;i<=8;i++)
	{
		for(int j=0;j<=8;j++)
		{
			printf(" %d ",x[i][j]);
		}
		printf("\n");
	}
	printf("---------------------------------");
}
bool check(int v,int r,int c)
{
	//check cot
	for(int i=0;i<r;i++)
	{
		if(v==x[i][c])
		return false;
	}
	//check hang
	for(int j=0;j<=c-1;j++)
	{
		if(v==x[r][j]) return false;
	}
	//check ma tran 3.3
	int I=r/3;int J=c/3;
	int i=r-3*I;int j=c-3*J;
	for(int i1=0;i1<i;i1++)
	{
		for(int j1=0;j1<3;j1++)
		{
			if(x[3*I+i1][3*J+j1]==v)
			return false;
		}
	}
	for(int j1=0;j1<j;j1++)
	{
		if(x[3*I+i][3*J+j1]==v)
		return false;
	}
	return true;
}
void TRY(int r,int c)
{
	for(int v=1;v<=9;v++)
	{
		if(check(v,r,c))
		{
			x[r][c]=v;
			if(r==8&&c==8)
			print(x);
			else
			{
				if(c<8)
				TRY(r,c+1);
				else
				TRY(r+1,0);
			}
		}
	}
}
int main()
{
	TRY(0,0);
}
