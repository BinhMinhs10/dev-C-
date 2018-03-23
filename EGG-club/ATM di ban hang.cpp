#include <stdio.h>
#include <conio.h>
int luong_mua(FILE *fp,int i,int j,int tong[])
{
	int s=0,k;
	for(k=i;k<=j;k++)
	{
		s=s+tong[k];
	}
	return s;
}
void chuoi_ngay(FILE *fp,int n,int tong[])
{
	int start=0;
	for(int i=0;i<n;i++)
	{
		if((tong[i]==0)&&(start=0))
		{
			fprintf(fp,"%d -",i); 
			start = -1;
			for(int j=i;j<n;j++)
			{
				if((tong[j]==0)&&(start!=0))
				{
				
				  fprintf(fp," %d\n",j);
				  start=0;
			    }
				
			}
		}
	}
	
}
int main()
{
     int n,a[31],i,ngayi,ngayj,dem,item,max_ngay;
     int ngay[100],tong[100]={};
	FILE *fpinput=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\input.txt","r");
	FILE *fpoutput=fopen("C:\\Users\\ThuyLinh Computer\\Documents\\dev-C++\\output.txt","w");
	if(fpinput==NULL) perror("khong mo duoc tep");
	
	else if(fpoutput==NULL) perror("khong mo duoc tep");
	
	else
	{
		fscanf(fpinput,"%d",&n);
		fscanf(fpinput,"%d %d",&ngayi,&ngayj);
		for(dem=0;dem<n;dem++)
		{
			fscanf(fpinput,"%d %d",&ngay[dem],&item);
			tong[ngay[dem]]+=item;
		}
		//in len output.txt, phan 1+++++++++++++++++++++++++++++++++++++++
		max_ngay=ngay[dem-1];
		fputs("Phan 1\n",fpoutput);
	   for(int i=1;i<=n;i++)
	   {
		   fprintf(fpoutput,"%d - %d\n",i,tong[i]);
	   }
	 //phan 2++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	    fputs("Phan 2\n",fpoutput);
	    int max=tong[0],temp;
	   for(int i=1;i<=max_ngay;i++)
	  {
		if(max<tong[i])
		{
			max=tong[i];
			temp=i;
		}
	  }
	  fprintf(fpoutput,"%d - %d\n",temp,max);
	  for(int i=1;i<=max_ngay;i++)
	   {
		if(tong[i]==0)
		fprintf(fpoutput,"%d - %d\n",i,tong[i]);
	   }
	   //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	   
	   fprintf(fpoutput,"Phan 3\n");
		fprintf(fpoutput,"%d\n",luong_mua(fpoutput, ngayi, ngayj, tong));
		//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		
		fprintf(fpoutput,"Phan 4\n");
		chuoi_ngay(fpoutput, max_ngay,tong);
		
	}
	
	fclose(fpoutput);
	fclose(fpinput);
}
