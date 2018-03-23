#include <conio.h>
#include <stdio.h>
main()
{
	int m[100],n,i,j,k;
    
	printf("cho biet so phan tu trong mang:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int temp;
		printf("\n nhap phan tu m[%d]: ",i+1);
		scanf("%d",&temp);
		m[i]= temp;
	}	
	printf("\n mang truoc khi sap xep: ");
	for(i=0;i<n;i++)
	printf("%3d",m[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(m[i]<m[j])
			{ int temp;
			  temp=m[i]; 
			  m[i]=m[j];
			  m[j]=temp;
			}
			
		}
		printf("\n mang sau khi sap xep thu %d",i+1);
			for(k=0;k<n;k++)
			printf("%3d",m[k]);
	}
	getch();
	
}

