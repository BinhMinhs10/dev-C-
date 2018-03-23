#include <stdio.h>
void tong_h(float a[][50],int m,int n,float *th);
main()
{
	float b[30][50];
	float h[30];
	float x; int i,j,m,n;
	printf("nhap m va n: "); scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
	for(int j=1;j<=n;++j)
	{
		printf("\n b[%d][%d]= ",i,j);
		scanf("%f",&x); b[i][j]=x;
	}
	tong_h(b,m,n,h);
	for(int i=1;i<=m;++i)
	{
		printf("\n rong hang %d la %0.2f ",i,h[i]);
	}
}
void tong_h(float a[][50],int m,int n,float *th)
{
	int i,j;
	for(int i=1;i<=m;++i)
	{
		th[i]=0;
		for(int j=1;j<=n;++j)
		th[i]+=a[i][j];
	}
}
