#include <stdio.h>
#include <conio.h>
void hoan_vi(float *px,float * py)
{
	float z;
	z=*px;
	*px=*py;
	*py=z;
}
main()
{
	float a=8.34, b=12.45;
	hoan_vi(&a,&b);
	printf("a=%.2f, b=%.2f ",a,b);
}
