#include <conio.h>
#include <stdio.h>
void thap_co(int n,int a,int b,int c)
{
	if(n==1) printf("\nchuyen dia tu cot %d sang %d",a,c);
	else
	{
		thap_co(n-1,a,c,b);
		printf("\nchuyen dia tu cot %d sang %d",a,c);
		thap_co(n-1,b,a,c);
	}
}
main()
{
	int n;
	printf("nhap vao so dia o cot A:"); scanf("%d",&n);
	thap_co(n,1,2,3);
}
