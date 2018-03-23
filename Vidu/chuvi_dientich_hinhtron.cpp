#include <conio.h>
#include <stdio.h>
#include <math.h>
main()
{
	float M,S;
	unsigned int r;
	printf("\n nhap so ban kinh r:");
	scanf("%d",&r);
	M=2*M_PI*r; S=M_PI*r*r;
	printf("\n chu vi hinh tron la: %10.2f\n dien tich hinh tron la: %10.2f",M,S);
	getch();
}
