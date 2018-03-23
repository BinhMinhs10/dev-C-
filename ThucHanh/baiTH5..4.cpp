#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
main()
{
	char dslop[10][30],s[30];
	int i,j,n;
	do{
		printf("nhap so sinh vien cua lop 0<n<=10: ");
		scanf("%d",&n);
		
	}while(n<=0||n>10);
	for(i=0;i<n;i++)
	{
		printf("\n nhap ten sinh vien thu %d ",i+1);
		fflush(stdin);    gets(dslop[i]);
	}
	
	for(i=0;i<n-1;i++)
	   for(j=i+1;j<n;j++)
	     if(toupper(dslop[i][0])>toupper(dslop[j][0]))
	     {
	     	strcpy(s,dslop[i]);
	     	strcpy(dslop[i],dslop[j]);
	     	strcpy(dslop[j],s);
	     }
	 printf("\n Danh sach lop xep theo thu tu ABC:");
	 for(i=0;i<n;i++){
	 	printf("\n %d",i+1);
	 	puts(dslop[i]);
	 }
	 getch();
	 return 0;
	      
}
