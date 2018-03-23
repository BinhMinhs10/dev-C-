#include <stdio.h>
#include <conio.h>
main()
// chuyen tu he co so 10 sang co so 2
{
	int n,i=0,h2[99];
	printf("nhap so nguyen n (trong he co so 10):"); scanf("%d",&n);
	printf("\n n trong he co so 2: ");
	if(n<0) {  printf("-"); n=-n;
	}
	do{
		h2[i]=n%2;
		n=n/2;
		i++;
	}while(n!=0);
	for(i--;i>=0;i--)
	printf("%d",h2[i]);
	getch();
	return 0;
}
