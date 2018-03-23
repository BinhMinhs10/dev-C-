#include <stdio.h>
#include <conio.h>
#include <string.h>
main()


{ struct sinhvien
     {
     	char tensv[30];
     	int tcno;
     
     }a[200];
char tg[30];
int n,i;
for (n=0;n<200;n++)
  {
  	printf("\nNhap du lieu cho sinh vien thu %d",n);
  	printf("\n ten sih vien :");
  	fflush(stdin);
  	gets(tg);
  	if(strcmp(tg,"***")==0) break;
  	else
  	{
  		strcpy(a[n].tensv,tg);
  		printf("\n so tin chi no:");
  		scanf("%d",&a[n].tcno);
  	}
  }
 printf("\n STT  Ten vinh vien     So TC no      Dang bi canh cao muc 3\n");
 for(i=0;i<n;i++)
 {
 	printf("\n %3d %-20s  %4d",i+1,a[i].tensv,a[i].tcno);
 	if(a[i].tcno>27) printf("%10s","YES");
 } 
}
