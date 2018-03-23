#include <stdio.h>
#include <conio.h>
#include <math.h>
main()
{    float a,x,cos=0,epsilon=0.0001,gt=1;
     int n=0,i=0;
     do {printf("Nhap vao so thuc x radian (0<=x<10) :");
        scanf("%f",&x);
		}while(x<0||x>=10);
       a=1;
     do {if(i%4==2) cos=cos-a;
         else cos=cos+a;
         i=i+2;gt=gt/(i-1)/i;
         a=pow(x,i)*gt;} 
         while(a>=epsilon);
         printf("\n Ta co cos(%.6f) = %.6f",x,cos);
      getch();
      return 1;
}
