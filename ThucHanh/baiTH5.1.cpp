#include <stdio.h>
#include <conio.h>
main()
{
	float day[9],tb;
	int i,n,tong,k,v;
	printf("nhap tong so phan tu day n:");  scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		float temp;
		printf("nhap phan tu thu day[%d]:",i);
		scanf("%f",&temp);
		day[i]=temp;
		
	}
	printf("day vua nhap la:");
	for(i=0;i<n;i++)
	{
		
		printf("%7.2f",day[i]);
	}
	tb=0;k=0;tong=0;v=0;
	for(i=0;i<n;i++)
	{
		if(day[i]<0)
		 {
		 tb=tb+day[i];
		 v++;
		 	 
	     }
		if (day[i]>0)
		 tong=tong+day[i];
		if (day[i]==0)
		  k++;
		  
	}
	printf("\ntrung binh cong cac so am:%5.2f ,\ntong cac so duong: %d va co %d so 0 trong day",tb/v,tong,k);
	getch();
}
