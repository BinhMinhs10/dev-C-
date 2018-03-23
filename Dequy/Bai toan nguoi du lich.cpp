#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#define max 100
int n,a[max];
int count;
bool marked[max];
int c[max][max];
char filename[40];
int f;
void sinh_matrancapn()
{
	int n;
	printf(" ten tep muon tao "); scanf("%s",filename);
	FILE *fp;
	fp=fopen(filename,"w");
	printf("\n so thanh pho di qua n: ");  scanf("%d",&n);
	fprintf(fp,"%d\n",n);
	srand(time(0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j)
			{
				fprintf(fp,"\t%d",rand()%200);
			}
			else
			{
				fprintf(fp,"\t%d",0);
				
			}
			
		}
	   	fputs("\n",fp);
	}
	fclose(fp);
}
void readdata(char* f)
{
	FILE *fp=fopen(f,"r");
	fscanf(fp,"%d",&n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				fscanf(fp,"%d",&c[i][j]);
			}
		}
	fclose(fp);
}
//store best cost, best solution
int f_min;
int x_min[max];//best tour
void process()
{
	count++;
	//printf("so %3d: ",count);
	//solution a[1]->a[2]->a[3]->a[4]->a[5]
	//for(int i=1;i<n;i++)   f=f+c[a[i]][a[i+1]];
	//f=f+c[a[n]][a[1]];
	if(f+c[a[n]][a[1]]<f_min)
	{
		f_min=f;
		for(int i=1;i<=n;i++)
		   x_min[i]=a[i];
	}
	//for(int i=1;i<=n;i++) printf("%d",a[i]);
	//printf(",cost= %d, cost min= %d\n",f,f_min);
}

void TRY(int k)
{
	int v;
	for(v=1;v<=n;v++)
	{
		if(marked[v]==false)
		{
			a[k]=v;
			f=f+c[a[k-1]][a[k]];
			marked[v]=true;
			if(k==n)
			{
				process();
			}
			else
			{
				TRY(k+1);
			}
			marked[v]=false;
			f=f-c[a[k-1]][a[k]];
		}
	}
}
int main()
{
	//printf("nhap so thanh pho: "); scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		marked[i]=false;
	}
	//sinh_matrancapn();
	readdata("tsp");
	f_min=10000000;
	f=0;
	a[1]=1;
	marked[a[1]]=true;	
	TRY(2);
	 printf("\n best solution la: %d\n",f_min);
	 
	return 0;
}
