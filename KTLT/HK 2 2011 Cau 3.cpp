#include <stdio.h>
#include <math.h>
int sum=0;
int TongChuSoLe(int n){
	if(n==0){
		return 0;
	}
	if(( (n%10) % 2)==1|| ( n%10 )%2 == -1){
		sum+=fabs(n%10);
	}
	TongChuSoLe(n/10);
	return sum;
}
int TongChuSoLeNonRecursion(int n){
	while(n!=0){
		if(( n%10 )%2 == 1 || ( n%10 )%2 == -1){
			sum+=fabs(n%10);
		}
		n=n/10;
	}
	return sum;
}
int main(){
	int x;
	printf("\nnhap so : "); scanf("%d",&x);
	printf("\ntong so le: %d",TongChuSoLeNonRecursion(x));
	return 0;
}
