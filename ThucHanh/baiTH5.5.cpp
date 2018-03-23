#include <conio.h>
#include <stdio.h>
#include <string.h>
struct Hoso{
	char Hoten[40];
	int diem;
	char loai[10];
};
int main()
{
	char str[20];
	struct Hoso sv[16];
	int n,i,gan;
	char str1[10]="Gioi";
	char str2[10]="kha";
	char str3[20]="trung binh", str4[20]="Khong Dat";
	printf("tong n hoc sinh: ");   scanf("%d",&n);
	for (i=0;i<n;i++)
	{
		printf("nhap ten cua hoc sinh thu %d: ",i+1);
		fflush(stdin); 
		gets(str);
		strcpy(sv[i].Hoten,str);
		printf("\ndiem cua hoc sinh do:");
		scanf("%d",&sv[i].diem);
		{
		   
		if((sv[i].diem==9)||(sv[i].diem==10))
		   strcpy(sv[i].loai,str1);
		if ((sv[i].diem==7)||(sv[i].diem==8))
		     strcpy(sv[i].loai,str2);
		if((sv[i].diem==5)||(sv[i].diem==6))
		    strcpy(sv[i].loai,str3);
		if ((sv[i].diem<5))    
		   strcpy(sv[i].loai,str4);
	    }
		
	}
	printf("\n                  XEP LOAI VAN HOA");
    printf("\nHO VA TEN             DIEM               XEP Loai");
    for(i=0;i<n;i++)
	printf("\n%-s                 %d                   %s",sv[i].Hoten,sv[i].diem,sv[i].loai);
	printf("\n................................................................................");
	getch();
	return 0;	
}
