#include <stdio.h>
void change(int &a,int &b){
	a^=b;
	b^=a;
	a^=b;
}
int main(){
	int a=12,b=6;
	change(a,b);
	printf("a=%d, b=%d",a,b);
	return 0;
}
