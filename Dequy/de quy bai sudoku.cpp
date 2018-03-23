#include <conio.h>
#include <stdio.h>
#define max 100
int a[10][10];
int check(int a[10][10],int x,int y,int k)
{
	for(int i=1;i<=9;i++)
	{
		if(a[i][y]==k) return 0;
		if(a[x][i]==k) return 0;
	}
	int x_lon,y_lon;
	x_lon=x/3; y_lon=y/3;
	for(int i=3*y_lon+1;i<=3*y_lon+3;i++)
	{
		for(int j=3*x_lon+1;j<=3*x_lon+3;j++)
		{
			if(a[i][j]==k)
			return 0;
		}
	}
	return 1;
}
void print(int a[10][10])
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			printf("|%d| ",a[i][j]);
		}
		printf("\n");
	}
}
void sudoku(int a[10][10],int x,int y)
{
	for(int k=1;k<=9;k++)
	{
		if((check(a,x,y,k))==1)
		{
			a[x][y]=k;
			if(x==9&&y==9)
			{
				print(a);
			}
			else
			{
				if(y<9)
				sudoku(a,x,y+1);
				else
				sudoku(a,x+1,1);
			}
			a[x][y]=-1;
		}
	}
   
}
int main()
{
	
	sudoku(a,1,1);
	getch();
}
