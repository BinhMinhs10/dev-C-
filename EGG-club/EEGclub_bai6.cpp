#include <conio.h>
#include <stdio.h>
#include <math.h>
main()
{
	int a,b;
	FILE *f;
	f=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\BAITAP.INP","r");
	if(f==NULL) perror("khong mo duoc file");
	else{
		fscanf(f,"%d",&a);
		fscanf(f,"%d",&b);
	}
	int n,m,mang1[6],mang2[6];
	for(int i=0;i<6;i++)
	{
		if(a<pow(10,i+1)) 
		{
		   n=i+1;
		   break;
	    }
	}
	for(int i=0;i<6;i++)
	{
		if(b<pow(10,i+1)) 
		{
		   m=i+1;
		   break;
	    }
	}
	printf("\nso A=%u co %d chu so",a,n);
	printf("\nso B=%u co %d chu so",b,m);
	mang1[0]=a/pow(10,n-1);
	for(int i=1;i<n;i++)
	{
		int c=pow(10,n-i);// cho nay phai gan vi phep lay du khong thuc hien tren int va double
		mang1[i]=((a%c)/pow(10,n-i-1));
		a=a%c;
	}
	mang2[0]=b/pow(10,m-1);
	for(int i=1;i<m;i++)
	{
		int d=pow(10,m-i);
		mang2[i]=((b%d)/pow(10,m-i-1));
		b=b%d;
	}
	printf("\n");
	for(int i=0;i<n;i++)
	{
		printf("%d",mang1[i]);
	}
	printf("\n");
	for(int i=0;i<m;i++)
	{
		printf("%d",mang2[i]);
	}
	
}
