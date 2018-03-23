#include <stdio.h>
#include <conio.h>
#include <math.h>
main()
{
	float a[10],b[10],c[10];
	int n,i,j,dem,dem1;
	printf("nhap so n:"); scanf("%d",&n);
	do{
	
	    for (i=0;i<n;i++)
	   {
		  float tem;
		  printf("\nnhap phan tu thu %d:",i);
		  scanf("%f",&tem);
		  a[i]=tem;
		  printf(" %7.2f",a[i]);
	   }
    }while(n>10);
    for(i=0;i<n;i++)
    {
    	int dem=0,dem1=0;
    	if(a[i]>0)
    	{
    	 b[dem]=a[i]; dem++;
        }
        if(a[i]<0)
        {
        	c[dem1]=a[i]; dem1++;
        }
            
    }   
	for(j=0;j<dem;j++) 
	printf("%7.2f",b[j]);
	for(j=0;j<dem1;j++) 
	printf(" %7.2f",c[j]);
	getch();

}
