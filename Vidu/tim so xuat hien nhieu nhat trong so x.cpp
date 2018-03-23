#include <stdio.h>
#include <conio.h>
#include <math.h>
int main()
{
	int n,x,mang[50],dem[50];
	printf("nhap so nguyen duong n: "); scanf("%d",&n);
	tt :printf("\n nhap so X: "); scanf("%d",&x);
	if((x>pow(10,n))||(x<pow(10,n-1)))
	{
		goto tt;
	}
	else{
	
	
	   for(int i=0;i<n;i++)
	   {
		mang[n-i]=x%10;
		x=x/10;
	   }
	    for(int i=1;i<=n;i++)
	   {
		printf("%3d",mang[i]);
	   }
	
	    for(int j=0;j<=9;j++)
	    {
		    dem[j]=0;
	    }
	    for(int i=1;i<=n;i++)
	    {
			
		
		        for(int j=0;j<=9;j++)
		    {
				if(mang[i]==j)
			   {
				   dem[j]=dem[j]+1;
			   }
			
		    }
	    }
	    int max=0,flag;
	     for(int i=0;i<=9;i++)
	     {
		       if(max<dem[i])
		      {
			      max=dem[i];
			       flag=i;
		      }
	     }
	printf("\nso suat hien %d lan trong day X la nhieu nhat. Vi du: %d",max,flag);
	return 0;
    }
}
