#include <stdio.h>
#include <conio.h>
int tong_chu_so(int a)
{
	if((a/10)==0)
	return(a%10);
	else
	return((a%10)+tong_chu_so(a/10));
}
main()
{
	int a;
	printf("nhap so nguyen duong :");
	scanf("%d",&a);
	printf("tong chu so cua %d la: %d",a,tong_chu_so(a));
}
