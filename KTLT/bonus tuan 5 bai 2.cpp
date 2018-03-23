// day 1,2,3,7,14,27,55,110,219,....
// S(n)=2*S(n-3)+S(n-2)+S(n-1) ;n>=3
// S(1)=1;S(2)=2;S(3)=3;
#include <stdio.h>
#include <conio.h>
#define max 100
int tmp;
int n,a[max];
int dayso(int i)
{
	if(i<4)
	{
		return i;
	}
	else
	{
		return (2*dayso(i-3)+dayso(i-2)+dayso(i-1));
	}
}
void inday_recursion(int n)
{
	int j;
	printf("\n day so duoc in bang cach de quy:\n");
	for(j=1;j<=n;j++)
	{
		printf("\t%d",dayso(j));
		
	}
}
void tong_recursion(int n)
{
	int flag;
	for(int i=1;i<=n;i++)
	{
		flag+=dayso(i);
	}
	printf("\ntong day tren tinh theo de quy: %d",flag);
}
void inday_norecursion(int k)
{
	printf("\n day so duoc in bang cach de quy:\n");
    for(int i=1;i<=k;i++)
    {
    	if(i<4)
    	{
    		a[i]=i;
    	}
    	else
    	{
    		a[i]=2*a[i-3]+a[i-2]+a[i-1];
    	}
    	printf("\t%d",a[i]);
    }
}
void tong_norecursion(int n)
{
	int flag;
	for(int i=1;i<=n;i++)
	{
		flag+=a[i];
	}
	printf("\ntong day tren tinh theo cach khong dung de quy: %d",flag);
}
int main()
{
	do{
		printf("\nban muon in va tinh tong day");
	    printf("\nbang de quy(press one) hoac khong dung de quy(press two): ");
		scanf("%d",&tmp);
	}while((tmp<1)||(tmp>2));
	do{
		printf("\n nhap so phan tu cua day so: ");
	    scanf("%d",&n);
	}while(n<1);
	if(tmp==1)
	{
		inday_recursion(n);
		tong_recursion(n);
	}
	else if(tmp==2)
	{
		inday_norecursion(n);
		tong_norecursion(n);
	}
	return 0;
}
