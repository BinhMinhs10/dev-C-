#include <stdio.h>
#include <conio.h>
main()
{
	FILE *fptr;
int a,b,max,min;
fptr=fopen("D:\\sonhoson.txt","w");
printf("nhap 2 so a va b lan luot la :");
scanf("%d %d",&a,&b);
max=a>b?a:b;
fprintf(fptr,"so lon nhat la: %d\n",max);
min=a<b?a:b;
//fscanf(fptr,"%d",&min);
fprintf(fptr,"%d",min);
fclose(fptr);
getch();
}
