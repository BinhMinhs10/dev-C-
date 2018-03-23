#include <stdio.h>
#include <conio.h>
int F(int n)
{
	if(n==1||n==0)
	return 1;
	return F(n-1)+F(n-2);
}
main()
{
	signed int n;
	printf("nhap n:"); scanf("%d",&n);
 printf("day tong day fibonaci thu %d la %d",n+1,F(n));
}
