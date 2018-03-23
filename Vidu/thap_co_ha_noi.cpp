#include <stdio.h>
using namespace std;
void hoandoi(int n,int c1,int c2,int c3)
{
	
	if(n==1){
	
	 printf(" %d -> %d\n",c1,c3);
    }
	else {
		hoandoi(n-1,c1,c3,c2);
		hoandoi(1,c1,c2,c3);
		hoandoi(n-1,c2,c1,c3);
	}
}
main()
{
	int n;
	printf("nhap N: "); scanf("%d",&n);
	
	hoandoi(n,1,2,3);
	
}
