#include <stdio.h>
#include <conio.h>
main()
{
	
	int n,a[100];
	printf("nhap so phan tu cua day: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	   printf("\n phan tu thu %d  : ",i+1);
	   scanf("%d",&a[i]);
    }
    int maxsum= a[0];
    for(int i=0;i<n;i++)
	{
	  int sum=0;	
    
     for (int j=i;j<n;j++)
       {
        sum=sum+a[j];
        if(sum>maxsum)
	    maxsum=sum;}
    }
    printf(" trong luong lon nhat la : %d",maxsum);
    getch();
}
