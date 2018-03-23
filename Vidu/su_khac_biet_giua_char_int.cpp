#include <stdio.h>
#include <conio.h>
main()
{
	int a; float x; char ch; char* str;
	printf("Nhap vao 1 so nguyen:"); scanf("%d",&a);
	printf("\nnhap vao 1 so thuc:"); scanf("%f",&x);
	printf("\nnhap vao 1 ki tu:");
	fflush(stdin);
	scanf("%c",&ch);
	puts("Nhap vao mot xau ki tu:");
	fflush(stdin);
	gets(str);
	printf("\n1 so nguyen:%d",a);
	printf("\n1 so thuc:%f",x);
	printf("\n1 ki tu:%c",ch);
	printf("\nxau ki tu:%s",str);
	
	
}
	

