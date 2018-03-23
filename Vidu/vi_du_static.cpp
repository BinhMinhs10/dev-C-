#include <stdio.h>
#include <conio.h>
int main()
{
	static int sum=0;
	int num;
	printf("Enter a number: "); scanf("%d",&num);
	sum+=num;
	printf("the current total is: %d",sum);
	return 0;
}
