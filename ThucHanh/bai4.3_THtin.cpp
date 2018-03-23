# include <stdio.h>
# include <conio.h>
main()
{
	int i,F,n;
	printf("nhap so nguyen n\n");
	scanf("%d",&n);
	F=1;
	{
	
	if((n>=0)&&(n<8))
	 
	
		{
		 
		 for(i=1;i<=n;i++)
		 {
		 F=F*i;
	     }
	     
	     printf("giai thua cua %d =%d",n,F);
        }
    }
	getch();
	
}
