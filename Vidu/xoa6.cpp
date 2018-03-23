#include <stdio.h>
int main(){
	int a=9,b=0;
	int A[]={2,3,6,8};
	int *p=&a,*q=&b;
	*p++=*q++;
	printf("\na=%d,*p=%d,b=%d,*q=%d",a,*p,b,*q);
	return 0;
}
