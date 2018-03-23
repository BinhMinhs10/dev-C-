#include <stdio.h>
#include <conio.h>
int giaithua(signed int n)
{
	if(n==0) return 1;
	else{
	int i=1,x=1;
	while(i<=n)
	{
		x=i*x;
		i++;
	}
	return x;
    }
}
main(){
	signed int n;
	printf("nhap n: "); scanf("%d",&n);
	printf("giai thua %d la %d",n,giaithua(n));
	getch();
}
