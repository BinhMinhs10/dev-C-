#include <stdio.h>
#include <conio.h>
main()
{
	int a,b,max,min;
	FILE *sosanh;
	printf("nhap 2 lan luot 2 so a,b: ");
	scanf("%d %d",&a,&b);
	max=a>b?a:b;
	printf("so lon nhat la: %d",max);
	min=a<b?a:b;
	sosanh=fopen("D:\\sonhoson.txt","w");
	fprintf(sosanh,"so be nhat: %d",min);
	fclose(sosanh);
}
