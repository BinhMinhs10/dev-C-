#include <stdio.h>
#include <conio.h>
int k2,k3,k5,k6;
void readdata(char *name)
{
	FILE *f;
	f=fopen(name,"r");
	if(f==NULL)
	{
		printf("\nkhong mo duoc file");
	}
	else
	{
		fscanf(f,"%d",&k2);
		fscanf(f,"%d",&k3);
		fscanf(f,"%d",&k5);
		fscanf(f,"%d",&k6);
	}
}
int main()
{
	readdata("input");
	int sum=0;
	while((k2!=0)&&(k5!=0)&&(k6!=0))
	{
		k2--;
		k5--;
		k6--;
		sum+=256;
	}
	while((k3!=0)&&(k2!=0))
	{
		k3--;
		k2--;
		sum+=32;
	}
	printf("\n tong cac so lon nhat co the la: %d",sum);
}
