#include <stdio.h>
#include <conio.h>
main()
{ 
      float x,y, min;
      printf("\n x= ");
      scanf("%f",&x);
      printf("\n y= ");
      scanf("%f",&y);
      if(x<y)
         min=x;
      else 
         min=y;
      printf(" So nho nhat rong hai so la: %6.2f",min);
	  getch();
	     
}
