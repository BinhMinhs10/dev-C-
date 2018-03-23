#include <stdio.h>
#include <conio.h>
main()
{
	float a,b, max;
	printf("\n a= ");
	scanf("%f",&a);
	printf("\n b= ");
	scanf("%f",&b);
	max=a;
	if(max<b)
	    max=b;
	printf("So lon nhat trong hai so la %6.2f",max);
	getch();    
}

