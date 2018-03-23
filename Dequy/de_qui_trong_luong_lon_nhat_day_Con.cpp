#include <stdio.h>
#include <conio.h>
int maxleft(int b[100],int i,int j)
{
	float maxsum=-20000; 
	int sum=0;
	for(int k=j;k>=i;k--)
	{
		sum=sum+b[k];
		if(maxsum<sum)
		maxsum=sum;
	}
	return maxsum;
}
///////////////////////////////////////////////////////////////////
int maxright(int a[100],int i,int j)
{
	float maxsum=-20000; 
	int sum=0;
	for(int k=i;k<=j;k++)
	{
		sum=sum+a[k];
		if(maxsum<sum)
		maxsum=sum;
	}
	return maxsum;
}
main()
{
	
}
