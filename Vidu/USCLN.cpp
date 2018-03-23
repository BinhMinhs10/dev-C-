#include <stdio.h>
#include <conio.h>
unsigned int Uscln(unsigned int a,unsigned int b)
{
	unsigned int u;
	if(a<b)
	{
		u=a;a=b;b=u;
	}
	do
	{
		u=a%b;
		a=b; b=u;
	}while(u!=0);
	return a;
}
int main()
{
	unsigned int a,b;
	do
	{
		printf("\n Nhap vao 2 so nguyen duong a va b");
		printf("\n a="); scanf("%d",&a);
		printf("\n b= "); scanf("%d",&b);
		if(a*b==0)
		{
			printf("\n Khong hop le");
			continue;
		}
		printf("uc chung lon nhat la:%d",Uscln(a,b));
	}while((a!=0)||(b!=0));
	getch();
	return 0;
}
