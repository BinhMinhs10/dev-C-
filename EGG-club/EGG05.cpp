#include <stdio.h>
#include <conio.h>
main()
{
	int n,i,a[100];
	FILE *solonnhat;
	printf("nhap so phan tu cua day: "); scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("phan tu thu %d la: ",i+1);
		scanf("%d",&a[i]);
	}
	//so lon nhat
	int max=a[0];
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		max=a[i];
	}
	solonnhat=fopen("solonnhat.txt","w");
	fprintf(solonnhat,"phan tu lon nhat cua day: %d",max);
	fclose(solonnhat);
	getch();
}
