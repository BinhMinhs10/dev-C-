#include <stdio.h>
#include <conio.h>
long F(long x){
	if (x==0||x==1) return x;
	else 
	 return F(x-1)+F(x-2);
}
//#define printf(x) printf("\n gia tri cua ham Fibonaci(%d) la: %d",n,F(n))
int main()
#define printf(x) printf("\n gia tri cua ham Fibonaci(%d) la: %d",n,F(n))
{
	long n;
	printf("nhap gia tri n: ");
	scanf(" %ld",&n);
	printf(x);
	getch();
	return 0;
}
