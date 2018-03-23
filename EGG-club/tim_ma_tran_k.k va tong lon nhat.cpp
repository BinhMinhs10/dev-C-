#include <stdio.h>
#include <conio.h>
#define max 100
int m,n,k;
void findsum(int a[max][max],int m,int n,int k)
{
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
	int row,column,sum=-10000,tong;
	printf("\nma tran vuong ban muon tinh tong la %d.%d ",k);
	for(int i=k+1;i<=m;i++)
	{
		for(int j=k+1;j<=n;j++)
		{
			tong=-b[i-k][j]-b[i][j-k]+b[i-k][j-k]+b[i][j];
			if(sum<tong)
			{
				sum=tong;
				row=i;
				column=j;
			}
			
		}
			
    }
    printf("\n ma tran can tim:\n");
    printf("\ntong lon nhat ma tran %d.%d la : %d\n",k,k,sum);
    for(int i=row-k+1;i<=row;i++)
    {
    	for(int j=column-k+1;j<=column;j++)
    	{
    		printf("\t%d",a[i][j]);
    	}
    	printf("\n");
    }
	printf("\n tong ma tran vuong %d la: %d",k,sum);
	
}
int main()
{
	FILE *fp;
	fp=fopen("matrix","r");
	if(fp==NULL)
	{
		printf("\nkhong the mo file!!!!!!!!!!!!!");
	}
	else
	{
		int a[100][100];
		int i,j;
		fscanf(fp,"%d",&m);
	    fscanf(fp,"%d",&n);
	    fscanf(fp,"%d",&k);
	    for(int i=1;i<=m;i++)
	    {
		       for(int j=1;j<=n;j++)
		        {
			       fscanf(fp,"%d",&a[i][j]);
		        }
	    }
		printf("\nmatrix co %d dong va %d cot\n",m,n);
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				printf("%4d",a[i][j]);
			}
			printf("\n");
		}  
		findsum(a,m,n,k);
		fclose(fp);
	}
	getch();
	
	return 0;
}
