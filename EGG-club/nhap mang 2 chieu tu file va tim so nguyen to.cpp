#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100
int m,n;
int dieu_kien(int n)
{
	for(int i=2;i<=sqrt(n);i++)
		if((n%i)==0)
		return 0;
	return 1;
}
void process(char* fn)
{
	int i,j;
	int temp;
	int a[MAX][MAX];
	FILE* f = fopen(fn,"r");
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&m);
	for(i = 1; i <= m; i++)
	{   
	    for(j=1;j<=n;j++)
	    {
	    	fscanf(f,"%d",&a[i][j]);
	    }
		
	}
	printf("n = %d, m = %d\n",n,m);
	
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j<=n ;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
	int max=0,column,row;
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j<=n ;j++)
		{
			if(max<a[i][j])
			{
				max=a[i][j];
				column=j;
				row=i;
			}
		}
	}
	printf("\nphan tu lon nhat ma tran la: a[%d][%d]=%d",row,column,max);
	//tim cac so nguyen to
	for(i=1;i<=m;i++)
	{
		for(j=1;j<n;j++)
		{
			 if((dieu_kien(a[i][j]))==1)
		     {
			      printf("\nso nguyen to a[%d][%d] la: %d",i,j,a[i][j]);
		     }
		}
	}
	fclose(f);// close the file
}
int main()
{
	int *a;
	a=(int *)malloc(m*n*sizeof(int));
	char filename[]="matrix.txt";
	process(filename);
	free(a);
}
