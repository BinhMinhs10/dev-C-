#include <conio.h>
#include <stdio.h>
#define max 100
int a[max],i;
bool check(int v,int k)
{
	
}
bool checksolution()
{
	//check if a[1...n] satisifes the constraints
	for(int i=1;i<=n-1;i++)
	for(int j=i+1;j<=n;j++)
	{
		if(a[i]==a[j]) return false;
		if(a[i])
	}
}
void process()
{
	if(checksolution())
	{
		
	}
}
void TRY(int n){
	for(v=1;v<=n;v++)
	{
		if(check(v,k))
		{
			a[k]=v;
			if(k==n)
			     process();
			else
			  TRy(k+1);     
		}
	}
}
int main()
{
	printf("nhap ma tran cap n= "); scanf("%d",&n);
	TRY(1);
}
