#include <conio.h>
#include <stdio.h>
int summatrix(int row,int column,int k, int a[100][100])
{
    int i,j,sum=0;
    for(i=row; i<row+k; i++)
    {
        for(j=column; j<column+k; j++)
        {
            sum=sum+a[i][j];
        }
    }
    return sum;
}
void findmatrixsquarek(int k,int a[100][100],int m, int n)
{
	int *p; 
	int sum=0,row,column,max=0;
    int i,j;
    int arraySum[50][50];
    for(row=0; row<=n-k; row++)
    {
        for(column=0; column<=m-k; column++)
        {
            arraySum[row][column]=summatrix(row,column,k,a);
        }
 
    }

    for(row=0; row<=n-k; row++)
    {
        for(column=0; column<=m-k; column++)
        {
            if(arraySum[row][column]>=max)
            {
                max=arraySum[row][column];
                i=row;
                j=column;
            }
        }
    }
 
    printf("\no vuong kich thuoc %dx%d co tong lon nhat la:%d\n",k,k,max);
    for(row=i; row<k+i; row++)
    {
        for(column=j; column<k+j; column++)
        {
            printf("%3d",a[row][column]);
        }
        printf("\n");
    }
}

main()
{
	int a[100][100],k=1;
	int m,n,temp,max=0,array[100];
	printf("nhap mang m x n: "); scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++)
	{
	   printf("\n");
	  for(int j=0;j<n;j++)
	  {
	  	printf("a[%d][%d]=",i+1,j+1);
	  	scanf("%3d",&a[i][j]);
	  }
    }
    for(int i=0;i<m;i++)
	{
	   printf("\n");
	  for(int j=0;j<n;j++)
	  {
	  	printf("%4d",a[i][j]);
	  }
    }
    
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		max=(max<a[i][j]?a[i][j]:max);
    	}
    	printf("\nphan tu lon nhat hang %d la :%d",i+1,max);
    }
    
    int row,column,tong;
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		tong=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
    		if(tong>max)
    		{
    			max=tong;
    			row=i;
    			column=j;
    		}
    	}
    }
    printf("\ntong lon nhat cua mang 2.2 la: %d\n",max);
        printf("%3d%3d",a[row][column],a[row][column+1]); printf("\n");
        printf("%3d%3d",a[row+1][column],a[row+1][column+1]);
    //mo rong cho ma tran k.k
    
    printf("\n nhap ma tran vuong muon tim tong lon nhat k= ");
	 scanf("%d",&k);
    findmatrixsquarek(k,a,m,n);
    
    
    
    getch();
}
