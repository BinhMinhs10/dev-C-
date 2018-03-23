#include <stdio.h>
int f(int x,int y){
	printf("\n%d",y);
	return x+y;
}
int main(){
	int x=9;
	int temp = f(x,x++);
	printf("f=%d",temp);
	return 0;
}
