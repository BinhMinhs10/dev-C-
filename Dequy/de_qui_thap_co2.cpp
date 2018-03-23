#include <conio.h>
#include <stdio.h>
void thapco(int n,int a,int b,int c)
{
	if(n==1)
	{
		printf("\nchuyen dia tu coc %d sang coc %d",a,c);
	}
	else
	{
		thapco(n-1,a,c,b);
	    thapco(1,a,b,c);
	    thapco(n-1,b,a,c);
	}
	
	
}
main()
{
	int n;
	printf("nhap so dia: "); scanf("%d",&n);
	thapco(n,1,2,3);
}
