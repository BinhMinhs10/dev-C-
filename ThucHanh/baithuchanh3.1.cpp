#include <stdio.h>
#include <conio.h>
#include <math.h>
main()
{
	int a,b,c;
	float (a-b),(b-c),(a-c);
	printf("Nhap 3 canh cua 1 tam giac:");
	scanf("%d %d %d",&a,&b,&c);
	if((fabs(a-b)<c<fabs(a+b))&&(fabs(b-c)<a<fabs(b+c))&&(fabs(a-c)<b<fabs(a+c)))
	  {
	    {
	    if((a==b)&&(b==c))
	      printf("\n la 3 canh cua tam giac deu");
	    }
	   {
	   if(((a==b)&&(b!=c))||((a==c)&&(c!=b))||((b==c)&&(c!=a)))
	      printf("\n la 3 canh tam giac can");
	   }
	   {
	   if((a*a==b*b+c*c)||(b*b==a*a+c*c)||(c*c==b*b+a*a))
	      printf("\n la 3 canh tam giac vuong");
	   }
      }
	  {
	   if((a>(b+c))||(b>(a+c))||(c>(b+a)))
	      printf("\n khong la 3 canh tam giac");   
	   else
	      printf("\n la tam giac binh thuong");
	  }
	  getch();
		  	   
}
