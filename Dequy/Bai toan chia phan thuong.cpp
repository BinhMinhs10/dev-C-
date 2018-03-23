#include <stdio.h>
#include <conio.h>
int m,n;
int PART(int m,int n);
int main()
{
	printf("\n nhap so keo: "); scanf("%d",&m);
	printf("\n nhap so hoc sinh: "); scanf("%d",&n);
	printf("\n so kha nang chia %d keo cho %d em be la: %d",m,n,PART(m,n));
	return 0;
}
int PART(int m,int n)
{
	if((m==0)||(n==0)) return 1;
	else if(m<n) return PART(m,m);
	return PART(m,n-1)+PART(m-n,n); 
}
