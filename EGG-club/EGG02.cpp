#include <stdio.h>
#include <conio.h>
main()
{
int a,b,max,min;

printf("nhap 2 so a va b lan luot la :");
scanf("%d %d",&a,&b);
max=a>b?a:b;
min=a<b?a:b;
printf("so lon nhat la: %d\n",max);
FILE *fptr;
fptr=fopen("sonhoson.txt","w");
printf("so be hon la: %d",min);
fclose(fptr);
getch();
}
