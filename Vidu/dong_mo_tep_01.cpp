#include <stdio.h>
#include <conio.h>
main()
{
	int a,b,max,min;
	FILE *fp;
	printf("nhap 2 so nguyen a, b: ");
	scanf("%d %d",&a,&b);
	max=a>b?a:b;
	min=a<b?a:b;
	printf("so lon: %d",max);
	fp=fopen("/This PC/cu/sonhoson.txt","wt");
	fprintf(fp,"day la so nho nhat: %d",min);
	fclose(fp);
	//
    fp=fopen("/This PC/cu/sonhoson.txt","r");
   fclose(fp);
}
