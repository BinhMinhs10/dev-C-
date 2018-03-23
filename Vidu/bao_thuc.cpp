#include <stdio.h>
#include <conio.h>
void bao_thuc(int *pa)
{
	int i;
	for(int i=0;i<10;i++)
	{
		putch(7);
	}
	scanf("%d",pa+2);
	printf("\n%d",pa[2]);
}
int main()
{
	char *mes;
	mes="minh";
	puts(mes);
	int n;
	bao_thuc(&n);
	float a[2][3],s;
	int i,j;
	for(i=0;i<2;i++)
	for(j=0;j<3;j++)
	{
		scanf("%f",&a[i][j]);
	}
	for(i=0;i<2;i++)
	for(j=0;j<3;j++)
	{
		printf("\t%f",a[i][j]);
	}
}
