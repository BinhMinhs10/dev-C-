#include <stdio.h>
#include <conio.h>
main()
{
	int m[100];
	int n;
	int i,k,j;
	fflush(stdin);
	printf("cho biet so phan tu trong mang: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int temp;
		printf("\n cho biet gia tri cua m[%d] ",i);
		scanf("%d",&temp);
		m[i]=temp;
		
	}
	printf("\nmang truoc khi sap xep:");
	for(i=0;i<n;i++)
	{
	
	 
		printf("%3d",m[i]);
	
	  for(j=i+1;j<n-1;j++)
	 {
		if(m[i]>m[j])
		{
			int temp;
			temp=m[j];
			m[j]=m[i];
			m[i]=temp;
	 		
		}
	 }
	 
    }
    printf("\nmang sau khi sap xep");
	 for(k=0;k<n;k++)
	    printf("%3d",m[k]);
    getch();
}
