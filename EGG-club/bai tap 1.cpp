#include <conio.h>
#include <stdio.h>
#define max 100 
int n,k,array[max],sum[max];
int main()
{
	FILE *fp;
	if((fp=fopen("baitap1","r"))==NULL)
	{
		printf("khong mo duoc file\n");
	}
	else
	{
		int lonnhat=-1000;
		fscanf(fp,"%d",&n);
		fscanf(fp,"%d",&k);
		for(int i=0;i<n;i++)
		{
			fscanf(fp,"%d",&array[i]);
		}
		sum[0]=array[0];
		printf("\n sinh mang : %3d",array[0]);
		for(int i=1;i<n;i++)
		{
			sum[i]=sum[i-1]+array[i];
			printf("%3d",sum[i]);
		}
		int minsum=0,maxai, maxarray=array[0];
		for(int i=1;i<=n;i++)
		{
			maxai=sum[i-1]-minsum;//theo nhu anh cuong noi cho nay khong rong thi no khong co so am 
			                      //    chu co la sai ngay
			if(maxarray<maxai)
			{
				maxarray=maxai;
			}
			if(sum[i-1]<minsum)
			{
				minsum=sum[i-1];
			}
		}
		printf("\ntrong long lon nhat cua day %d so la: %d",n,maxarray);
		//printf("tong lon nhat day %d phan tu tu day da cho la: %d",k,lonnhat);
	}
	fclose(fp);
	return 0;
}
