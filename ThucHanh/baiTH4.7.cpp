#include <stdio.h>
#include <conio.h>
#include <math.h>
main()
{
	float pi,epsilon; 
	int i;
	i=0; pi=0;
	printf("nhap so epsilon:"); scanf("%f",epsilon);
	if((epsilon<1)&&(epsilon>0))
	     {
	     	while(i>(1/(2*epsilon)-1/2))
	     	  {
	     	  	pi=4*pow(-1,i)/(2*i+1);
	     	  	i+=1;
	     	  }
	     	printf("so pi la:%f",pi);  
	     }
	    
	else
	    printf("nhap sai hay nhap lai (0<epsilon<1):");
	getch();    
}
