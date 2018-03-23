#include <stdio.h>
#include <conio.h>
main()
{
	int i;
	for(i=1;i<=100;i++)
	{
		if(i%2==0) continue;
		printf("%5d",i);
		if((i+1)%20==0) printf("\n");
		
	}
	getch();
}
