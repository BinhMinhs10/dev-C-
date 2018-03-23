#include <stdio.h>
#include <conio.h>
#include <math.h>

typedef struct array{
	int count;
	float max[1000];
} Array;

Array makeArray()
{
	int n;
	printf("\nNhap so phan tu cua mang muon khoi tao:"); scanf("%d",&n);
	Array a;
	a.count=n;
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nmax[%d]=",i);
		scanf("%f",&a.max[i]);
	}
	return a;
}
int main()
{
	makeArray;
	getch();
}
