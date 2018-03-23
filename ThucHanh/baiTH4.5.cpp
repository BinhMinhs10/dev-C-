#include <stdio.h>
#include <conio.h>
main()
{
	int n,s=0,i;
	printf ("nhap gia tri cua n:"); scanf("%d",&n);
	while (10<n<100)
	  {
	     for(i=1;i<=n;i++)
	    {
		    s=s+i;
	    }
	    printf("tong can tim s: %d",s);
	    break;
	  }
	 //printf("tong can tim s: %d",s);  
	getch();
}
