#include <conio.h>
#include <stdio.h>
#define max 100
int a[max];
int n,k,count=0;
int flag;
void process()
{
	
	count++;
	for(int i=1;i<=n;i++)
	{
		flag=0;
		for(int j=i;j<i+k;j++)
		{
			if(a[j]==0)
			{
				flag++;
				if(flag==k)
		        {
		        	count--;
			        break;
		        }
			}
			
		}
		if(flag==k)
		{
			break;
		}
		
	}
}
void hoanvi(int h)
{
	int v;
	for(v=0;v<=1;v++)
	{
		a[h]=v;
		if(h==n)
		{
			process();
		}
		else
		{
			hoanvi(h+1);
		}
	}
}
int main()
{
	do
	{
		printf("\nhap do sai xau nhi phan (n>=1): "); 
	    scanf("%d",&n);
	}while(n<1);
	do
	{
		printf("\nkhong chua so so 0 lien tiep (k>=2): ");
		scanf("%d",&k);
	}while(k<2);
	for(int i=0;i<max;i++)
	{
		a[i]=1;
	}
	hoanvi(1);
	printf("\n so luong xau nhi phan do dai %d khong chua %d so 0 lien tiep la: %d",n,k,count);
	return 0;
}
