#include <stdio.h>
#include <conio.h>
int main()
{
	int a[100][2],b[100][2],c[100][2],d[100][2];
	int n,thang=0,thua=0;
	printf("nhap so nguoi trong 1 team: "); scanf("%d",&n);
	printf("\nkha nang dau cua team ATM: ");
	for(int i=0;i<n;i++)
	{
		printf("\na[%d]= ",i+1);
		fflush(stdin);
		scanf("%d",&a[i][1]);
		c[i][1]=a[i][1];
		a[i][0]=i+1;
		c[i][0]=i+1;
	}
	printf("\nkha nang dau cua team doi thu: ");
	for(int i=0;i<n;i++)
	{
		printf("\nb[%d]= ",i+1);
		fflush(stdin);
		scanf("%d",&b[i][1]);
		d[i][1]=b[i][1];
		b[i][0]=i+1;
		d[i][0]=i+1;
	}
	//sap xep++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	fflush(stdin);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i][1]>a[j][1])
			{
				int temp;
				temp=a[i][1];
				a[i][1]=a[j][1];
				a[j][1]=temp;
			}
			if(b[i][1]>b[j][1])
			{
				int temp;
				temp=b[i][1];
				b[i][1]=b[j][1];
				b[j][1]=temp;
			}
		}
	}
	//in ra 
	printf("\nsap xep team: ");
	int i=n-1 , j = 0, k = n-1,h=0;
	for (i = n-1; i >= 0; i--)
	{
		//int i , j = 0, k = n-1,h=0;
		if (a[k][1] > b[i][1])
		{
			for(h=0;h<n;h++)
			{
				if(a[k][1]==c[h][1])
				{
					printf("\n%d",c[h][0]);
				    break;
				}
			}
			for(h=0;h<n;h++)
			{
				if(b[i][1]==d[h][1])
				{
					printf("--%d\n",d[h][0]);
				    break;
				}
				
			}
			k--;
			thang++;
		}
		else 
		{
		  if (j <= i)
			{
				for(h=0;h<n;h++)
			   {
				if(a[j][1]==c[h][1])
				{
				    printf("\n%d",c[h][0]);
				    break;	
				}
				
			   }
			   for(h=0;h<n;h++)
			   {
			   	if(b[i][1]==d[h][1])
			   	{
				    printf("--%d\n",d[h][0]);
				    break;
			    }
			   }
			 	//cout << a[j].d<<"--" << b[i].d<<endl;
				j++;
				thua++;
			}
		}
		
    }
    if(thang>thua)
    {
    	printf("\n-----------------team ATM danh chien thang----------------------------");
    }
    else
    {
    	
    	printf("\n\a-----------------team ATM bi thua hoac hoa----------------------------");
    }
	
	getch();
	return 1;
}
