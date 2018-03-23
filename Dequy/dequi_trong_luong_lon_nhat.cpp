#include <stdio.h>
#include <conio.h>
main()
{
	int n,a[100],j;
	printf("nhap gia tri cua n: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("nhap phan tu thu %d ",i+1);
		scanf("%d",&a[i]);
	}
	MaxLeft(a, i, j); 
	{ maxSum = -?; 
	sum = 0; 
	for (int k=j; k>=i; k--) 
	{ sum = sum+a[k]; 
	  maxSum = max(sum, maxSum); }
	   return maxSum; }
}
