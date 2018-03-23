#include<stdio.h>
#include<conio.h>
main()
{
	int j,i,h,l,k;
	printf("so chieu cao ma ban muon nhap h (h>0): ");
		 scanf("%d",&h);
		 
	printf("chieu dai ma ban muon nhap l: ");
	     scanf("%d",&l);
	if(h>0&&l>0)
	{	
		{
		  for(k=0;k<l-1;k++)
		  { 
		      printf("*");
		  }
		      printf("*\n");
	       for(i=0;i<h;i++)
	      {
	         printf("*");
	          printf("%lc * \n");
          }
          for(k=0;k<l;k++)
		  { 
		      printf("*");
		  }
        }
    }
    else
    {
    	printf("ban nhap sai gia tri h hoac l (h>0,l>0) ??");
    }
	getch();
}
