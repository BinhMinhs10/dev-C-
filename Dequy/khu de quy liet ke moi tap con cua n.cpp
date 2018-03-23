#include <stdio.h>
#include <conio.h>
int n;
void norecursion(int n)
{
	
}
int main()
{
	do{
		printf("nhap so phan tu day (n>=1): n= "); scanf("%d",&n);
	}while(n<1);
    norecursion(int n);	
	return 0;
}
