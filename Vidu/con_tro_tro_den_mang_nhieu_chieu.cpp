#include <stdio.h>
#include <conio.h>
main()
{
	float a[50][50];
	int m,n,i,j;
	printf("\n Vao m va n: ");
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	{
		printf("\n a[%d][%d]= ",i,j);
		scanf("%f",(float*)a+i*50+j);
	}
	for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
	{
		printf("\n a[%d][%d]= %f",i,j,a[i][j]);
	}
}
