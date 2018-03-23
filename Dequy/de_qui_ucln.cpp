#include <stdio.h>
#include <conio.h>
void ucln(int a, int b)
{
	if(a==b) 
	printf("uoc chung lon nhat la: %d",a);
	else if(a>b)
	ucln(a-b,b);
	else
	ucln(a,b-a);
}
main()
{
	int a,b;
	printf("nhap a va b: ");
	scanf("%d%d",&a,&b);
	ucln(a,b);
	
}
