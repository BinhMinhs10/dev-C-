#include <stdio.h>
int main(){
	int a=9;
	int *p=&a;
	a++;
	printf("\na=%d,*p=%d",a,*p);
	return 0;
}
