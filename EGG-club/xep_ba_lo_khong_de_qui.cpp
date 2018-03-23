#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main()
{
	int a[100],b[100],n,m,j,t,s=0;
	printf("nhap khoi luong toi da ba lo: "); scanf("%d",&m);
	printf("\nnhap so luong: "); scanf("%d",&n);
	printf("nhap khoi luong va gia tri: \n");
	for(int i=0;i<n;i++)
	{
		printf("\na[%d]= ",i+1); scanf("%d",&a[i]);
		printf("\nb[%d]= ",i+1); scanf("%d",&b[i]);
	}
	int k,temp,flag;
	for(int i=1;i<n;i++)
	{
		temp=b[i];
		flag=a[i];
		k=i-1;
		while((k>=0)&&(b[k]>temp))
		{
			b[k+1]=b[k];
			a[k+1]=a[k];
			k--;
		}
		a[k+1]=flag;
		b[k+1]=temp;
	}
	for(int i=n;i>0;i--)
	{
		s+=a[i]; t=t+a[i]*b[i];
		if(s>m)
		{
			t=t-(s-m)*b[i];
			j=i+1;
			break;
		}
	}
	printf("\nnhung hang can lay: ");
	
	for(int i=n-1;i>=j;i--)
	{
		if(i==j)
		{
			printf("\n%d",s-m); printf("\t%d",b[i]);
		}
		else
		{
			printf("\n%d",a[i]); printf("\t%d",b[i]);
		}
	}
	getch();
}
