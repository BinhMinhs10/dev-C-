#include <stdio.h>
#include <conio.h>
main()
{
	int m[100], chi_so[100];
	int n;
	int i,k,kiem_tra;
	fflush(stdin);
	printf("cho biet so phan tu trong mang: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int temp;
		printf("\n cho biet gia tri cua m[%d] ",i);
		scanf("%d",&temp);
		m[i]=temp;
		
	}
	printf("\n cho biet gia tri cua du lieu K ");
	scanf("%d",&k);
	kiem_tra=0;
	for(i=1;i<n;i++)
	   if(m[i]==k)
	   {
	   	chi_so[kiem_tra]=i;
	   	kiem_tra++;
	   	
       }
    if(kiem_tra>0)
	{
		printf("\n trong mang co %d phan tu co gia tri bang %d",kiem_tra,k);
		printf("\nChi so cua cac phan tu la:");
		for(i=0;i<kiem_tra;i++)
		  printf("%3d",chi_so[i]);
		  
	}   
	else 
	   printf("trong mang ko co pt co gia tri %d",k);
	getch();   
}
