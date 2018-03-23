#include <stdio.h>
#include <conio.h>
int maxdigit(int n)
{
	int max=0;
	if(n==0)
	return max;
	else
	{
		if(max<(n%10))
		max=n%10;
		return maxdigit(n/10);
	}
	
}
main()
{
	int n;
	printf("n= "); scanf("%d",&n);
	printf("\ngia tri cua max: %d",maxdigit(n));
}
