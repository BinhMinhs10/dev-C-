#include <stdio.h>
#include <conio.h>
main()
{
	float x,y, max;
	printf("\n X= ");
	scanf("%f",&x);
	printf("\n Y=");
	scanf("%f",&y);
	if(x>y)
	    max = x;
	else 
	    max = y;
	printf("so lon nhat trong hai so la: %6.2f",max);
	getch();
		    
	
}
