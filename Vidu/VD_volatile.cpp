#include <stdio.h>
#include <conio.h>
int check();
int main()
{
	int dem=3;
	int iobuff=4;
	while(dem--){
		printf("\n-----%d",check());
		iobuff--;
	}
	return 0;
}
int check(){
	volatile int iobuff;
	int val=2;
	while(iobuff==0){
		
	}
	val=iobuff;
	iobuff=0;
	return val;
}
