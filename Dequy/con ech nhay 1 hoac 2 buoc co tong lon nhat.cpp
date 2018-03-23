#include <stdio.h>
#include <conio.h>
#define max 100
int n,a[max],count,b[max],flag;
int max_sum=-100000;
void process()
{
	count++;
	int tong=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]==2)
		{
			b[i+1]=0;
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(b[i]==1)
		{
			tong=tong+a[i+1];
		}
		if(b[i]==2)
		{
			tong=tong+a[i+2];
		}
	}
	printf("\nlan %3d co tong la: %d",count,tong);
	if(max_sum<tong)
	{
	     max_sum=tong;
	}
}
void echnhay(int k,int a[max])
{
	for(int i=1;i<=2;i++)
	{
		b[k]=i;
		if(k==n)
		{
			process();
		}
		else
		{
			echnhay(k+1,a);
		}
		b[k]=0;
	}
}
int main()
{
	printf("\n nhap so o n= "); scanf("%d",&n);
	printf("\n nhap gia tri tung o:\n");
	for(int i=1;i<=n;i++)
	{
		printf("a[%d]= ",i); scanf("%d",&a[i]);
	}
	
	echnhay(1,a);
	printf("\n");
	printf("\nsau khi con ech nhay moi chan tong lon nhat la: %d",max_sum);
	return 0;
}
