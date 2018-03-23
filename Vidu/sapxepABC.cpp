#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
char *name[7] ;
char *tempt;
int i ,j;

printf("Nhap cac ten:\n ");
for(i =0;i<7;i++)
{ 
name[i] = new char[25];
printf("Ten: %d :",i+1);
fflush(stdin);
gets(name[i]);
}

printf("Sap xep theo thu tu tang dan : ");
for(i = 0;i<7;i++){
for ( int j = i+1 ; j < 7 ; j++){
if(strcmp(name[i],name[j])>0)
{
tempt = name[i];
name[i] = name[j];
name[j] = tempt;
}
}
}
printf("Cac ten sau khi da xap xep xong: ");
for(i=0;i<7;i++)
printf("\n %s",name[i]);
getch();
}
