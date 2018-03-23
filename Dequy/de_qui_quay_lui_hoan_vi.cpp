#include <conio.h>
#include <stdio.h>
#define max  100
int x[max];
int n;
bool kt[max];
void TRY(int j)
{
	int i,k;
	for(int i=0;i<n;i++)
	{
		if(kt[i]==true)
		{
			kt[i]=false;
			x[j]=i;
		
		 if(j==n)
		 {
			for(k=1;k<n;k++)
			printf("x[%d]=%d",k,x[k]);
		 }
		 else TRY(j+1);
		 kt[i]=true;
	    }
	}
}
main()
{
	int n;
     printf("nhap so n:");
	  scanf("%d",&n);
	 for(int i=0;i<n;i++)
	 {
	    kt[i]=true;
	 }
	printf("cac hoan vi la:");
	TRY(0);
	getch();	
}
