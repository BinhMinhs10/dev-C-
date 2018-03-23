#include <stdio.h>
#include <conio.h>
#include <math.h>
int giaithua(signed int n)
{
	if(n==0) return 1;
	else{
	int i=1,x=1;
	while(i<=n)
	{
		x=i*x;
		i++;
	}
	return x;
    }
}
main()
{
	signed int x;
	int e=1,n=1;
	printf("nhap x: "); fflush(stdin); 
	scanf("%d",&x);
	printf("\n");
	while(n<200)
	{
		e=e+(pow(x,n)/giaithua(n));
		n++;
	}
	printf("exp(%d) la %d",x,e);
	printf("\n");
	printf("%d",exp(x));
}
