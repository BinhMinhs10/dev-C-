#include <stdio.h>
#include <conio.h>
main()
{
	long int li;
	int i;
	float f;
	clrscr();
	li=0x123456;
	f=123.456;
	i=(int) li;
	printf("\n li=%ld",li);
	printf("\n i=%d",i);
	i = (int)f;
	printf("\n f=%d", f);
	printf("\n i=%d",i);
	getch();
	
}
