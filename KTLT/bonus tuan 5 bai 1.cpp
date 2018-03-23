//S(n)=S(n-1)+1/(n*(n-1))
//S(0)=1
#include <stdio.h>
#include <conio.h>
int n;
float recursion(int k)
{
	if(k==0)
	{
		return 0;
	}
	else
	{
		return recursion(k-1)+1.0/(k*(k+1));
	}
}
void norecursion(int k)
{
	float tmp=0;
	for(int i=1;i<=k;i++)
	{
		tmp+=1.0/(i*(i+1));
	}
	printf("\n gia tri cua bieu thuc khong de quy S(%d)= %.3f",k,tmp);
}
int main()
{
	do{
		printf("\n nhap n: "); scanf("%d",&n);
	}while(n<0);
	printf("\n gia tri cua bieu thuc co de quy S(%d)= %.3f",n,recursion(n));
	norecursion(n);
	return 0;
}
