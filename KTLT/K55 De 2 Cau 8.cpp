#include <stdio.h>
void factorial(int n){
	int fact=1;
	do{
		if(n==0) break;
		fact*=n;
	}while(n--);
	printf("KQ:  %d",fact);
}
int main(){
	factorial(5);
	return 0;
}
