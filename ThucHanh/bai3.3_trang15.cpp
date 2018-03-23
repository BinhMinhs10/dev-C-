#include <stdio.h>
#include <conio.h>
#include <math.h>
main()
{
	int x,y;
	float F;
	printf("\n nhap 2 so thuc X,Y:");
	scanf("\n%d ",&x);
	scanf("\n%d",&y);
	F=pow(y,6)+x*pow(y,5)+x*x*pow(y,4)+pow(x,3)*pow(y,3)+pow(x,4)*y*y+pow(x,5)*y+pow(x,6);
	printf ("Gia tri cua F= %10.2f",F);
	getch();
}
