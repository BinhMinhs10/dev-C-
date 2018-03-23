#include <stdio.h>
#include <conio.h>
#include <math.h>
float Y(int c,float x){
	if(x==4.5) return 0;
	if(x>4.5) return exp(1.0/c*log(2*x-9));
	else return -exp(1.0/c*log(9-2*x));
}
main()
{
	int c,i; 
	float x;
	printf("nhap vao so thuc x: "); scanf("%f",&x);
	do{
		printf("nhap vao so duong c: "); scanf("%d",&c);
	}while(c<=0);
	for(i=0;i<20;i++)
	{
		printf("\nHam cua %3d va %7.2f la: %7.2f",c,x,Y(c,x));
		x+=0.25;
	}
	getch();
}

