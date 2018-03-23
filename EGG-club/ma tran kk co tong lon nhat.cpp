#include <conio.h>
#include <stdio.h>
static int m,n,k;

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
            printf("\t%d",a[row][column]);
        }
        printf("\n");
    }
}
void readfile(FILE *fp,int a[100][100],int m,int n,int k)
{
	fscanf(fp,"%d",&m);
	fscanf(fp,"%d",&n);
	fscanf(fp,"%d",&k);
	printf ("m=%d , n=%d, k=%d",m,n,k);
	for(int i=0;i<(m);i++)
	{
		for(int j=0;j<(n);j++)
		{
			fscanf(fp,"%d",&a[i][j]);
		}
	}
	printf("\nma tran vuong muon tim tong lon nhat %d ",k);
            findmatrixsquarek(k,a,m,n);
}

main()
{
	int a[100][100];
	FILE *fp;
	fp=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\matrix","r");
	if(fp==NULL)
	{
		printf("khong mo duoc file!");
	}
	else{
		  readfile(fp,a,m,n,k);
              
              //mo rong cho ma tran k.k
            fclose(fp);
	} 
    getch();
}
