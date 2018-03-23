#include <stdio.h>
#include <conio.h>
main()
{
	int *p;
	int x=5;
	p=&x;
	printf("gia tri cua con tro p: %d\n",*p);
	printf("dia tri cua con tro p: %p",&p);
	getch();
}

