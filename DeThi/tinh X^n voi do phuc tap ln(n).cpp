#include <stdio.h>
int X(int a,int n){
	if(n==1) return a;
	if(n==0) return 1;
	int temp = X(a,n/2);
	if(n%2 == 0){
		return temp*temp;
	}
	else{
		return temp*temp*a;
	}
	
}
int main(){
	printf("X = %d",X(2,5));
	return 0;
}
