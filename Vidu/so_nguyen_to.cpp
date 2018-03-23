#include <stdio.h>
#include <conio.h>
main()
{
	int n,index=1;
	printf("nhap n= "); scanf("%d",&n);
	for(int i=2;i<n;i++)
	{
		if((n%i)==0)
		{
		   index=0;
		   break;
	    }
	}
	if(index==1)
	printf("\nYES");
	else
	printf("\nNO");
	getch();
}
