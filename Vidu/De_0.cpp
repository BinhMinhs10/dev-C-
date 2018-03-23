#include <stdio.h>
#include <conio.h>
main()
{
	int m[100],chi_so[100];
	int N,i,X,k,kiem_tra;
	fflush(stdin);
	do
	{
		printf("nhap N so phan tu mang: ");
		scanf("%d",&N);
		
	}
	while((0>N)||(N>10));
	for(i=0;i<N;i++)
	{ 
	    int temp;
		printf("\nnhap phan tu m[%d] ",i);
		scanf("%d",&temp);
		m[i]=temp;
	}
	printf("\nmang vua nhap:  ");
	for(i=0;i<N;i++)
	{
		printf("%3d",m[i]);
	}
	printf("\nnhap mot so nguyen X:");
	scanf("%d",&X);
	do
	{
	 
	        kiem_tra=0;
	   for(i=0;i<N;i++)
	  {
	 	
		    if(m[i]==X)
		   {
			chi_so[kiem_tra]=i;
			kiem_tra++;
			
		   }
		
	  }
	 if(kiem_tra>0)
	   {
	 	printf("\ntrong mang co %d pt co gia tri bang %d",kiem_tra,X);
	 	printf("\nchi so cua phan tu la:");
	 	for(k=0;k<kiem_tra;k++)
	 	printf("%3d",chi_so[k]);
	   }
	 else
	  printf("trong mang ko co phan tu co gia tri bang %d",X);
    }
    while(X>10);
    getch();
}  
