#include <stdio.h>
#include <conio.h>
main()
{
	
	int maxsum=0,n,a[100];
	printf("nhap so phan tu cua day: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	   printf("\n phan tu thu %d  : ",i+1);
	   scanf("%d",&a[i]);
    }
	for (int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++)
		{
			int sum=0;
			for(int k=i;k<=j;k++)
			sum += a[k];
			if (sum > maxsum )
			maxsum = sum;
		}
	}
	printf("\ntrong luong lo nhat cua day : %d",maxsum);
	getch();
}
